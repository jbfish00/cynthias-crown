#!/usr/bin/env python3
"""
Assign SPLIT_PHYSICAL / SPLIT_SPECIAL / SPLIT_STATUS to every move entry
in src/data/battle_moves.h based on Gen 4+ categories.

Algorithm:
  1. Parse include/constants/moves.h for move name -> power mapping.
  2. For each [MOVE_X] block, determine split:
       - power == 0 -> SPLIT_STATUS
       - else: default by Gen 3 type (TYPE_FIRE..FAIRY = special, others = physical)
       - then apply override dict for moves whose Gen 4+ split differs
  3. Insert ".split = SPLIT_*," after the .flags = ... line.

Usage:
  python3 tools/assign_move_splits.py [--dry-run]
"""

import re
import sys

MOVES_H      = "src/data/battle_moves.h"
CONSTANTS_H  = "include/constants/moves.h"

# Gen 3 special types (type values 10-18 in include/constants/pokemon.h)
SPECIAL_TYPES = {
    "TYPE_FIRE", "TYPE_WATER", "TYPE_GRASS", "TYPE_ELECTRIC",
    "TYPE_PSYCHIC", "TYPE_ICE", "TYPE_DRAGON", "TYPE_DARK",
    "TYPE_FAIRY",
}

# Overrides: move_name -> split  (where Gen 4+ split differs from the Gen 3 type assumption)
SPLIT_OVERRIDES = {
    # Ghost (Gen3=physical) -> special in Gen4+
    "MOVE_SHADOW_BALL":         "SPLIT_SPECIAL",
    "MOVE_OMINOUS_WIND":        "SPLIT_SPECIAL",
    "MOVE_HEX":                 "SPLIT_SPECIAL",
    "MOVE_NIGHT_SHADE":         "SPLIT_SPECIAL",
    # Dark (Gen3=special) -> physical in Gen4+
    "MOVE_BITE":                "SPLIT_PHYSICAL",
    "MOVE_CRUNCH":              "SPLIT_PHYSICAL",
    "MOVE_FAINT_ATTACK":        "SPLIT_PHYSICAL",
    "MOVE_FEINT_ATTACK":        "SPLIT_PHYSICAL",
    "MOVE_KNOCK_OFF":           "SPLIT_PHYSICAL",
    "MOVE_THIEF":               "SPLIT_PHYSICAL",
    "MOVE_PURSUIT":             "SPLIT_PHYSICAL",
    "MOVE_BEAT_UP":             "SPLIT_PHYSICAL",
    "MOVE_NIGHT_SLASH":         "SPLIT_PHYSICAL",
    "MOVE_SUCKER_PUNCH":        "SPLIT_PHYSICAL",
    "MOVE_ASSURANCE":           "SPLIT_PHYSICAL",
    "MOVE_PAYBACK":             "SPLIT_PHYSICAL",
    "MOVE_PUNISHMENT":          "SPLIT_PHYSICAL",
    "MOVE_EMBARGO":             "SPLIT_STATUS",
    "MOVE_FOUL_PLAY":           "SPLIT_PHYSICAL",
    "MOVE_BRUTAL_SWING":        "SPLIT_PHYSICAL",
    "MOVE_LASH_OUT":            "SPLIT_PHYSICAL",
    "MOVE_THROAT_CHOP":         "SPLIT_PHYSICAL",
    "MOVE_DARKEST_LARIAT":      "SPLIT_PHYSICAL",
    "MOVE_HYPERSPACE_FURY":     "SPLIT_PHYSICAL",
    "MOVE_SNARL":               "SPLIT_SPECIAL",
    "MOVE_DARK_PULSE":          "SPLIT_SPECIAL",
    "MOVE_NIGHT_DAZE":          "SPLIT_SPECIAL",
    "MOVE_FIERY_WRATH":         "SPLIT_SPECIAL",
    "MOVE_RUINATION":           "SPLIT_SPECIAL",
    "MOVE_WICKED_BLOW":         "SPLIT_PHYSICAL",
    "MOVE_KOWTOW_CLEAVE":       "SPLIT_PHYSICAL",
    # Psychic (Gen3=special) -> physical
    "MOVE_PSYCHO_CUT":          "SPLIT_PHYSICAL",
    "MOVE_ZEN_HEADBUTT":        "SPLIT_PHYSICAL",
    "MOVE_PSYSHOCK":            "SPLIT_SPECIAL",   # special split, but hits Def (effect)
    "MOVE_PSYSTRIKE":           "SPLIT_SPECIAL",
    "MOVE_HEART_STAMP":         "SPLIT_PHYSICAL",
    # Ice (Gen3=special) -> physical
    "MOVE_ICE_PUNCH":           "SPLIT_PHYSICAL",
    "MOVE_ICE_SHARD":           "SPLIT_PHYSICAL",
    "MOVE_ICICLE_CRASH":        "SPLIT_PHYSICAL",
    "MOVE_ICICLE_SPEAR":        "SPLIT_PHYSICAL",
    "MOVE_ICE_FANG":            "SPLIT_PHYSICAL",
    "MOVE_TRIPLE_AXEL":         "SPLIT_PHYSICAL",
    "MOVE_FREEZE_DRY":          "SPLIT_SPECIAL",
    # Fire (Gen3=special) -> physical
    "MOVE_FIRE_PUNCH":          "SPLIT_PHYSICAL",
    "MOVE_BLAZE_KICK":          "SPLIT_PHYSICAL",
    "MOVE_FLAME_CHARGE":        "SPLIT_PHYSICAL",
    "MOVE_FLARE_BLITZ":         "SPLIT_PHYSICAL",
    "MOVE_FIRE_FANG":           "SPLIT_PHYSICAL",
    "MOVE_FLAME_WHEEL":         "SPLIT_PHYSICAL",
    "MOVE_SACRED_FIRE":         "SPLIT_PHYSICAL",
    "MOVE_V_CREATE":            "SPLIT_PHYSICAL",
    # Electric (Gen3=special) -> physical
    "MOVE_THUNDER_PUNCH":       "SPLIT_PHYSICAL",
    "MOVE_WILD_CHARGE":         "SPLIT_PHYSICAL",
    "MOVE_VOLT_TACKLE":         "SPLIT_PHYSICAL",
    "MOVE_SPARK":               "SPLIT_PHYSICAL",
    "MOVE_THUNDER_FANG":        "SPLIT_PHYSICAL",
    "MOVE_NUZZLE":              "SPLIT_PHYSICAL",
    "MOVE_BOLT_STRIKE":         "SPLIT_PHYSICAL",
    "MOVE_RISING_VOLTAGE":      "SPLIT_SPECIAL",
    "MOVE_THUNDEROUS_KICK":     "SPLIT_PHYSICAL",
    # Water (Gen3=special) -> physical
    "MOVE_WATERFALL":           "SPLIT_PHYSICAL",
    "MOVE_AQUA_TAIL":           "SPLIT_PHYSICAL",
    "MOVE_AQUA_JET":            "SPLIT_PHYSICAL",
    "MOVE_CRABHAMMER":          "SPLIT_PHYSICAL",
    "MOVE_LIQUIDATION":         "SPLIT_PHYSICAL",
    "MOVE_WAVE_CRASH":          "SPLIT_PHYSICAL",
    "MOVE_DIVE":                "SPLIT_PHYSICAL",
    "MOVE_FLIP_TURN":           "SPLIT_PHYSICAL",
    # Grass (Gen3=special) -> physical
    "MOVE_LEAF_BLADE":          "SPLIT_PHYSICAL",
    "MOVE_SEED_BOMB":           "SPLIT_PHYSICAL",
    "MOVE_WOOD_HAMMER":         "SPLIT_PHYSICAL",
    "MOVE_POWER_WHIP":          "SPLIT_PHYSICAL",
    "MOVE_BULLET_SEED":         "SPLIT_PHYSICAL",
    "MOVE_RAZOR_LEAF":          "SPLIT_PHYSICAL",
    "MOVE_LEAF_TORNADO":        "SPLIT_PHYSICAL",
    "MOVE_PETAL_BLIZZARD":      "SPLIT_PHYSICAL",
    "MOVE_TROP_KICK":           "SPLIT_PHYSICAL",
    "MOVE_SNAP_TRAP":           "SPLIT_PHYSICAL",
    "MOVE_BRANCH_POKE":         "SPLIT_PHYSICAL",
    # Dragon (Gen3=special) -> physical
    "MOVE_DRAGON_CLAW":         "SPLIT_PHYSICAL",
    "MOVE_DRAGON_RUSH":         "SPLIT_PHYSICAL",
    "MOVE_DRAGON_TAIL":         "SPLIT_PHYSICAL",
    "MOVE_OUTRAGE":             "SPLIT_PHYSICAL",
    "MOVE_DUAL_CHOP":           "SPLIT_PHYSICAL",
    "MOVE_SCALE_SHOT":          "SPLIT_PHYSICAL",
    "MOVE_BREAKING_SWIPE":      "SPLIT_PHYSICAL",
    # Normal (Gen3=physical) -> special
    "MOVE_HYPER_VOICE":         "SPLIT_SPECIAL",
    "MOVE_ROUND":               "SPLIT_SPECIAL",
    "MOVE_BOOMBURST":           "SPLIT_SPECIAL",
    "MOVE_ECHOED_VOICE":        "SPLIT_SPECIAL",
    "MOVE_SWIFT":               "SPLIT_SPECIAL",
    "MOVE_SNORE":               "SPLIT_SPECIAL",
    "MOVE_TRI_ATTACK":          "SPLIT_SPECIAL",
    "MOVE_HYPER_BEAM":          "SPLIT_SPECIAL",
    "MOVE_WEATHER_BALL":        "SPLIT_SPECIAL",
    "MOVE_REVELATION_DANCE":    "SPLIT_SPECIAL",
    "MOVE_NATURAL_GIFT":        "SPLIT_PHYSICAL",
    # Bug (Gen3=physical) -> special
    "MOVE_BUG_BUZZ":            "SPLIT_SPECIAL",
    "MOVE_SIGNAL_BEAM":         "SPLIT_SPECIAL",
    "MOVE_INFESTATION":         "SPLIT_SPECIAL",
    "MOVE_POLLEN_PUFF":         "SPLIT_SPECIAL",
    # Rock (Gen3=physical) -> special
    "MOVE_POWER_GEM":           "SPLIT_SPECIAL",
    # Steel (Gen3=physical) -> special
    "MOVE_FLASH_CANNON":        "SPLIT_SPECIAL",
    "MOVE_MIRROR_SHOT":         "SPLIT_SPECIAL",
    "MOVE_MAGNET_BOMB":         "SPLIT_SPECIAL",
    "MOVE_STEEL_BEAM":          "SPLIT_SPECIAL",
    "MOVE_STEEL_ROLLER":        "SPLIT_PHYSICAL",
    # Flying (Gen3=special) -> physical
    "MOVE_AERIAL_ACE":          "SPLIT_PHYSICAL",
    "MOVE_ACROBATICS":          "SPLIT_PHYSICAL",
    "MOVE_BRAVE_BIRD":          "SPLIT_PHYSICAL",
    "MOVE_SKY_ATTACK":          "SPLIT_PHYSICAL",
    "MOVE_FLY":                 "SPLIT_PHYSICAL",
    "MOVE_PECK":                "SPLIT_PHYSICAL",
    "MOVE_DRILL_PECK":          "SPLIT_PHYSICAL",
    "MOVE_WING_ATTACK":         "SPLIT_PHYSICAL",
    "MOVE_BOUNCE":              "SPLIT_PHYSICAL",
    "MOVE_SKY_DROP":            "SPLIT_PHYSICAL",
    "MOVE_DUAL_WINGBEAT":       "SPLIT_PHYSICAL",
    # Poison (Gen3=physical) -> some are special
    "MOVE_SLUDGE_BOMB":         "SPLIT_SPECIAL",
    "MOVE_SLUDGE_WAVE":         "SPLIT_SPECIAL",
    "MOVE_ACID_SPRAY":          "SPLIT_SPECIAL",
    "MOVE_VENOSHOCK":           "SPLIT_SPECIAL",
    "MOVE_CLEAR_SMOG":          "SPLIT_SPECIAL",
    "MOVE_SLUDGE":              "SPLIT_SPECIAL",
    "MOVE_ACID":                "SPLIT_SPECIAL",
    "MOVE_BELCH":               "SPLIT_SPECIAL",
    # Ground (Gen3=physical) -> some are special
    "MOVE_EARTH_POWER":         "SPLIT_SPECIAL",
    "MOVE_MUD_BOMB":            "SPLIT_SPECIAL",
    # Fairy (all Gen4+ = special unless otherwise listed)
    "MOVE_PLAY_ROUGH":          "SPLIT_PHYSICAL",
    "MOVE_FAIRY_WIND":          "SPLIT_SPECIAL",
    "MOVE_DISARMING_VOICE":     "SPLIT_SPECIAL",
    "MOVE_DRAINING_KISS":       "SPLIT_SPECIAL",
    "MOVE_DAZZLING_GLEAM":      "SPLIT_SPECIAL",
    "MOVE_MOONBLAST":           "SPLIT_SPECIAL",
    "MOVE_SPARKLING_ARIA":      "SPLIT_SPECIAL",
    "MOVE_TWINKLE_TACKLE":      "SPLIT_SPECIAL",
    "MOVE_LIGHT_OF_RUIN":       "SPLIT_SPECIAL",
    "MOVE_FLEUR_CANNON":        "SPLIT_SPECIAL",
    "MOVE_CHARM_OFFENSIVE":     "SPLIT_SPECIAL",
}

