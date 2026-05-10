#!/usr/bin/env python3
"""
assign_trainer_movesets.py

1. Converts every NO_ITEM_DEFAULT_MOVES / ITEM_DEFAULT_MOVES trainer party to
   a custom-moves party. Movesets are chosen from the species' level-up learnset
   using a heuristic that prefers STAB moves, high-power moves, and useful status
   moves over filler (Growl, Leer, String Shot, etc.).

2. Upgrades every trainer's AI flags to:
       AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY

Run from the project root:
    python3 tools/assign_trainer_movesets.py

Modifies in place:
    src/data/trainer_parties.h
    src/data/trainers.h
"""

import re
import sys

ROOT = "."
MAX_AI = "AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY"

# ── Move quality heuristics ────────────────────────────────────────────────────

# Moves that are almost always useless for AI trainers.
FILLER = {
    "MOVE_GROWL", "MOVE_LEER", "MOVE_TAIL_WHIP", "MOVE_SAND_ATTACK",
    "MOVE_SMOKESCREEN", "MOVE_STRING_SHOT", "MOVE_SPLASH", "MOVE_TELEPORT",
    "MOVE_HARDEN", "MOVE_WITHDRAW", "MOVE_DEFENSE_CURL", "MOVE_SHARPEN",
    "MOVE_BIDE", "MOVE_RAGE", "MOVE_LOCK_ON", "MOVE_MIND_READER",
    "MOVE_CONVERSION", "MOVE_CONVERSION_2", "MOVE_CONSTRICT",
    "MOVE_SCARY_FACE",  # speed-lowering on opponent, AI won't chain it
}

# Status / utility moves with hand-tuned quality scores.
STATUS_SCORES = {
    # Sleep
    "MOVE_SPORE": 72, "MOVE_SLEEP_POWDER": 66, "MOVE_LOVELY_KISS": 52,
    "MOVE_HYPNOSIS": 50, "MOVE_YAWN": 50, "MOVE_SING": 38,
    # Paralysis
    "MOVE_TOXIC": 66, "MOVE_WILL_O_WISP": 62,
    "MOVE_THUNDER_WAVE": 61, "MOVE_GLARE": 56, "MOVE_STUN_SPORE": 52,
    # Boosting (self)
    "MOVE_SWORDS_DANCE": 59, "MOVE_DRAGON_DANCE": 63, "MOVE_NASTY_PLOT": 59,
    "MOVE_CALM_MIND": 59, "MOVE_BULK_UP": 59, "MOVE_AGILITY": 50,
    "MOVE_AMNESIA": 52, "MOVE_HOWL": 44, "MOVE_GROWTH": 42,
    "MOVE_IRON_DEFENSE": 45, "MOVE_ACID_ARMOR": 42, "MOVE_BARRIER": 42,
    "MOVE_STOCKPILE": 36,
    # Recovery
    "MOVE_RECOVER": 63, "MOVE_SOFTBOILED": 63, "MOVE_SLACK_OFF": 61,
    "MOVE_SYNTHESIS": 56, "MOVE_MOONLIGHT": 56, "MOVE_MORNING_SUN": 56,
    "MOVE_REST": 55,
    # Hazards / entry
    "MOVE_LEECH_SEED": 49, "MOVE_SUBSTITUTE": 49,
    "MOVE_STEALTH_ROCK": 51, "MOVE_SPIKES": 46, "MOVE_TOXIC_SPIKES": 46,
    # Disruption
    "MOVE_TAUNT": 41, "MOVE_ENCORE": 36, "MOVE_PROTECT": 38,
    "MOVE_CURSE": 49, "MOVE_COSMIC_POWER": 40,
    "MOVE_LIGHT_SCREEN": 43, "MOVE_REFLECT": 43,
    "MOVE_PAIN_SPLIT": 36, "MOVE_DESTINY_BOND": 33,
    "MOVE_TRICK": 36, "MOVE_TRICK_ROOM": 36,
    "MOVE_DISABLE": 28,
    # Healing entry moves / items
    "MOVE_INGRAIN": 30,
}

