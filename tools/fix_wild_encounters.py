#!/usr/bin/env python3
"""
Fix wild encounter slots where the species is at a level too low to have evolved yet.

Rules (user-confirmed):
  - Level evo, min_level >= evo_level  → valid, no change
  - Level evo, partial violation        → restrict min_level to evo_level
  - Level evo, full violation           → recurse on pre-evo
  - Non-level evo (item/friendship/…)   → always recurse on pre-evo

Usage:
  python3 tools/fix_wild_encounters.py [--dry-run]
"""

import json
import re
import sys

EVOLUTION_H  = "src/data/pokemon/evolution.h"
ENCOUNTERS_J = "src/data/wild_encounters.json"

LEVEL_EVO_TYPES = {
    "EVO_LEVEL",
    "EVO_LEVEL_ATK_LT_DEF",
    "EVO_LEVEL_ATK_GT_DEF",
    "EVO_LEVEL_ATK_EQ_DEF",
    "EVO_LEVEL_SILCOON",
    "EVO_LEVEL_CASCOON",
    "EVO_LEVEL_NINJASK",
    "EVO_LEVEL_SHEDINJA",
}


def parse_evolution_table(path):
    """
    Returns evolved_from[TARGET] = (SOURCE, EVO_TYPE, evo_level_int)
    where TARGET and SOURCE are bare species names (no SPECIES_ prefix).
    Only the first entry per target is stored (each species has exactly one source).
    """
    with open(path) as f:
        content = f.read()

    evolved_from = {}

    # Split on [SPECIES_X] = to get alternating (name, body) pairs
    parts = re.split(r'\[SPECIES_(\w+)\]\s*=\s*', content)
    # parts = [preamble, name0, body0, name1, body1, ...]

    evo_entry = re.compile(r'\{(EVO_\w+),\s+(\w+),\s+SPECIES_(\w+)\}')

    for i in range(1, len(parts), 2):
        source = parts[i]
        body   = parts[i + 1] if i + 1 < len(parts) else ""

        for m in evo_entry.finditer(body):
            evo_type = m.group(1)
            param    = m.group(2)
            target   = m.group(3)
            level    = int(param) if param.isdigit() else 0

            if target not in evolved_from:
                evolved_from[target] = (source, evo_type, level)

    return evolved_from


def get_replacement(species, min_level, max_level, evolved_from):
    """
    Recursively find the correct species and level range for an encounter slot.
    Returns (new_species, new_min_level, new_max_level).
    """
    if species not in evolved_from:
        return (species, min_level, max_level)  # base form: always valid

    pre_evo, evo_type, evo_level = evolved_from[species]

    if evo_type in LEVEL_EVO_TYPES:
        if min_level >= evo_level:
            return (species, min_level, max_level)          # valid
        elif max_level < evo_level:
            # Full violation: replace with pre-evo
            return get_replacement(pre_evo, min_level, max_level, evolved_from)
        else:
            # Partial violation: restrict min_level
            return (species, evo_level, max_level)
    else:
        # Item / friendship / beauty / trade: always replace
        return get_replacement(pre_evo, min_level, max_level, evolved_from)


def fix_encounters(dry_run):
    evolved_from = parse_evolution_table(EVOLUTION_H)
    print(f"Parsed {len(evolved_from)} evolution entries.")

    with open(ENCOUNTERS_J) as f:
        data = json.load(f)

    changes = 0

    for group in data.get("wild_encounter_groups", []):
        for enc in group.get("encounters", []):
            map_name = enc.get("map", "?")
            for field in ("land_mons", "water_mons", "rock_smash_mons", "fishing_mons"):
                if field not in enc:
                    continue
                for mon in enc[field].get("mons", []):
                    raw = mon["species"]
                    if not raw.startswith("SPECIES_"):
                        continue
                    bare = raw[len("SPECIES_"):]

                    new_bare, new_min, new_max = get_replacement(
                        bare, mon["min_level"], mon["max_level"], evolved_from
                    )
                    new_species = f"SPECIES_{new_bare}"

                    if new_species != raw or new_min != mon["min_level"] or new_max != mon["max_level"]:
                        print(
                            f"  {map_name} [{field}]: "
                            f"{raw} {mon['min_level']}-{mon['max_level']} "
                            f"→ {new_species} {new_min}-{new_max}"
                        )
                        changes += 1
                        if not dry_run:
                            mon["species"]    = new_species
                            mon["min_level"]  = new_min
                            mon["max_level"]  = new_max

    if dry_run:
        print(f"\n[DRY RUN] {changes} slots would be changed. Run without --dry-run to apply.")
    else:
        with open(ENCOUNTERS_J, "w") as f:
            json.dump(data, f, indent="\t")
            f.write("\n")
        print(f"\nApplied {changes} changes to {ENCOUNTERS_J}.")


if __name__ == "__main__":
    dry_run = "--dry-run" in sys.argv
    fix_encounters(dry_run)
