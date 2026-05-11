#!/usr/bin/env python3
"""
Merge Gen-3-valid DPE learnset moves into FR learnset arrays.

For each species: read the CURRENT FR learnset, read the DPE learnset,
filter DPE to FR-valid move names, then merge:
  - Keep all existing FR moves (never remove).
  - Add DPE moves not already present at any level.
  - For moves that exist in both at different levels: consult DECISIONS below.

Usage:
  python3 tools/extract_dpe_learnsets.py [--dry-run]

  --dry-run  Print all conflicts and additions without modifying any file.

Workflow:
  1. Run with --dry-run to see all conflicts.
  2. Fill in DECISIONS dict below (keyed by "Species:MOVE_NAME").
  3. Run without --dry-run to apply.

Rotom forms have no separate DPE learnsets → use base Rotom.
Galarian Mr. Mime has no DPE learnset → use base MrMime.
"""

import re
import sys

# ── Conflict resolution decisions ──────────────────────────────────────────
# Key format: "SpeciesName:MOVE_CONSTANT"  (e.g. "Shinx:MOVE_SPARK")
# Values: "F" = keep FR level, "D" = use DPE level, "B" = keep both
# Unresolved conflicts default to "F" (keep FR level).
DECISIONS: dict[str, str] = {
    # Rule: D when DPE level < FR level (DPE is earlier); F otherwise (default).

    # Shinx
    "Shinx:MOVE_SPARK":                     "D",   # FR=17, DPE=13

    # Axew
    "Axew:MOVE_LEER":                        "D",   # FR=5,  DPE=4

    # Honedge
    "Honedge:MOVE_METAL_SOUND":              "D",   # FR=9,  DPE=8

    # GalarianZigzagoon
    "GalarianZigzagoon:MOVE_LEER":           "D",   # FR=13, DPE=1
    "GalarianZigzagoon:MOVE_SAND_ATTACK":    "D",   # FR=9,  DPE=3

    # Toxel
    "Toxel:MOVE_FLAIL":                      "D",   # FR=4,  DPE=1

    # Dreepy
    "Dreepy:MOVE_BITE":                      "D",   # FR=12, DPE=1
    "Dreepy:MOVE_QUICK_ATTACK":              "D",   # FR=6,  DPE=1

    # GalarianLinoone
    "GalarianLinoone:MOVE_PIN_MISSILE":      "D",   # FR=9,  DPE=1
    "GalarianLinoone:MOVE_SAND_ATTACK":      "D",   # FR=5,  DPE=3
    "GalarianLinoone:MOVE_HEADBUTT":         "D",   # FR=13, DPE=12

    # GalarianMrMime (all DPE levels are earlier)
    "GalarianMrMime:MOVE_MEDITATE":          "D",   # FR=20, DPE=8
    "GalarianMrMime:MOVE_DOUBLE_SLAP":       "D",   # FR=16, DPE=11
    "GalarianMrMime:MOVE_ENCORE":            "D",   # FR=24, DPE=18
    "GalarianMrMime:MOVE_REFLECT":           "D",   # FR=36, DPE=22
    "GalarianMrMime:MOVE_PSYBEAM":           "D",   # FR=32, DPE=25
    "GalarianMrMime:MOVE_PSYCHIC":           "D",   # FR=44, DPE=39

    # HisuianZorua
    "HisuianZorua:MOVE_TORMENT":             "D",   # FR=29, DPE=3
    "HisuianZorua:MOVE_FURY_SWIPES":         "D",   # FR=13, DPE=12
    "HisuianZorua:MOVE_SCARY_FACE":          "D",   # FR=21, DPE=18
    "HisuianZorua:MOVE_TAUNT":               "D",   # FR=25, DPE=20

    # HisuianZoroark
    "HisuianZoroark:MOVE_TORMENT":           "D",   # FR=29, DPE=1
    "HisuianZoroark:MOVE_FURY_SWIPES":       "D",   # FR=17, DPE=12
    "HisuianZoroark:MOVE_SCARY_FACE":        "D",   # FR=21, DPE=18
    "HisuianZoroark:MOVE_TAUNT":             "D",   # FR=25, DPE=20

    # HisuianGrowlithe
    "HisuianGrowlithe:MOVE_EMBER":           "D",   # FR=5,  DPE=1
    "HisuianGrowlithe:MOVE_LEER":            "D",   # FR=9,  DPE=1
    "HisuianGrowlithe:MOVE_BITE":            "D",   # FR=13, DPE=7
    "HisuianGrowlithe:MOVE_FLAME_WHEEL":     "D",   # FR=33, DPE=12

    # HisuianArcanine (DPE has level-0 and level-1 entries, both earlier than FR=34)
    "HisuianArcanine:MOVE_EXTREME_SPEED":    "D",   # FR=34, DPE=0/1

    # GalarianMeowth (newly mapped from MeowthG)
    "GalarianMeowth:MOVE_FAKE_OUT":          "D",   # FR=8,  DPE=1
    "GalarianMeowth:MOVE_METAL_CLAW":        "D",   # FR=20, DPE=16
    "GalarianMeowth:MOVE_SWAGGER":           "D",   # FR=35, DPE=24
    "GalarianMeowth:MOVE_SLASH":             "D",   # FR=40, DPE=36

    # GalarianFarfetchd (newly mapped from FarfetchdG)
    "GalarianFarfetchd:MOVE_PECK":           "D",   # FR=17, DPE=1
    "GalarianFarfetchd:MOVE_DETECT":         "D",   # FR=41, DPE=25

    # GalarianDarumaka (newly mapped from DarumakaG)
    "GalarianDarumaka:MOVE_POWDER_SNOW":     "D",   # FR=5,  DPE=1

    # AlolanMeowth (newly mapped from MeowthA)
    "AlolanMeowth:MOVE_BITE":                "D",   # FR=8,  DPE=6

    # AlolanDiglett (newly mapped from DiglettA)
    "AlolanDiglett:MOVE_SAND_ATTACK":        "D",   # FR=4,  DPE=1
    "AlolanDiglett:MOVE_METAL_CLAW":         "D",   # FR=24, DPE=1
    "AlolanDiglett:MOVE_MUD_SLAP":           "D",   # FR=14, DPE=10
    "AlolanDiglett:MOVE_MAGNITUDE":          "D",   # FR=19, DPE=14
    "AlolanDiglett:MOVE_DIG":               "D",   # FR=39, DPE=31
    "AlolanDiglett:MOVE_EARTHQUAKE":         "D",   # FR=44, DPE=39

    # AlolanDugtrio (newly mapped from DugtrioA)
    "AlolanDugtrio:MOVE_FISSURE":            "D",   # FR=57, DPE=53

    # AlolanGeodude (newly mapped from GeodudeA)
    "AlolanGeodude:MOVE_SPARK":              "D",   # FR=17, DPE=12
    "AlolanGeodude:MOVE_SELF_DESTRUCT":      "D",   # FR=38, DPE=24
    "AlolanGeodude:MOVE_EXPLOSION":          "D",   # FR=55, DPE=36

    # AlolanGraveler (newly mapped from GravelerA)
    "AlolanGraveler:MOVE_SPARK":             "D",   # FR=17, DPE=12
    "AlolanGraveler:MOVE_SELF_DESTRUCT":     "D",   # FR=38, DPE=24
    "AlolanGraveler:MOVE_EXPLOSION":         "D",   # FR=60, DPE=44

    # AlolanVulpix (newly mapped from VulpixA)
    "AlolanVulpix:MOVE_CONFUSE_RAY":         "D",   # FR=20, DPE=12
    "AlolanVulpix:MOVE_ICY_WIND":            "D",   # FR=16, DPE=15
    "AlolanVulpix:MOVE_MIST":               "D",   # FR=24, DPE=20
    "AlolanVulpix:MOVE_BLIZZARD":            "D",   # FR=44, DPE=42

    # AlolanExeggutor (newly mapped from ExeggutorA)
    "AlolanExeggutor:MOVE_EGG_BOMB":         "D",   # FR=41, DPE=27
}