# Moves whose .power = 0 in battle_moves.h but still deal real damage.
SPECIAL_POWER = {
    "MOVE_DRAGON_RAGE": 40, "MOVE_SONIC_BOOM": 35,
    "MOVE_NIGHT_SHADE": 50, "MOVE_SEISMIC_TOSS": 50,
    "MOVE_SUPER_FANG": 48, "MOVE_PSYWAVE": 32,
    "MOVE_FISSURE": 50, "MOVE_GUILLOTINE": 50,
    "MOVE_HORN_DRILL": 50, "MOVE_SHEER_COLD": 50,
    "MOVE_COUNTER": 55, "MOVE_MIRROR_COAT": 55, "MOVE_METAL_BURST": 50,
    "MOVE_ENDEAVOR": 46, "MOVE_FINAL_GAMBIT": 46,
    "MOVE_RETURN": 100, "MOVE_FRUSTRATION": 60,
    "MOVE_HIDDEN_POWER": 68,
    "MOVE_MAGNITUDE": 70, "MOVE_NATURE_POWER": 55,
    "MOVE_GRASS_KNOT": 65, "MOVE_LOW_KICK": 65,
    "MOVE_GYRO_BALL": 60, "MOVE_ELECTRO_BALL": 55,
    "MOVE_BEAT_UP": 45, "MOVE_TRUMP_CARD": 55,
    "MOVE_SPIT_UP": 60,
}


# ── Data parsers ───────────────────────────────────────────────────────────────

def parse_move_data(path):
    """Return {MOVE_X: {power, type, accuracy}} parsed from battle_moves.h."""
    result = {}
    try:
        text = open(f"{ROOT}/{path}").read()
    except FileNotFoundError:
        print(f"  WARNING: {path} not found", file=sys.stderr)
        return result

    for block in re.finditer(r'\[(MOVE_\w+)\]\s*=\s*\{([^}]*)\}', text, re.DOTALL):
        move = block.group(1)
        body = block.group(2)
        pm = re.search(r'\.power\s*=\s*(\d+)', body)
        tm = re.search(r'\.type\s*=\s*(TYPE_\w+)', body)
        am = re.search(r'\.accuracy\s*=\s*(\d+)', body)
        result[move] = {
            'power':    int(pm.group(1)) if pm else 0,
            'type':     tm.group(1) if tm else 'TYPE_NORMAL',
            'accuracy': int(am.group(1)) if am else 100,
        }
    return result


def parse_species_types(paths):
    """Return {SPECIES_X: (type1, type2)} from species_info source files.

    Uses brace-depth tracking to handle nested braces inside entries
    (e.g. .types = {TYPE_GRASS, TYPE_POISON}).
    """
    result = {}
    for path in paths:
        try:
            text = open(f"{ROOT}/{path}").read()
        except FileNotFoundError:
            continue

        i = 0
        while i < len(text):
            # Find next [SPECIES_X] =
            sm = re.search(r'\[(SPECIES_\w+)\]\s*=\s*', text[i:])
            if not sm:
                break
            species = sm.group(1)
            pos = i + sm.end()

            # Skip whitespace to find the opening {
            bm = re.match(r'\s*\{', text[pos:])
            if not bm:
                i = pos
                continue
            pos += bm.end()

            # Walk forward with brace-depth tracking to find the matching }
            depth, start = 1, pos
            while pos < len(text) and depth > 0:
                if text[pos] == '{':
                    depth += 1
                elif text[pos] == '}':
                    depth -= 1
                pos += 1

            body = text[start:pos - 1]
            i = pos

            if species in result:
                continue
            tm = re.search(
                r'\.types\s*=\s*\{\s*(TYPE_\w+)\s*,\s*(TYPE_\w+)\s*\}', body)
            if tm:
                result[species] = (tm.group(1), tm.group(2))

    return result


def parse_learnsets(learnsets_path, pointers_path):
    """Return {SPECIES_X: [(level, MOVE_Y), ...]} sorted ascending by level."""
    try:
        ls_text  = open(f"{ROOT}/{learnsets_path}").read()
        ptr_text = open(f"{ROOT}/{pointers_path}").read()
    except FileNotFoundError as e:
        print(f"  ERROR: {e}", file=sys.stderr)
        sys.exit(1)

    arrays = {}
    for m in re.finditer(
        r'static const u16 (s\w+LevelUpLearnset)\[\]\s*=\s*\{(.*?)\};',
        ls_text, re.DOTALL
    ):
        name    = m.group(1)
        entries = [(int(lv), mv) for lv, mv in
                   re.findall(
                       r'LEVEL_UP_MOVE\s*\(\s*(\d+)\s*,\s*(MOVE_\w+)\s*\)',
                       m.group(2))]
        arrays[name] = sorted(entries, key=lambda x: x[0])

    result = {}
    for m in re.finditer(r'\[(SPECIES_\w+)\]\s*=\s*(s\w+LevelUpLearnset)', ptr_text):
        species, arr = m.group(1), m.group(2)
        if arr in arrays:
            result[species] = arrays[arr]
    return result


