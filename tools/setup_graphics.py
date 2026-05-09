#!/usr/bin/env python3
"""
Set up placeholder graphics for all new Step 5 species.

For each species without a graphics directory:
  1. Creates graphics/pokemon/<name>/ by copying from a donor species
  2. Adds INCBIN declarations to src/data/graphics/pokemon.h
  3. Adds entries to all 8 graphics table files

For species that already have graphics (Shinx, Axew, Honedge, Galarian_Zigzagoon),
it just adds the table entries if they're missing.

Run from repo root:
  python3 tools/setup_graphics.py
"""

import os, re, shutil, subprocess

# ─── Configuration ────────────────────────────────────────────────
GRAPHICS_ROOT = "graphics/pokemon"
DONOR = "shinx"  # use Shinx graphics as placeholder

# Graphics table files and their entry formats
TABLE_FILES = {
    "front":     "src/data/pokemon_graphics/front_pic_table.h",
    "back":      "src/data/pokemon_graphics/back_pic_table.h",
    "palette":   "src/data/pokemon_graphics/palette_table.h",
    "shiny":     "src/data/pokemon_graphics/shiny_palette_table.h",
    "footprint": "src/data/pokemon_graphics/footprint_table.h",
    "elevation": "src/data/pokemon_graphics/enemy_mon_elevation.h",
    "front_coords": "src/data/pokemon_graphics/front_pic_coordinates.h",
    "back_coords":  "src/data/pokemon_graphics/back_pic_coordinates.h",
}