FR_MOVES_H    = "include/constants/moves.h"
DPE_LEARNSETS = "/dev/shm/dpe/src/Learnsets.c"
FR_LEARNSETS  = "src/data/pokemon/level_up_learnsets.h"

# FR array name prefix → DPE learnset species name
# Keys must match exactly: s{KEY}LevelUpLearnset in the FR file
SPECIES_TO_DPE = {
    # Previous-step species (hand-crafted learnsets, now being merged)
    "Shinx":              "Shinx",
    "Axew":               "Axew",
    "Honedge":            "Honedge",
    "GalarianZigzagoon":  "ZigzagoonG",
    # Gen 4 Sinnoh
    "Luxio":              "Luxio",
    "Luxray":             "Luxray",
    "Starly":             "Starly",
    "Staravia":           "Staravia",
    "Staraptor":          "Staraptor",
    "Munchlax":           "Munchlax",
    "Chimchar":           "Chimchar",
    "Monferno":           "Monferno",
    "Infernape":          "Infernape",
    "Piplup":             "Piplup",
    "Prinplup":           "Prinplup",
    "Empoleon":           "Empoleon",
    "Buizel":             "Buizel",
    "Floatzel":           "Floatzel",
    "Bronzor":            "Bronzor",
    "Bronzong":           "Bronzong",
    "Gible":              "Gible",
    "Gabite":             "Gabite",
    "Garchomp":           "Garchomp",
    "Riolu":              "Riolu",
    "Lucario":            "Lucario",
    "Honchkrow":          "Honchkrow",
    "Gliscor":            "Gliscor",
    # Gen 4 evolutions of earlier species
    "Roserade":           "Roserade",
    "Tangrowth":          "Tangrowth",
    "Leafeon":            "Leafeon",
    "Glaceon":            "Glaceon",
    "Mamoswine":          "Mamoswine",
    "PorygonZ":           "PorygonZ",
    "Magnezone":          "Magnezone",
    "Rhyperior":          "Rhyperior",
    "Electivire":         "Electivire",
    "Magmortar":          "Magmortar",
    "Togekiss":           "Togekiss",
    "Yanmega":            "Yanmega",
    "Gallade":            "Gallade",
    "Probopass":          "Probopass",
    "Froslass":           "Froslass",
    "Weavile":            "Weavile",
    # Gen 4 legendary / mythical
    "Rotom":              "Rotom",
    "RotomHeat":          "Rotom",
    "RotomWash":          "Rotom",
    "RotomFrost":         "Rotom",
    "RotomFan":           "Rotom",
    "RotomMow":           "Rotom",
    "Uxie":               "Uxie",
    "Mesprit":            "Mesprit",
    "Azelf":              "Azelf",
    "Dialga":             "Dialga",
    "Palkia":             "Palkia",
    "Heatran":            "Heatran",
    "Regigigas":          "Regigigas",
    "Giratina":           "Giratina",
    "Cresselia":          "Cresselia",
    "Phione":             "Phione",
    "Manaphy":            "Manaphy",
    "Darkrai":            "Darkrai",
    "Shaymin":            "Shaymin",
    "Arceus":             "Arceus",
    # Gen 5
    "Zorua":              "Zorua",
    "Zoroark":            "Zoroark",
    "Pawniard":           "Pawniard",
    "Bisharp":            "Bisharp",
    "Tynamo":             "Tynamo",
    "Eelektrik":          "Eelektrik",
    "Eelektross":         "Eelektross",
    "Litwick":            "Litwick",
    "Lampent":            "Lampent",
    "Chandelure":         "Chandelure",
    "Ferroseed":          "Ferroseed",
    "Ferrothorn":         "Ferrothorn",
    "Drilbur":            "Drilbur",
    "Excadrill":          "Excadrill",
    "Sandile":            "Sandile",
    "Krokorok":           "Krokorok",
    "Krookodile":         "Krookodile",
    "Golett":             "Golett",
    "Golurk":             "Golurk",
    "Scraggy":            "Scraggy",
    "Scrafty":            "Scrafty",
    "Deino":              "Deino",
    "Zweilous":           "Zweilous",
    "Hydreigon":          "Hydreigon",
    "Larvesta":           "Larvesta",
    "Volcarona":          "Volcarona",
    "Annihilape":         "Annihilape",
    # Gen 6
    "Fraxure":            "Fraxure",
    "Haxorus":            "Haxorus",
    "Fletchling":         "Fletchling",
    "Fletchinder":        "Fletchinder",
    "Talonflame":         "Talonflame",
    "Skrelp":             "Skrelp",
    "Dragalge":           "Dragalge",
    "Inkay":              "Inkay",
    "Malamar":            "Malamar",
    "Doublade":           "Doublade",
    "Aegislash":          "Aegislash",
    "Phantump":           "Phantump",
    "Trevenant":          "Trevenant",
    "Pumpkaboo":          "Pumpkaboo",
    "Gourgeist":          "Gourgeist",
    "Flabebe":            "Flabebe",
    "Floette":            "Floette",
    "Florges":            "Florges",
    "Sylveon":            "Sylveon",
    "Hawlucha":           "Hawlucha",
    "Pancham":            "Pancham",
    "Pangoro":            "Pangoro",
    "Kleavor":            "Kleavor",
    # Gen 7
    "Grubbin":            "Grubbin",
    "Charjabug":          "Charjabug",
    "Vikavolt":           "Vikavolt",
    "Salandit":           "Salandit",
    "Salazzle":           "Salazzle",
    "Rockruff":           "Rockruff",
    "Lycanroc":           "Lycanroc",
    "Toxel":              "Toxel",
    "Toxtricity":         "Toxtricity",
    "Goomy":              "Goomy",
    "Sliggoo":            "Sliggoo",
    "Goodra":             "Goodra",
    "Ursaluna":           "Ursaluna",
    "Basculin":           "Basculin",
    "Basculegion":        "Basculegion",
    # Gen 8
    "Rookidee":           "Rookidee",
    "Corvisquire":        "Corvisquire",
    "Corviknight":        "Corviknight",
    "Dreepy":             "Dreepy",
    "Drakloak":           "Drakloak",
    "Dragapult":          "Dragapult",
    "Tinkatink":          "Tinkatink",
    "Tinkatuff":          "Tinkatuff",
    "Tinkaton":           "Tinkaton",
    "Sizzlipede":         "Sizzlipede",
    "Centiskorch":        "Centiskorch",
    "Obstagoon":          "Obstagoon",
    "MrRime":             "MrRime",
    "Sirfetchd":          "Sirfetchd",
    "Perrserker":         "Perrserker",
    "Duraludon":          "Duraludon",
    "Archaludon":         "Archaludon",
    "Kingambit":          "Kingambit",
    # Galarian forms
    "GalarianZigzagoon":  "ZigzagoonG",
    "GalarianLinoone":    "LinooneG",
    "GalarianMeowth":     "MeowthG",
    "GalarianMrMime":     "MrMime",           # no GalarianMrMime in DPE → use base
    "GalarianFarfetchd":  "FarfetchdG",
    "GalarianDarumaka":   "DarumakaG",
    "GalarianDarmanitan": "DarmanitanG",
    # Alolan forms
    "AlolanMeowth":       "MeowthA",
    "AlolanPersian":      "PersianA",
    "AlolanDiglett":      "DiglettA",
    "AlolanDugtrio":      "DugtrioA",
    "AlolanGeodude":      "GeodudeA",
    "AlolanGraveler":     "GravelerA",
    "AlolanGolem":        "GolemA",
    "AlolanVulpix":       "VulpixA",
    "AlolanNinetales":    "NinetalesA",
    "AlolanExeggutor":    "ExeggutorA",
    # Hisuian forms
    "HisuianZorua":       "ZoruaH",
    "HisuianZoroark":     "ZoroarkH",
    "HisuianGrowlithe":   "GrowlitheH",
    "HisuianArcanine":    "ArcanineH",
}