# ── Move selection ─────────────────────────────────────────────────────────────

def get_moves_at_level(species, level, learnsets):
    """Return all unique moves learnable at or before the given level."""
    entries = learnsets.get(species, [])
    seen, moves = set(), []
    for lv, mv in entries:
        if lv <= max(level, 1) and mv not in seen:
            seen.add(mv)
            moves.append(mv)
    return moves


def score_move(move, sp_types, move_data):
    """Return a quality score for the move; negative = never pick."""
    if move in FILLER:
        return -1000
    if move in STATUS_SCORES:
        return STATUS_SCORES[move]
    if move in SPECIAL_POWER:
        base = SPECIAL_POWER[move]
        md = move_data.get(move, {})
        if md.get('type') in sp_types:
            base += 28
        return base

    md = move_data.get(move)
    if not md:
        return 22   # unknown move — low but positive

    power = md['power']
    if power == 0:
        return 10   # unknown status move

    score = power
    if md['type'] in sp_types:
        score += 28   # STAB bonus

    acc = md['accuracy']
    if 0 < acc < 100:
        score = int(score * acc / 100)
    elif acc == 0:
        score += 6    # always-hit (Swift, Aerial Ace, etc.)

    return score


def select_moves(species, level, learnsets, species_types, move_data):
    """Return the best 4-move list for a trainer Pokemon."""
    available = get_moves_at_level(species, level, learnsets)
    sp_types  = species_types.get(species, ("TYPE_NORMAL", "TYPE_NORMAL"))

    if not available:
        return ["MOVE_NONE"] * 4

    scored = sorted(
        ((score_move(m, sp_types, move_data), m) for m in available),
        key=lambda x: -x[0]
    )
    scored = [(s, m) for s, m in scored if s >= 0]  # drop fillers

    # Pick top 4 with type variety (max 2 moves of the same type).
    selected, type_count = [], {}
    for _, move in scored:
        if len(selected) >= 4:
            break
        mtype = move_data.get(move, {}).get('type', 'TYPE_NORMAL')
        if type_count.get(mtype, 0) < 2:
            selected.append(move)
            type_count[mtype] = type_count.get(mtype, 0) + 1

    # If variety filter left us with fewer than 4, fill from the scored list.
    if len(selected) < 4:
        for _, move in scored:
            if move not in selected:
                selected.append(move)
            if len(selected) >= 4:
                break

    while len(selected) < 4:
        selected.append("MOVE_NONE")

    return selected[:4]


# ── File processing ────────────────────────────────────────────────────────────

