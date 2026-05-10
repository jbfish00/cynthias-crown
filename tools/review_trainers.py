#!/usr/bin/env python3
"""Generate a human-readable Markdown report of all custom-moveset trainer teams.

Usage:
    python3 tools/review_trainers.py > /tmp/trainer_review.md
"""

import re
import sys
from collections import defaultdict

ROOT = "."


def title(s):
    """SHADOW_BALL -> Shadow Ball, NONE -> —"""
    if s in ("NONE", ""):
        return "—"
    return s.replace("_", " ").title()


def parse_defines(path, prefix):
    """Return {value: human_name} for all #define PREFIX_NAME value lines."""
    result = {}
    try:
        text = open(f"{ROOT}/{path}").read()
    except FileNotFoundError:
        return result
    for m in re.finditer(rf"#define\s+{re.escape(prefix)}(\w+)\s+(\d+)", text):
        name, val = m.group(1), int(m.group(2))
        if val not in result:  # keep first definition
            result[val] = title(name)
    return result


def parse_enum_values(path, prefix):
    """Return {value: human_name} for enum entries PREFIX_NAME = value."""
    result = {}
    try:
        text = open(f"{ROOT}/{path}").read()
    except FileNotFoundError:
        return result
    for m in re.finditer(rf"\b{re.escape(prefix)}(\w+)\s*=\s*(\d+)", text):
        name, val = m.group(1), int(m.group(2))
        if val not in result:
            result[val] = title(name)
    return result


def const_to_int(s, lookup_by_name):
    """Convert a constant string like SPECIES_LUCARIO to its int, or None."""
    m = re.match(r"(\w+)", s)
    if not m:
        return None
    return lookup_by_name.get(m.group(1))


def build_name_lookup(value_to_name):
    """Invert {value: name} to {PREFIXED_CONST_NAME: value} — not needed here,
    but we also want {PREFIXED_NAME: human_name} for species/moves."""
    return {v: k for k, v in value_to_name.items()}


# ── Build constant lookups ────────────────────────────────────────────────────

species_by_val = parse_defines("include/constants/species.h", "SPECIES_")
move_by_val    = parse_defines("include/constants/moves.h",   "MOVE_")
item_by_val    = parse_defines("include/constants/items.h",   "ITEM_")

# Reverse maps: CONST_STRING -> human name (no prefix)
def make_reverse(path, prefix):
    result = {}
    try:
        text = open(f"{ROOT}/{path}").read()
    except FileNotFoundError:
        return result
    for m in re.finditer(rf"#define\s+({re.escape(prefix)}\w+)\s+(\d+)", text):
        const, val = m.group(1), int(m.group(2))
        human = title(const[len(prefix):])
        if const not in result:
            result[const] = human
    return result

species_name = make_reverse("include/constants/species.h", "SPECIES_")
move_name    = make_reverse("include/constants/moves.h",   "MOVE_")
item_name    = make_reverse("include/constants/items.h",   "ITEM_")

# Class names
trainer_class_name = make_reverse("include/constants/trainers.h", "TRAINER_CLASS_")


# ── Parse trainer_parties.h ───────────────────────────────────────────────────

def parse_parties(path):
    """Return {party_name: {"type": str, "mons": [dict]}}"""
    text = open(f"{ROOT}/{path}").read()
    parties = {}

    # Match each static const struct ... sParty_X[] = { ... };
    # The body may span many lines and contain nested braces for each mon.
    party_pat = re.compile(
        r"static\s+const\s+struct\s+(Trainer\w+)\s+(sParty_\w+)\s*\[\s*\]\s*=\s*\{(.*?)\};",
        re.DOTALL,
    )

    for m in party_pat.finditer(text):
        struct_type = m.group(1)
        party_name  = m.group(2)
        body        = m.group(3)

        has_custom_moves = "CustomMoves"  in struct_type
        has_item         = "Item"         in struct_type and "NoItem" not in struct_type

        # Split body into per-mon blocks by top-level { }
        mons = []
        depth = 0
        mon_start = None
        for i, ch in enumerate(body):
            if ch == "{":
                if depth == 0:
                    mon_start = i + 1
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0 and mon_start is not None:
                    mon_body = body[mon_start:i]
                    mon = parse_mon(mon_body, has_custom_moves, has_item)
                    if mon:
                        mons.append(mon)
                    mon_start = None

        parties[party_name] = {
            "type": struct_type,
            "has_custom_moves": has_custom_moves,
            "has_item": has_item,
            "mons": mons,
        }

    return parties