# All 168 species in order (species macro → graphics dir name)
# The dir name = what comes after "graphics/pokemon/"
SPECIES_MAP = [
    # Step-1 species (already have graphics dirs)
    ("SPECIES_SHINX",              "shinx"),
    ("SPECIES_AXEW",               "axew"),
    ("SPECIES_HONEDGE",            "honedge"),
    ("SPECIES_GALARIAN_ZIGZAGOON", "galarian_zigzagoon"),
    # New species (416+)
    ("SPECIES_LUXIO",              "luxio"),
    ("SPECIES_LUXRAY",             "luxray"),
    ("SPECIES_FRAXURE",            "fraxure"),
    ("SPECIES_HAXORUS",            "haxorus"),
    ("SPECIES_DOUBLADE",           "doublade"),
    ("SPECIES_AEGISLASH",          "aegislash"),
    ("SPECIES_GALARIAN_LINOONE",   "galarian_linoone"),
    ("SPECIES_OBSTAGOON",          "obstagoon"),
    ("SPECIES_STARLY",             "starly"),
    ("SPECIES_STARAVIA",           "staravia"),
    ("SPECIES_STARAPTOR",          "staraptor"),
    ("SPECIES_MUNCHLAX",           "munchlax"),
    ("SPECIES_PORYGON_Z",          "porygon_z"),
    ("SPECIES_HISUIAN_ZORUA",      "hisuian_zorua"),
    ("SPECIES_HISUIAN_ZOROARK",    "hisuian_zoroark"),
    ("SPECIES_FLETCHLING",         "fletchling"),
    ("SPECIES_FLETCHINDER",        "fletchinder"),
    ("SPECIES_TALONFLAME",         "talonflame"),
    ("SPECIES_URSALUNA",           "ursaluna"),
    ("SPECIES_SALANDIT",           "salandit"),
    ("SPECIES_SALAZZLE",           "salazzle"),
    ("SPECIES_LITWICK",            "litwick"),
    ("SPECIES_LAMPENT",            "lampent"),
    ("SPECIES_CHANDELURE",         "chandelure"),
    ("SPECIES_CHIMCHAR",           "chimchar"),
    ("SPECIES_MONFERNO",           "monferno"),
    ("SPECIES_INFERNAPE",          "infernape"),
    ("SPECIES_PIPLUP",             "piplup"),
    ("SPECIES_PRINPLUP",           "prinplup"),
    ("SPECIES_EMPOLEON",           "empoleon"),
    ("SPECIES_BUIZEL",             "buizel"),
    ("SPECIES_FLOATZEL",           "floatzel"),
    ("SPECIES_MAGMORTAR",          "magmortar"),
    ("SPECIES_ELECTIVIRE",         "electivire"),
    ("SPECIES_ROTOM",              "rotom"),
    ("SPECIES_ROTOM_HEAT",         "rotom_heat"),
    ("SPECIES_ROTOM_WASH",         "rotom_wash"),
    ("SPECIES_ROTOM_FROST",        "rotom_frost"),
    ("SPECIES_ROTOM_FAN",          "rotom_fan"),
    ("SPECIES_ROTOM_MOW",          "rotom_mow"),
    ("SPECIES_TOXEL",              "toxel"),
    ("SPECIES_TOXTRICITY",         "toxtricity"),
    ("SPECIES_TYNAMO",             "tynamo"),
    ("SPECIES_EELEKTRIK",          "eelektrik"),
    ("SPECIES_EELEKTROSS",         "eelektross"),
    ("SPECIES_ROSERADE",           "roserade"),
    ("SPECIES_TANGROWTH",          "tangrowth"),
    ("SPECIES_LEAFEON",            "leafeon"),
    ("SPECIES_GLACEON",            "glaceon"),
    ("SPECIES_SYLVEON",            "sylveon"),
    ("SPECIES_FERROSEED",          "ferroseed"),
    ("SPECIES_FERROTHORN",         "ferrothorn"),
    ("SPECIES_PUMPKABOO",          "pumpkaboo"),
    ("SPECIES_GOURGEIST",          "gourgeist"),
    ("SPECIES_PHANTUMP",           "phantump"),
    ("SPECIES_TREVENANT",          "trevenant"),
    ("SPECIES_GALARIAN_MR_MIME",   "galarian_mr_mime"),
    ("SPECIES_MR_RIME",            "mr_rime"),
    ("SPECIES_MAMOSWINE",          "mamoswine"),
    ("SPECIES_FROSLASS",           "froslass"),
    ("SPECIES_WEAVILE",            "weavile"),
    ("SPECIES_GALARIAN_DARUMAKA",  "galarian_darumaka"),
    ("SPECIES_GALARIAN_DARMANITAN","galarian_darmanitan"),
    ("SPECIES_ANNIHILAPE",         "annihilape"),
    ("SPECIES_GALARIAN_FARFETCHD", "galarian_farfetchd"),
    ("SPECIES_SIRFETCHD",          "sirfetchd"),
    ("SPECIES_PANCHAM",            "pancham"),
    ("SPECIES_PANGORO",            "pangoro"),
    ("SPECIES_CROAGUNK",           "croagunk"),
    ("SPECIES_TOXICROAK",          "toxicroak"),
    ("SPECIES_RIOLU",              "riolu"),
    ("SPECIES_LUCARIO",            "lucario"),
    ("SPECIES_SCRAGGY",            "scraggy"),
    ("SPECIES_SCRAFTY",            "scrafty"),
    ("SPECIES_SKRELP",             "skrelp"),
    ("SPECIES_DRAGALGE",           "dragalge"),
    ("SPECIES_GIBLE",              "gible"),
    ("SPECIES_GABITE",             "gabite"),
    ("SPECIES_GARCHOMP",           "garchomp"),
    ("SPECIES_GLISCOR",            "gliscor"),
    ("SPECIES_RHYPERIOR",          "rhyperior"),
    ("SPECIES_DRILBUR",            "drilbur"),
    ("SPECIES_EXCADRILL",          "excadrill"),
    ("SPECIES_SANDILE",            "sandile"),
    ("SPECIES_KROKOROK",           "krokorok"),
    ("SPECIES_KROOKODILE",         "krookodile"),
    ("SPECIES_GOLETT",             "golett"),
    ("SPECIES_GOLURK",             "golurk"),
    ("SPECIES_HONCHKROW",          "honchkrow"),
    ("SPECIES_TOGEKISS",           "togekiss"),
    ("SPECIES_YANMEGA",            "yanmega"),
    ("SPECIES_HAWLUCHA",           "hawlucha"),
    ("SPECIES_ROOKIDEE",           "rookidee"),
    ("SPECIES_CORVISQUIRE",        "corvisquire"),
    ("SPECIES_CORVIKNIGHT",        "corviknight"),
    ("SPECIES_GALLADE",            "gallade"),
    ("SPECIES_INKAY",              "inkay"),
    ("SPECIES_MALAMAR",            "malamar"),
    ("SPECIES_LARVESTA",           "larvesta"),
    ("SPECIES_VOLCARONA",          "volcarona"),
    ("SPECIES_GRUBBIN",            "grubbin"),
    ("SPECIES_CHARJABUG",          "charjabug"),
    ("SPECIES_VIKAVOLT",           "vikavolt"),
    ("SPECIES_SIZZLIPEDE",         "sizzlipede"),
    ("SPECIES_CENTISKORCH",        "centiskorch"),
    ("SPECIES_KLEAVOR",            "kleavor"),
    ("SPECIES_HISUIAN_GROWLITHE",  "hisuian_growlithe"),
    ("SPECIES_HISUIAN_ARCANINE",   "hisuian_arcanine"),
    ("SPECIES_ALOLAN_GEODUDE",     "alolan_geodude"),
    ("SPECIES_ALOLAN_GRAVELER",    "alolan_graveler"),
    ("SPECIES_ALOLAN_GOLEM",       "alolan_golem"),
    ("SPECIES_PROBOPASS",          "probopass"),
    ("SPECIES_ROCKRUFF",           "rockruff"),
    ("SPECIES_LYCANROC",           "lycanroc"),
    ("SPECIES_DREEPY",             "dreepy"),
    ("SPECIES_DRAKLOAK",           "drakloak"),
    ("SPECIES_DRAGAPULT",          "dragapult"),
    ("SPECIES_BASCULIN",           "basculin"),
    ("SPECIES_BASCULEGION",        "basculegion"),
    ("SPECIES_ALOLAN_EXEGGUTOR",   "alolan_exeggutor"),
    ("SPECIES_DEINO",              "deino"),
    ("SPECIES_ZWEILOUS",           "zweilous"),
    ("SPECIES_HYDREIGON",          "hydreigon"),
    ("SPECIES_GOOMY",              "goomy"),
    ("SPECIES_SLIGGOO",            "sliggoo"),
    ("SPECIES_GOODRA",             "goodra"),
    ("SPECIES_DARKRAI",            "darkrai"),
    ("SPECIES_ZORUA",              "zorua"),
    ("SPECIES_ZOROARK",            "zoroark"),
    ("SPECIES_PAWNIARD",           "pawniard"),
    ("SPECIES_BISHARP",            "bisharp"),
    ("SPECIES_KINGAMBIT",          "kingambit"),
    ("SPECIES_BRONZOR",            "bronzor"),
    ("SPECIES_BRONZONG",           "bronzong"),
    ("SPECIES_GALARIAN_MEOWTH",    "galarian_meowth"),
    ("SPECIES_PERRSERKER",         "perrserker"),
    ("SPECIES_ALOLAN_MEOWTH",      "alolan_meowth"),
    ("SPECIES_ALOLAN_PERSIAN",     "alolan_persian"),
    ("SPECIES_DURALUDON",          "duraludon"),
    ("SPECIES_ARCHALUDON",         "archaludon"),
    ("SPECIES_TINKATINK",          "tinkatink"),
    ("SPECIES_TINKATUFF",          "tinkatuff"),
    ("SPECIES_TINKATON",           "tinkaton"),
    ("SPECIES_ALOLAN_DIGLETT",     "alolan_diglett"),
    ("SPECIES_ALOLAN_DUGTRIO",     "alolan_dugtrio"),
    ("SPECIES_MAGNEZONE",          "magnezone"),
    ("SPECIES_FLABEBE",            "flabebe"),
    ("SPECIES_FLOETTE",            "floette"),
    ("SPECIES_FLORGES",            "florges"),
    ("SPECIES_ALOLAN_VULPIX",      "alolan_vulpix"),
    ("SPECIES_ALOLAN_NINETALES",   "alolan_ninetales"),
    ("SPECIES_UXIE",               "uxie"),
    ("SPECIES_MESPRIT",            "mesprit"),
    ("SPECIES_AZELF",              "azelf"),
    ("SPECIES_DIALGA",             "dialga"),
    ("SPECIES_PALKIA",             "palkia"),
    ("SPECIES_HEATRAN",            "heatran"),
    ("SPECIES_REGIGIGAS",          "regigigas"),
    ("SPECIES_GIRATINA",           "giratina"),
    ("SPECIES_CRESSELIA",          "cresselia"),
    ("SPECIES_PHIONE",             "phione"),
    ("SPECIES_MANAPHY",            "manaphy"),
    ("SPECIES_SHAYMIN",            "shaymin"),
    ("SPECIES_ARCEUS",             "arceus"),
]