def process_parties(text, learnsets, species_types, move_data):
    """
    Convert all TrainerMon*DefaultMoves blocks to TrainerMon*CustomMoves blocks,
    inserting optimal .moves = {...} fields. Returns (new_text, converted_set, n_mons).
    """
    converted  = set()
    total_mons = [0]

    def replace_mon(mm):
        """Replace a single {.iv=...,.lvl=...,.species=...}, block."""
        mon_text = mm.group(1)
        sm = re.search(r'\.species\s*=\s*(SPECIES_\w+)', mon_text)
        lm = re.search(r'\.lvl\s*=\s*(\d+)', mon_text)
        if not sm or not lm:
            return mm.group(0)   # unparseable — leave unchanged

        species = sm.group(1)
        level   = int(lm.group(1))
        moves   = select_moves(species, level, learnsets, species_types, move_data)
        moves_str = ", ".join(moves)
        total_mons[0] += 1

        inner = mon_text.strip()  # remove leading/trailing whitespace

        if '\n' not in inner:
            # Compact single-line format: { .iv=0, .lvl=10, .species=X }
            # Ensure a trailing comma before appending .moves
            if not inner.endswith(','):
                inner += ','
            return f'{{ {inner} .moves = {{{moves_str}}} }},'
        else:
            # Standard multi-line format
            fi = re.search(r'\n( +)\.', mon_text)
            field_indent = fi.group(1) if fi else "        "
            stripped    = mon_text.rstrip()
            trailing_ws = mon_text[len(stripped):]
            new_text = (stripped
                        + f'\n{field_indent}.moves = {{{moves_str}}},'
                        + trailing_ws)
            return '{' + new_text + '},'

    def replace_party(m):
        """Replace a full sParty_* block."""
        struct_type = m.group(1)   # TrainerMonNoItemDefaultMoves / TrainerMonItemDefaultMoves
        party_name  = m.group(2)
        body        = m.group(3)

        # Skip RS stub entries that use DUMMY_TRAINER macros.
        if 'DUMMY_TRAINER' in body:
            return m.group(0)

        new_body   = re.sub(r'\{([^{}]*)\},', replace_mon, body)
        new_struct = struct_type.replace('DefaultMoves', 'CustomMoves')
        converted.add(party_name)
        return f'static const struct {new_struct} {party_name}[] = {{{new_body}}};'

    pattern = re.compile(
        r'static const struct (TrainerMon\w+DefaultMoves)\s+(sParty_\w+)\[\]\s*=\s*\{(.*?)\};',
        re.DOTALL
    )
    new_text = pattern.sub(replace_party, text)
    return new_text, converted, total_mons[0]


def process_trainers(text, converted):
    """
    In trainers.h:
    1. Replace every .aiFlags line with the maximum AI flag combination.
    2. Change DEFAULT_MOVES → CUSTOM_MOVES macros for converted parties.
    """
    # Update AI flags on every trainer.
    text = re.sub(
        r'(\.aiFlags\s*=\s*)[^\n,]+',
        rf'\1{MAX_AI}',
        text
    )

    # Swap macro names only for parties that were actually converted.
    def fix_macro(m):
        pname = m.group(2)
        if pname in converted:
            return m.group(0).replace('DEFAULT_MOVES', 'CUSTOM_MOVES')
        return m.group(0)

    text = re.sub(r'((?:NO_ITEM|ITEM)_DEFAULT_MOVES)\((\w+)\)', fix_macro, text)
    return text


# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    print("Loading data...", file=sys.stderr)

    move_data = parse_move_data("src/data/battle_moves.h")
    print(f"  {len(move_data)} moves", file=sys.stderr)

    species_types = parse_species_types([
        "src/data/pokemon/species_info.h",
        "build/step5_species_info.inc",
    ])
    print(f"  {len(species_types)} species with type data", file=sys.stderr)

    learnsets = parse_learnsets(
        "src/data/pokemon/level_up_learnsets.h",
        "src/data/pokemon/level_up_learnset_pointers.h",
    )
    print(f"  {len(learnsets)} species learnsets", file=sys.stderr)

    # ── trainer_parties.h ──────────────────────────────────────────────────
    parties_path = "src/data/trainer_parties.h"
    print(f"\nProcessing {parties_path}...", file=sys.stderr)
    parties_text = open(f"{ROOT}/{parties_path}").read()

    new_parties, converted, n_mons = process_parties(
        parties_text, learnsets, species_types, move_data)

    print(f"  {len(converted)} parties converted, {n_mons} Pokémon assigned custom moves",
          file=sys.stderr)

    with open(f"{ROOT}/{parties_path}", 'w') as f:
        f.write(new_parties)
    print(f"  Saved {parties_path}", file=sys.stderr)

    # ── trainers.h ────────────────────────────────────────────────────────
    trainers_path = "src/data/trainers.h"
    print(f"\nProcessing {trainers_path}...", file=sys.stderr)
    trainers_text = open(f"{ROOT}/{trainers_path}").read()

    n_ai    = trainers_text.count('.aiFlags =')
    new_trainers = process_trainers(trainers_text, converted)

    with open(f"{ROOT}/{trainers_path}", 'w') as f:
        f.write(new_trainers)
    print(f"  {n_ai} AI flags set to max", file=sys.stderr)
    print(f"  {len(converted)} party macros changed to CUSTOM_MOVES", file=sys.stderr)
    print(f"  Saved {trainers_path}", file=sys.stderr)

    print("\nDone. Run:  make -j$(nproc)", file=sys.stderr)


if __name__ == "__main__":
    main()