def parse_mon(body, has_custom_moves, has_item):
    """Extract fields from a single mon body string."""
    mon = {}

    m = re.search(r"\.species\s*=\s*(\w+)", body)
    if not m:
        return None
    mon["species"] = species_name.get(m.group(1), title(m.group(1)[len("SPECIES_"):] if m.group(1).startswith("SPECIES_") else m.group(1)))

    m = re.search(r"\.lvl\s*=\s*(\d+)", body)
    mon["lvl"] = int(m.group(1)) if m else "?"

    if has_item:
        m = re.search(r"\.heldItem\s*=\s*(\w+)", body)
        mon["item"] = item_name.get(m.group(1), "?") if m else "—"
    else:
        mon["item"] = "—"

    if has_custom_moves:
        m = re.search(r"\.moves\s*=\s*\{([^}]+)\}", body)
        if m:
            raw_moves = [x.strip() for x in m.group(1).split(",")]
            mon["moves"] = [move_name.get(mv, title(mv[len("MOVE_"):] if mv.startswith("MOVE_") else mv)) for mv in raw_moves if mv]
        else:
            mon["moves"] = []
    else:
        mon["moves"] = None  # default moves

    return mon


# ── Parse trainers.h ──────────────────────────────────────────────────────────

AI_FLAGS = {
    "AI_SCRIPT_CHECK_BAD_MOVE":   "CheckBad",
    "AI_SCRIPT_TRY_TO_FAINT":     "TryFaint",
    "AI_SCRIPT_CHECK_VIABILITY":  "CheckViab",
    "AI_SCRIPT_SETUP_FIRST_TURN": "Setup",
    "AI_SCRIPT_RISKY":            "Risky",
}


def parse_trainers(path):
    """Return list of trainer dicts."""
    text = open(f"{ROOT}/{path}").read()
    trainers = []

    # Match each [TRAINER_X] = { ... }, block
    block_pat = re.compile(
        r"\[(\w+)\]\s*=\s*\{(.*?)\},\s*(?=\[|\Z)",
        re.DOTALL,
    )

    for m in block_pat.finditer(text):
        trainer_id = m.group(1)
        body = m.group(2)

        if trainer_id == "TRAINER_NONE":
            continue

        t = {"id": trainer_id}

        nm = re.search(r'\.trainerName\s*=\s*_\("([^"]*)"\)', body)
        t["name"] = nm.group(1) if nm else ""

        cm = re.search(r"\.trainerClass\s*=\s*(\w+)", body)
        raw_class = cm.group(1) if cm else ""
        t["class_raw"] = raw_class
        t["class"] = trainer_class_name.get(raw_class, title(raw_class[len("TRAINER_CLASS_"):] if raw_class.startswith("TRAINER_CLASS_") else raw_class))

        # Items bag
        im = re.search(r"\.items\s*=\s*\{([^}]*)\}", body)
        if im:
            raw_items = [x.strip() for x in im.group(1).split(",") if x.strip() and x.strip() != "0"]
            items = [item_name.get(i, i) for i in raw_items if i and i != "ITEM_NONE"]
            t["bag"] = items
        else:
            t["bag"] = []

        # AI flags
        ai_m = re.search(r"\.aiFlags\s*=\s*([^\n,]+)", body)
        ai_str = ai_m.group(1).strip() if ai_m else ""
        active_ai = [short for long, short in AI_FLAGS.items() if long in ai_str]
        t["ai"] = " | ".join(active_ai) if active_ai else "—"

        # Party
        pm = re.search(r"\.party\s*=\s*(\w+)\((\w+)\)", body)
        if pm:
            t["party_macro"] = pm.group(1)
            t["party_name"]  = pm.group(2)
            t["has_custom_moves"] = "CUSTOM_MOVES" in pm.group(1)
        else:
            t["party_macro"] = ""
            t["party_name"]  = ""
            t["has_custom_moves"] = False

        trainers.append(t)

    return trainers


# ── Tier classification ────────────────────────────────────────────────────────