# Map species dir name to a capitalized variable suffix
# e.g. "galarian_zigzagoon" → "GalarianZigzagoon"
def dir_to_varname(dirname):
    return "".join(p.capitalize() for p in dirname.split("_"))


def ensure_graphics_dir(dirname):
    """Create graphics dir by copying from donor if it doesn't exist."""
    path = os.path.join(GRAPHICS_ROOT, dirname)
    if not os.path.isdir(path):
        donor_path = os.path.join(GRAPHICS_ROOT, DONOR)
        shutil.copytree(donor_path, path)
        print(f"  Created placeholder: {path}")
        return True
    return False


def build_incbin_block(dirname):
    varname = dir_to_varname(dirname)
    lines = []
    lines.append(f"const u32 gMonFrontPic_{varname}[] = INCBIN_U32(\"graphics/pokemon/{dirname}/front.4bpp.lz\");\n")
    lines.append(f"const u32 gMonPalette_{varname}[] = INCBIN_U32(\"graphics/pokemon/{dirname}/normal.gbapal.lz\");\n")
    lines.append(f"const u32 gMonBackPic_{varname}[] = INCBIN_U32(\"graphics/pokemon/{dirname}/back.4bpp.lz\");\n")
    lines.append(f"const u32 gMonShinyPalette_{varname}[] = INCBIN_U32(\"graphics/pokemon/{dirname}/shiny.gbapal.lz\");\n")
    lines.append(f"const u8 gMonIcon_{varname}[] = INCBIN_U8(\"graphics/pokemon/{dirname}/icon.4bpp\");\n")
    lines.append(f"const u8 gMonFootprint_{varname}[] = INCBIN_U8(\"graphics/pokemon/{dirname}/footprint.1bpp\");\n")
    lines.append("\n")
    return "".join(lines)