# De-duplicate: GalarianZigzagoon and GalarianLinoone appear twice in the dict literal
# above due to editing; Python keeps last occurrence, so they resolve correctly.


def build_fr_move_set(fr_moves_path):
    """Return dict: normalized_name → FR constant name (e.g. MOVEFURYSWIPES → MOVE_FURY_SWIPES)."""
    fr_moves = {}
    with open(fr_moves_path) as f:
        for line in f:
            m = re.match(r'^#define (MOVE_[A-Z0-9_]+)\s+\d+', line)
            if m:
                name = m.group(1)
                if name == "MOVE_UNAVAILABLE":
                    continue
                normalized = name.replace("_", "").upper()
                fr_moves[normalized] = name
    return fr_moves


def parse_dpe_learnsets(dpe_path):
    """Return dict: species_name → list of (level, dpe_move_name)."""
    learnsets = {}
    with open(dpe_path) as f:
        content = f.read()

    pattern = re.compile(
        r'static const struct LevelUpMove s(\w+)LevelUpLearnset\[\]\s*=\s*\{([^}]+)\}',
        re.DOTALL
    )
    move_pattern = re.compile(r'LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_\w+)\s*\)')

    for m in pattern.finditer(content):
        species = m.group(1)
        body = m.group(2)
        moves = []
        for mm in move_pattern.finditer(body):
            level = int(mm.group(1))
            move = mm.group(2)
            moves.append((level, move))
        learnsets[species] = moves

    return learnsets


