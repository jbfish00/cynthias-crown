#!/usr/bin/env python3
"""
Extract Gen 9 learnsets from DPE source and update FR learnset arrays.

For each Step 5 species: look up its DPE learnset array, filter to FR-valid
move names, and replace the existing array body in level_up_learnsets.h.

Rotom forms have no separate DPE learnsets → use base Rotom.
Galarian Mr. Mime has no DPE learnset → use base MrMime.
"""

import re

FR_MOVES_H    = "include/constants/moves.h"
DPE_LEARNSETS = "/dev/shm/dpe/src/Learnsets.c"
FR_LEARNSETS  = "src/data/pokemon/level_up_learnsets.h"

# FR array name prefix → DPE learnset species name
# Keys must match exactly: s{KEY}LevelUpLearnset in the FR file
SPECIES_TO_DPE = {
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
    "Basculin":           "BasculinRed",
    "Basculegion":        "BasculegionM",
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
    "GalarianZigzagoon":  "GalarianZigzagoon",
    "GalarianLinoone":    "GalarianLinoone",
    "GalarianMeowth":     "GalarianMeowth",
    "GalarianMrMime":     "MrMime",           # no GalarianMrMime in DPE → use base
    "GalarianFarfetchd":  "GalarianFarfetchd",
    "GalarianDarumaka":   "GalarianDarumaka",
    "GalarianDarmanitan": "GalarianDarmanitan",
    # Alolan forms
    "AlolanMeowth":       "AlolanMeowth",
    "AlolanPersian":      "AlolanPersian",
    "AlolanDiglett":      "AlolanDiglett",
    "AlolanDugtrio":      "AlolanDugtrio",
    "AlolanGeodude":      "AlolanGeodude",
    "AlolanGraveler":     "AlolanGraveler",
    "AlolanGolem":        "AlolanGolem",
    "AlolanVulpix":       "AlolanVulpix",
    "AlolanNinetales":    "AlolanNinetales",
    "AlolanExeggutor":    "AlolanExeggutor",
    # Hisuian forms
    "HisuianZorua":       "ZoruaH",
    "HisuianZoroark":     "ZoroarkH",
    "HisuianGrowlithe":   "GrowlitheH",
    "HisuianArcanine":    "ArcanineH",
}


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


def translate_move(dpe_move, fr_move_set):
    """Translate DPE move name to FR move name, or None if not in FR."""
    normalized = dpe_move.replace("_", "").upper()
    return fr_move_set.get(normalized)


def build_learnset_body(moves, fr_move_set):
    """Build learnset array body from list of (level, dpe_move_name)."""
    lines = []
    seen = set()
    for level, dpe_move in moves:
        fr_move = translate_move(dpe_move, fr_move_set)
        if fr_move is None:
            continue
        key = (level, fr_move)
        if key in seen:
            continue
        seen.add(key)
        lines.append(f"    LEVEL_UP_MOVE({level}, {fr_move}),")
    lines.append("    LEVEL_UP_END")
    return "\n".join(lines)


def update_learnsets(fr_learnsets_path, species_to_dpe, dpe_learnsets, fr_move_set):
    with open(fr_learnsets_path) as f:
        content = f.read()

    updated = 0
    skipped = []

    for fr_name, dpe_name in species_to_dpe.items():
        dpe_moves = dpe_learnsets.get(dpe_name)
        if dpe_moves is None:
            skipped.append(f"{fr_name} → {dpe_name} (not in DPE)")
            continue

        array_name = f"s{fr_name}LevelUpLearnset"
        pattern = re.compile(
            r'(static const u16 ' + re.escape(array_name) + r'\[\]\s*=\s*\{)[^}]*(})',
            re.DOTALL
        )
        new_body = build_learnset_body(dpe_moves, fr_move_set)
        replacement = r'\g<1>' + '\n' + new_body + '\n' + r'\g<2>'

        new_content, n = pattern.subn(replacement, content)
        if n == 0:
            skipped.append(f"{fr_name} → array '{array_name}' not found in FR file")
        else:
            content = new_content
            updated += 1

    with open(fr_learnsets_path, "w") as f:
        f.write(content)

    print(f"Updated {updated} learnsets.")
    if skipped:
        print(f"\nSkipped ({len(skipped)}):")
        for s in skipped:
            print(f"  {s}")


def main():
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

    update_learnsets(FR_LEARNSETS, SPECIES_TO_DPE, dpe_learnsets, fr_move_set)


if __name__ == "__main__":
    main()