def parse_move_constants(path):
    """Return dict {MOVE_NAME: power_or_None} — we only need names here."""
    names = set()
    with open(path) as f:
        for line in f:
            m = re.match(r'\s*#define\s+(MOVE_\w+)\s+(\d+)', line)
            if m:
                names.add(m.group(1))
    return names

def get_type_from_block(block):
    m = re.search(r'\.type\s*=\s*(\w+)', block)
    return m.group(1) if m else None

def get_power_from_block(block):
    m = re.search(r'\.power\s*=\s*(\d+)', block)
    return int(m.group(1)) if m else 0

def determine_split(move_name, block):
    power = get_power_from_block(block)
    if power == 0:
        return "SPLIT_STATUS"
    if move_name in SPLIT_OVERRIDES:
        return SPLIT_OVERRIDES[move_name]
    move_type = get_type_from_block(block)
    if move_type in SPECIAL_TYPES:
        return "SPLIT_SPECIAL"
    return "SPLIT_PHYSICAL"

def process(dry_run):
    with open(MOVES_H) as f:
        content = f.read()

    # Split file into move blocks; pattern: [MOVE_X] = \n    {\n ... \n    },
    block_pat = re.compile(
        r'(\[MOVE_\w+\]\s*=\s*\n\s*\{[^}]+\})',
        re.MULTILINE,
    )

    changes = 0
    new_content = content

    for m in block_pat.finditer(content):
        block_text = m.group(1)

        # Already has .split?
        if '.split' in block_text:
            continue

        # Extract move name
        name_m = re.match(r'\[(MOVE_\w+)\]', block_text)
        if not name_m:
            continue
        move_name = name_m.group(1)

        split = determine_split(move_name, block_text)

        # Insert after .flags = ...,
        flags_m = re.search(r'(\.flags\s*=[^,\n]+,)', block_text)
        if not flags_m:
            print(f"  WARNING: no .flags line in {move_name} block, skipping")
            continue

        old_flags_line = flags_m.group(1)
        new_flags_line = old_flags_line + f"\n        .split = {split},"

        new_block = block_text.replace(old_flags_line, new_flags_line, 1)
        new_content = new_content.replace(block_text, new_block, 1)
        changes += 1

    if dry_run:
        print(f"[DRY RUN] {changes} move entries would get .split field.")
    else:
        with open(MOVES_H, 'w') as f:
            f.write(new_content)
        print(f"Applied .split to {changes} move entries in {MOVES_H}.")

if __name__ == "__main__":
    dry_run = "--dry-run" in sys.argv
    process(dry_run)