def parse_fr_learnset(content, array_name):
    """Parse current FR learnset from file content. Returns list of (level, move) or None."""
    pattern = re.compile(
        r'static const u16 ' + re.escape(array_name) + r'\[\]\s*=\s*\{([^}]+)\}',
        re.DOTALL
    )
    m = pattern.search(content)
    if not m:
        return None
    move_pattern = re.compile(r'LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_\w+)\s*\)')
    return [(int(mm.group(1)), mm.group(2)) for mm in move_pattern.finditer(m.group(1))]


# DPE move names that normalize differently from their FR equivalents
_DPE_ALIASES = {
    "MOVEHIGHJUMPKICK": "MOVE_HI_JUMP_KICK",  # DPE: MOVE_HIGHJUMPKICK  FR: MOVE_HI_JUMP_KICK
    "MOVEFEINTATTACK":  "MOVE_FAINT_ATTACK",   # DPE: MOVE_FEINTATTACK   FR: MOVE_FAINT_ATTACK
}


def translate_move(dpe_move, fr_move_set):
    """Translate DPE move name to FR move name, or None if not in FR."""
    normalized = dpe_move.replace("_", "").upper()
    if normalized in _DPE_ALIASES:
        return _DPE_ALIASES[normalized]
    return fr_move_set.get(normalized)