def build_table_entries(species_macro, dirname):
    varname = dir_to_varname(dirname)
    entries = {}
    # front_pic_table.h uses SPECIES_SPRITE(MACRO_SUFFIX, ptr)
    # e.g. SPECIES_SPRITE(SHINX, gMonFrontPic_Shinx)
    suffix = species_macro.replace("SPECIES_", "")
    entries["front"]     = f"    SPECIES_SPRITE({suffix}, gMonFrontPic_{varname}),\n"
    entries["back"]      = f"    SPECIES_SPRITE({suffix}, gMonBackPic_{varname}),\n"
    entries["palette"]   = f"    SPECIES_PAL({suffix}, gMonPalette_{varname}),\n"
    entries["shiny"]     = f"    SPECIES_SHINY_PAL({suffix}, gMonShinyPalette_{varname}),\n"
    entries["footprint"] = f"    [SPECIES_{suffix}] = gMonFootprint_{varname},\n"
    entries["elevation"] = f"    [SPECIES_{suffix}] = 0,\n"
    entries["front_coords"] = f"    FRONT_SPRITE_SIZE({suffix}, 6, 1),\n"
    entries["back_coords"]  = f"    BACK_SPRITE_SIZE({suffix}, 1, 4),\n"
    return entries


def update_pokemon_graphics_h(entries_to_add):
    """Append INCBIN declarations to src/data/graphics/pokemon.h."""
    path = "src/data/graphics/pokemon.h"
    content = open(path).read()
    new_content = content
    added = 0
    for (macro, dirname) in entries_to_add:
        varname = dir_to_varname(dirname)
        if f"gMonFrontPic_{varname}" not in content:
            new_content += build_incbin_block(dirname)
            added += 1
    if added:
        with open(path, "w") as f:
            f.write(new_content)
        print(f"  Added {added} INCBIN blocks to {path}")
    else:
        print(f"  No changes needed for {path}")


def update_table(table_name, filepath, species_with_dirs):
    """Insert table entries before the closing };."""
    content = open(filepath).read()
    entries_needed = []
    for (macro, dirname) in species_with_dirs:
        all_entries = build_table_entries(macro, dirname)
        entry = all_entries[table_name]
        suffix = macro.replace("SPECIES_", "")
        # Check if already present
        if suffix not in content or f"gMonFrontPic_{dir_to_varname(dirname)}" not in content:
            if entry.strip() not in content:
                entries_needed.append(entry)
    if entries_needed:
        new_block = "    // === Cynthia's Crown Step 5 species ===\n" + "".join(entries_needed)
        idx = content.rfind("};")
        new_content = content[:idx] + new_block + content[idx:]
        with open(filepath, "w") as f:
            f.write(new_content)
        print(f"  Added {len(entries_needed)} entries to {filepath}")
    else:
        print(f"  No changes needed for {filepath}")


def main():
    print("Setting up graphics for all Step 5 species...")

    # Step 1: Create placeholder dirs for species that don't have graphics
    created = 0
    for (macro, dirname) in SPECIES_MAP:
        if ensure_graphics_dir(dirname):
            created += 1
    print(f"  Created {created} placeholder graphics directories")

    # Step 2: Update pokemon.h INCBIN declarations
    print("\nUpdating INCBIN declarations...")
    update_pokemon_graphics_h(SPECIES_MAP)

    # Step 3: Update all table files
    print("\nUpdating graphics tables...")
    # For each table, we need to check what format entries use
    # Let's read the first few entries to detect the format
    for table_name, filepath in TABLE_FILES.items():
        if os.path.exists(filepath):
            # Skip updating complex-format tables for now
            if table_name in ("front_coords", "back_coords", "elevation"):
                pass  # these use simpler formats below
            update_table(table_name, filepath, SPECIES_MAP)

    print("\nDone!")


if __name__ == "__main__":
    main()