def classify_tier(t):
    cls = t["class_raw"]
    tid = t["id"]
    name = t["name"].upper()

    if "CHAMPION" in cls or name == "CYNTHIA":
        return 0  # Champions / Post-game
    if "ELITE_FOUR" in cls:
        return 1
    if "LEADER" in cls and "TEAM" not in cls:
        return 2  # Gym Leaders
    if "RIVAL" in cls:
        return 3
    if "Npc" in t.get("party_name", "") or t["id"].startswith("TRAINER_NPC"):
        return 4  # Phase D NPCs
    return 5  # Other custom-move trainers


TIER_HEADERS = [
    "## CHAMPIONS / POST-GAME",
    "## ELITE FOUR",
    "## GYM LEADERS",
    "## RIVALS",
    "## PHASE D NPCs (custom moves)",
    "## OTHER CUSTOM-MOVESET TRAINERS",
]

# ── Step 5 species set (for flagging default-move trainers) ───────────────────
STEP5_MIN = 416  # SPECIES_SHINX onwards

def party_has_step5(party_data):
    if not party_data:
        return False
    # We only have human names at this point, so check original species constants
    return False  # handled separately below


# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    parties  = parse_parties("src/data/trainer_parties.h")
    trainers = parse_trainers("src/data/trainers.h")

    # Build species-constant -> int lookup for Step 5 detection
    species_const_to_val = {}
    try:
        text = open(f"{ROOT}/include/constants/species.h").read()
        for m in re.finditer(r"#define\s+(SPECIES_\w+)\s+(\d+)", text):
            species_const_to_val[m.group(1)] = int(m.group(2))
    except FileNotFoundError:
        pass

    # Re-parse parties keeping raw species constants for Step 5 detection
    raw_species_in_party = {}
    try:
        text = open(f"{ROOT}/src/data/trainer_parties.h").read()
        party_pat = re.compile(
            r"static\s+const\s+struct\s+Trainer\w+\s+(sParty_\w+)\s*\[\s*\]\s*=\s*\{(.*?)\};",
            re.DOTALL,
        )
        for m in party_pat.finditer(text):
            pname = m.group(1)
            raw_species_in_party[pname] = re.findall(r"\.species\s*=\s*(\w+)", m.group(2))
    except FileNotFoundError:
        pass

    def party_uses_step5(party_name):
        for sp in raw_species_in_party.get(party_name, []):
            val = species_const_to_val.get(sp, 0)
            if val >= STEP5_MIN:
                return True
        return False

    # Group trainers by tier — only include custom-move trainers
    # (plus default-move trainers that use Step 5 species)
    tiers = defaultdict(list)
    for t in trainers:
        party = parties.get(t["party_name"])
        if not party:
            continue
        if not t["has_custom_moves"] and not party_uses_step5(t["party_name"]):
            continue
        tier = classify_tier(t)
        tiers[tier].append((t, party))

    print("# Trainer Review — Cynthia's Crown\n")
    print(f"_Custom-moveset trainers and default-move trainers with new (Step 5) species._\n")

    total = sum(len(v) for v in tiers.values())
    print(f"**{total} trainers shown**\n")

    for tier_idx in sorted(tiers.keys()):
        entries = tiers[tier_idx]
        if not entries:
            continue
        print(TIER_HEADERS[tier_idx])
        print()

        for t, party in entries:
            display_name = t["name"] or t["id"]
            bag_str = ""
            if t["bag"]:
                from collections import Counter
                counts = Counter(t["bag"])
                bag_str = "  Bag: " + ", ".join(
                    f"{name} ×{cnt}" if cnt > 1 else name
                    for name, cnt in counts.items()
                )

            print(f"### {display_name} [{t['id']}] — {t['class']} — AI: {t['ai']}")
            if bag_str:
                print(bag_str)

            for i, mon in enumerate(party["mons"], 1):
                sp   = mon["species"]
                lvl  = mon["lvl"]
                item = mon["item"]
                item_str = f"  Item:{item}" if item != "—" else ""

                if mon["moves"] is not None:
                    moves_str = " / ".join(mon["moves"])
                else:
                    moves_str = "_(default moves)_"

                print(f"{i}. {sp:<18} Lv{lvl:<4}{item_str:<18}  {moves_str}")

            print()


if __name__ == "__main__":
    main()