def resolve_conflict(species, move, fr_level, dpe_level, dry_run):
    """
    Return the resolution for a conflict: 'F', 'D', or 'B'.
    In dry-run mode just prints the conflict and returns 'F'.
    Otherwise looks up DECISIONS (defaults to 'F' if not set).
    """
    key = f"{species}:{move}"
    choice = DECISIONS.get(key, "F").upper()
    tag = "(default F)" if key not in DECISIONS else f"→ {choice}"
    print(f"  CONFLICT {tag}: {species} — {move}  FR=lvl {fr_level}  DPE=lvl {dpe_level}")
    return "F" if dry_run else choice


def build_merged_body(fr_moves, dpe_moves, fr_move_set, species_name, dry_run):
    """
    Merge DPE moves into FR moves.
    Returns (new_body_str, n_added, n_conflicts).
    In dry-run mode returns the original body unchanged but still prints info.
    """
    fr_set = set(fr_moves)
    fr_by_move = {}
    for level, move in fr_moves:
        fr_by_move.setdefault(move, set()).add(level)

    additions = []
    conflict_map = {}

    for dpe_level, dpe_move_raw in dpe_moves:
        fr_move = translate_move(dpe_move_raw, fr_move_set)
        if fr_move is None:
            continue
        if (dpe_level, fr_move) in fr_set:
            continue

        if fr_move in fr_by_move:
            for fr_level in sorted(fr_by_move[fr_move]):
                conflict_map.setdefault(fr_move, []).append((fr_level, dpe_level))
        else:
            additions.append((dpe_level, fr_move))

    if additions and not dry_run:
        for lvl, mv in sorted(additions):
            print(f"  ADD: {species_name} — {mv} @ lvl {lvl}")

    removals = set()
    extra_adds = []
    n_conflicts = 0

    for move, pairs in conflict_map.items():
        seen_pairs = set()
        for fr_level, dpe_level in pairs:
            pair_key = (fr_level, dpe_level)
            if pair_key in seen_pairs:
                continue
            seen_pairs.add(pair_key)
            n_conflicts += 1
            choice = resolve_conflict(species_name, move, fr_level, dpe_level, dry_run)
            if choice == "D":
                removals.add((fr_level, move))
                extra_adds.append((dpe_level, move))
            elif choice == "B":
                extra_adds.append((dpe_level, move))

    n_added = len(additions) + len(extra_adds)

    if dry_run:
        # Return unchanged body
        orig_lines = [f"    LEVEL_UP_MOVE({lvl}, {mv})," for lvl, mv in fr_moves]
        orig_lines.append("    LEVEL_UP_END")
        return "\n".join(orig_lines), 0, n_conflicts

    merged = [e for e in fr_moves if e not in removals]
    merged_set = set(merged)
    for entry in additions + extra_adds:
        if entry not in merged_set:
            merged.append(entry)
            merged_set.add(entry)

    merged.sort(key=lambda x: (x[0], x[1]))
    lines = [f"    LEVEL_UP_MOVE({lvl}, {mv})," for lvl, mv in merged]
    lines.append("    LEVEL_UP_END")
    return "\n".join(lines), n_added, n_conflicts


def update_learnsets(fr_learnsets_path, species_to_dpe, dpe_learnsets, fr_move_set, dry_run):
    with open(fr_learnsets_path) as f:
        content = f.read()

    updated = 0
    unchanged = 0
    skipped = []
    total_added = 0
    total_conflicts = 0

    for fr_name, dpe_name in species_to_dpe.items():
        dpe_moves = dpe_learnsets.get(dpe_name)
        if dpe_moves is None:
            skipped.append(f"{fr_name} → {dpe_name} (not in DPE)")
            continue

        array_name = f"s{fr_name}LevelUpLearnset"

        fr_moves = parse_fr_learnset(content, array_name)
        if fr_moves is None:
            skipped.append(f"{fr_name} → array '{array_name}' not found in FR file")
            continue

        new_body, n_added, n_conflicts = build_merged_body(
            fr_moves, dpe_moves, fr_move_set, fr_name, dry_run
        )
        total_added += n_added
        total_conflicts += n_conflicts

        if dry_run:
            continue

        pattern = re.compile(
            r'(static const u16 ' + re.escape(array_name) + r'\[\]\s*=\s*\{)[^}]*(})',
            re.DOTALL
        )
        replacement = r'\g<1>' + '\n' + new_body + '\n' + r'\g<2>'
        new_content, n = pattern.subn(replacement, content)

        if n == 0:
            skipped.append(f"{fr_name} → pattern replacement failed")
        else:
            if new_content == content:
                unchanged += 1
            else:
                content = new_content
                updated += 1

    if not dry_run:
        with open(fr_learnsets_path, "w") as f:
            f.write(content)
        print(f"\nUpdated {updated} learnsets ({total_added} moves added), "
              f"{unchanged} already up to date, {total_conflicts} conflicts resolved.")
    else:
        print(f"\n[DRY RUN] {total_conflicts} conflicts found across all species.")
        print("Fill in DECISIONS dict in extract_dpe_learnsets.py, then re-run without --dry-run.")

    if skipped:
        print(f"\nSkipped ({len(skipped)}):")
        for s in skipped:
            print(f"  {s}")


def main():
    dry_run = "--dry-run" in sys.argv

    fr_move_set = build_fr_move_set(FR_MOVES_H)
    print(f"Loaded {len(fr_move_set)} FR moves.")

    dpe_learnsets = parse_dpe_learnsets(DPE_LEARNSETS)
    print(f"Parsed {len(dpe_learnsets)} DPE learnsets.")

    missing_dpe = [(fr, dpe) for fr, dpe in SPECIES_TO_DPE.items()
                   if dpe not in dpe_learnsets]
    if missing_dpe:
        print(f"\nWARNING: {len(missing_dpe)} DPE names not found in Learnsets.c:")
        for fr, dpe in missing_dpe:
            print(f"  {fr} → {dpe}")

    if dry_run:
        print("\n[DRY RUN] Scanning for conflicts — no files will be modified.\n")

    update_learnsets(FR_LEARNSETS, SPECIES_TO_DPE, dpe_learnsets, fr_move_set, dry_run)


if __name__ == "__main__":
    main()
