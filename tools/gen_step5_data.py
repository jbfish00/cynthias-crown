#!/usr/bin/env python3
"""
Generate missing Step 5 data for new species (416-579):
  - src/data/pokemon/level_up_learnsets.h  (appended)
  - src/data/pokemon/level_up_learnset_pointers.h  (modified closing })
  - src/data/pokemon/tmhm_learnsets.h  (modified closing })
  - src/data/pokemon/pokedex_entries.h  (modified closing })
  - src/data/pokemon/pokedex_text_fr.h  (appended)
  - src/data/pokemon/pokedex_text_lg.h  (appended)

Run from repo root:
  python3 tools/gen_step5_data.py
"""

import re

# ─────────────────────────────────────────────────────────
# Species data: macro → (name_str, type1, type2, category, height_dm, weight_hg, gen_stage)
# type strings match GEN3 TYPE_XXX constants; gen_stage is 1/2/3 (evo stage, for learnset scaling)
# ─────────────────────────────────────────────────────────
SPECIES = [
    # Step-1 evolutions
    ("SPECIES_LUXIO",              "Luxio",              "ELECTRIC","ELECTRIC","Spark",           5, 305, 2),
    ("SPECIES_LUXRAY",             "Luxray",             "ELECTRIC","ELECTRIC","Gleam Eyes",       11,420, 3),
    ("SPECIES_FRAXURE",            "Fraxure",            "DRAGON",  "DRAGON",  "Axe Jaw",          10,360, 2),
    ("SPECIES_HAXORUS",            "Haxorus",            "DRAGON",  "DRAGON",  "Axe Jaw",          18,1055,3),
    ("SPECIES_DOUBLADE",           "Doublade",           "STEEL",   "GHOST",   "Sword",            5, 45,  2),
    ("SPECIES_AEGISLASH",          "Aegislash",          "STEEL",   "GHOST",   "Royal Sword",      17,530, 3),
    ("SPECIES_GALARIAN_LINOONE",   "Linoone-G",          "DARK",    "NORMAL",  "Rushing",          5, 325, 2),
    ("SPECIES_OBSTAGOON",          "Obstagoon",          "DARK",    "NORMAL",  "Blocking",         16,460, 3),
    # Starly line
    ("SPECIES_STARLY",             "Starly",             "NORMAL",  "FLYING",  "Starling",         3, 20,  1),
    ("SPECIES_STARAVIA",           "Staravia",           "NORMAL",  "FLYING",  "Starling",         6, 155, 2),
    ("SPECIES_STARAPTOR",          "Staraptor",          "NORMAL",  "FLYING",  "Predator",         12,249, 3),
    # Gen 4 misc
    ("SPECIES_MUNCHLAX",           "Munchlax",           "NORMAL",  "NORMAL",  "Big Eater",        6, 1050,1),
    ("SPECIES_PORYGON_Z",          "Porygon-Z",          "NORMAL",  "NORMAL",  "Virtual",          9, 340, 3),
    # Hisuian Zorua line
    ("SPECIES_HISUIAN_ZORUA",      "Zorua-H",            "NORMAL",  "GHOST",   "Tricky Fox",       7, 125, 1),
    ("SPECIES_HISUIAN_ZOROARK",    "Zoroark-H",          "NORMAL",  "GHOST",   "Illusion Fox",     16,731, 2),
    # Fletchling line
    ("SPECIES_FLETCHLING",         "Fletchling",         "NORMAL",  "FLYING",  "Tiny Robin",       3, 17,  1),
    ("SPECIES_FLETCHINDER",        "Fletchinder",        "FIRE",    "FLYING",  "Ember Bird",       7, 160, 2),
    ("SPECIES_TALONFLAME",         "Talonflame",         "FIRE",    "FLYING",  "Scorching",        12,193, 3),
    # Ursaluna
    ("SPECIES_URSALUNA",           "Ursaluna",           "GROUND",  "NORMAL",  "Peat",             24,3000,3),
    # Salandit line
    ("SPECIES_SALANDIT",           "Salandit",           "POISON",  "FIRE",    "Toxic Lizard",     6, 48,  1),
    ("SPECIES_SALAZZLE",           "Salazzle",           "POISON",  "FIRE",    "Toxic Lizard",     12,222, 2),
    # Litwick line
    ("SPECIES_LITWICK",            "Litwick",            "GHOST",   "FIRE",    "Candle",           3, 31,  1),
    ("SPECIES_LAMPENT",            "Lampent",            "GHOST",   "FIRE",    "Lamp",             6, 130, 2),
    ("SPECIES_CHANDELURE",         "Chandelure",         "GHOST",   "FIRE",    "Luring",           10,343, 3),
    # Chimchar line
    ("SPECIES_CHIMCHAR",           "Chimchar",           "FIRE",    "FIRE",    "Chimp",            5, 62,  1),
    ("SPECIES_MONFERNO",           "Monferno",           "FIRE",    "FIGHTING","Playful",          9, 220, 2),
    ("SPECIES_INFERNAPE",          "Infernape",          "FIRE",    "FIGHTING","Flame",            12,550, 3),
    # Piplup line
    ("SPECIES_PIPLUP",             "Piplup",             "WATER",   "WATER",   "Penguin",          4, 52,  1),
    ("SPECIES_PRINPLUP",           "Prinplup",           "WATER",   "WATER",   "Penguin",          8, 232, 2),
    ("SPECIES_EMPOLEON",           "Empoleon",           "WATER",   "STEEL",   "Emperor",          17,844, 3),
    # Buizel line
    ("SPECIES_BUIZEL",             "Buizel",             "WATER",   "WATER",   "Sea Weasel",       7, 295, 1),
    ("SPECIES_FLOATZEL",           "Floatzel",           "WATER",   "WATER",   "Sea Weasel",       11,335, 2),
    # Trade evolutions
    ("SPECIES_MAGMORTAR",          "Magmortar",          "FIRE",    "FIRE",    "Blast",            16,680, 3),
    ("SPECIES_ELECTIVIRE",         "Electivire",         "ELECTRIC","ELECTRIC","Thunderbolt",      18,1386,3),
    # Rotom forms
    ("SPECIES_ROTOM",              "Rotom",              "ELECTRIC","GHOST",   "Plasma",           3, 3,   1),
    ("SPECIES_ROTOM_HEAT",         "Rotom-H",            "ELECTRIC","FIRE",    "Plasma",           3, 3,   1),
    ("SPECIES_ROTOM_WASH",         "Rotom-W",            "ELECTRIC","WATER",   "Plasma",           3, 3,   1),
    ("SPECIES_ROTOM_FROST",        "Rotom-F",            "ELECTRIC","ICE",     "Plasma",           3, 3,   1),
    ("SPECIES_ROTOM_FAN",          "Rotom-S",            "ELECTRIC","FLYING",  "Plasma",           3, 3,   1),
    ("SPECIES_ROTOM_MOW",          "Rotom-C",            "ELECTRIC","GRASS",   "Plasma",           3, 3,   1),
    # Toxel line
    ("SPECIES_TOXEL",              "Toxel",              "ELECTRIC","POISON",  "Baby",             4, 110, 1),
    ("SPECIES_TOXTRICITY",         "Toxtricity",         "ELECTRIC","POISON",  "Punk",             16,400, 2),
    # Tynamo line
    ("SPECIES_TYNAMO",             "Tynamo",             "ELECTRIC","ELECTRIC","EleFish",          2, 3,   1),
    ("SPECIES_EELEKTRIK",          "Eelektrik",          "ELECTRIC","ELECTRIC","EleFish",          12,220, 2),
    ("SPECIES_EELEKTROSS",         "Eelektross",         "ELECTRIC","ELECTRIC","EleFish",          20,805, 3),
    # Single evolutions
    ("SPECIES_ROSERADE",           "Roserade",           "GRASS",   "POISON",  "Bouquet",          9, 145, 3),
    ("SPECIES_TANGROWTH",          "Tangrowth",          "GRASS",   "GRASS",   "Overgrow",         20,1284,3),
    # New Eevee evolutions
    ("SPECIES_LEAFEON",            "Leafeon",            "GRASS",   "GRASS",   "Verdant",          10,255, 2),
    ("SPECIES_GLACEON",            "Glaceon",            "ICE",     "ICE",     "Fresh Snow",       8, 259, 2),
    ("SPECIES_SYLVEON",            "Sylveon",            "FAIRY",   "FAIRY",   "Intertwining",     10,235, 2),
    # Ferroseed line
    ("SPECIES_FERROSEED",          "Ferroseed",          "GRASS",   "STEEL",   "Thorn Seed",       6, 188, 1),
    ("SPECIES_FERROTHORN",         "Ferrothorn",         "GRASS",   "STEEL",   "Thorn Pod",        10,1100,2),
    # Pumpkaboo line
    ("SPECIES_PUMPKABOO",          "Pumpkaboo",          "GHOST",   "GRASS",   "Pumpkin",          4, 50,  1),
    ("SPECIES_GOURGEIST",          "Gourgeist",          "GHOST",   "GRASS",   "Pumpkin",          9, 125, 2),
    # Phantump line
    ("SPECIES_PHANTUMP",           "Phantump",           "GHOST",   "GRASS",   "Stump",            4, 70,  1),
    ("SPECIES_TREVENANT",          "Trevenant",          "GHOST",   "GRASS",   "Elder Tree",       15,710, 2),
    # Galarian Mr. Mime line
    ("SPECIES_GALARIAN_MR_MIME",   "Mr. Mime-G",         "ICE",     "PSYCHIC", "Mime",             14,567, 2),
    ("SPECIES_MR_RIME",            "Mr. Rime",           "ICE",     "PSYCHIC", "Comedian",         15,582, 3),
    # Single evolutions
    ("SPECIES_MAMOSWINE",          "Mamoswine",          "ICE",     "GROUND",  "Twin Tusk",        25,2910,3),
    ("SPECIES_FROSLASS",           "Froslass",           "ICE",     "GHOST",   "Snow Land",        13,267, 2),
    ("SPECIES_WEAVILE",            "Weavile",            "DARK",    "ICE",     "Sharp Claw",       11,340, 3),
    # Galarian Darumaka line
    ("SPECIES_GALARIAN_DARUMAKA",  "Darumaka-G",         "ICE",     "ICE",     "Zen Charm",        8, 380, 1),
    ("SPECIES_GALARIAN_DARMANITAN","Darmanitan-G",       "ICE",     "ICE",     "Zen Charm",        17,929, 2),
    # Annihilape
    ("SPECIES_ANNIHILAPE",         "Annihilape",         "FIGHTING","GHOST",   "Rage Monkey",      12,560, 3),
    # Galarian Farfetch'd line
    ("SPECIES_GALARIAN_FARFETCHD", "Farfetch'd-G",       "FIGHTING","FIGHTING","Wild Duck",        8, 420, 1),
    ("SPECIES_SIRFETCHD",          "Sirfetch'd",         "FIGHTING","FIGHTING","Wild Duck",        8, 1177,2),
    # Pancham line
    ("SPECIES_PANCHAM",            "Pancham",            "FIGHTING","FIGHTING","Playful",          6, 80,  1),
    ("SPECIES_PANGORO",            "Pangoro",            "FIGHTING","DARK",    "Daunting",         21,1360,2),
    # Croagunk line
    ("SPECIES_CROAGUNK",           "Croagunk",           "POISON",  "FIGHTING","Toxic Mouth",      7, 230, 1),
    ("SPECIES_TOXICROAK",          "Toxicroak",          "POISON",  "FIGHTING","Toxic Mouth",      13,444, 2),
    # Riolu line
    ("SPECIES_RIOLU",              "Riolu",              "FIGHTING","FIGHTING","Emanation",        7, 202, 1),
    ("SPECIES_LUCARIO",            "Lucario",            "FIGHTING","STEEL",   "Aura",             12,540, 2),
    # Scraggy line
    ("SPECIES_SCRAGGY",            "Scraggy",            "DARK",    "FIGHTING","Shedding",         6, 118, 1),
    ("SPECIES_SCRAFTY",            "Scrafty",            "DARK",    "FIGHTING","Hoodlum",          11,300, 2),
    # Skrelp line
    ("SPECIES_SKRELP",             "Skrelp",             "POISON",  "WATER",   "Mock Kelp",        5, 73,  1),
    ("SPECIES_DRAGALGE",           "Dragalge",           "POISON",  "DRAGON",  "Mock Kelp",        18,815, 2),
    # Gible line
    ("SPECIES_GIBLE",              "Gible",              "DRAGON",  "GROUND",  "Land Shark",       7, 205, 1),
    ("SPECIES_GABITE",             "Gabite",             "DRAGON",  "GROUND",  "Cave",             14,560, 2),
    ("SPECIES_GARCHOMP",           "Garchomp",           "DRAGON",  "GROUND",  "Mach",             19,950, 3),
    # Single evolutions
    ("SPECIES_GLISCOR",            "Gliscor",            "GROUND",  "FLYING",  "Fang Scorp",       20,425, 3),
    ("SPECIES_RHYPERIOR",          "Rhyperior",          "GROUND",  "ROCK",    "Drill",            24,2823,3),
    # Drilbur line
    ("SPECIES_DRILBUR",            "Drilbur",            "GROUND",  "GROUND",  "Mole",             3, 85,  1),
    ("SPECIES_EXCADRILL",          "Excadrill",          "GROUND",  "STEEL",   "Subterrene",       7, 404, 2),
    # Sandile line
    ("SPECIES_SANDILE",            "Sandile",            "GROUND",  "DARK",    "Desert Croc",      7, 152, 1),
    ("SPECIES_KROKOROK",           "Krokorok",           "GROUND",  "DARK",    "Desert Croc",      10,333, 2),
    ("SPECIES_KROOKODILE",         "Krookodile",         "GROUND",  "DARK",    "Intimidation",     15,964, 3),
    # Golett line
    ("SPECIES_GOLETT",             "Golett",             "GROUND",  "GHOST",   "Automaton",        10,920, 1),
    ("SPECIES_GOLURK",             "Golurk",             "GROUND",  "GHOST",   "Automaton",        28,3300,2),
    # Single evolutions
    ("SPECIES_HONCHKROW",          "Honchkrow",          "DARK",    "FLYING",  "Big Boss",         9, 273, 3),
    ("SPECIES_TOGEKISS",           "Togekiss",           "FAIRY",   "FLYING",  "Jubilee",          15,380, 3),
    ("SPECIES_YANMEGA",            "Yanmega",            "BUG",     "FLYING",  "Ogre Darner",      19,515, 3),
    # Hawlucha
    ("SPECIES_HAWLUCHA",           "Hawlucha",           "FIGHTING","FLYING",  "Wrestling",        8, 215, 2),
    # Rookidee line
    ("SPECIES_ROOKIDEE",           "Rookidee",           "FLYING",  "FLYING",  "Rook",             2, 16,  1),
    ("SPECIES_CORVISQUIRE",        "Corvisquire",        "FLYING",  "FLYING",  "Raven",            8, 160, 2),
    ("SPECIES_CORVIKNIGHT",        "Corviknight",        "FLYING",  "STEEL",   "Raven",            22,750, 3),
    # Gallade
    ("SPECIES_GALLADE",            "Gallade",            "PSYCHIC", "FIGHTING","Blade",            16,547, 3),
    # Inkay line
    ("SPECIES_INKAY",              "Inkay",              "DARK",    "PSYCHIC", "Revolving",        4, 35,  1),
    ("SPECIES_MALAMAR",            "Malamar",            "DARK",    "PSYCHIC", "Overturning",      15,470, 2),
    # Larvesta line
    ("SPECIES_LARVESTA",           "Larvesta",           "BUG",     "FIRE",    "Torch",            11,288, 1),
    ("SPECIES_VOLCARONA",          "Volcarona",          "BUG",     "FIRE",    "Sun",              16,460, 2),
    # Grubbin line
    ("SPECIES_GRUBBIN",            "Grubbin",            "BUG",     "BUG",     "Larva",            4, 44,  1),
    ("SPECIES_CHARJABUG",          "Charjabug",          "BUG",     "ELECTRIC","Battery",          5, 105, 2),
    ("SPECIES_VIKAVOLT",           "Vikavolt",           "BUG",     "ELECTRIC","Stag Beetle",      15,450, 3),
    # Sizzlipede line
    ("SPECIES_SIZZLIPEDE",         "Sizzlipede",         "FIRE",    "BUG",     "Radiator",         7, 10,  1),
    ("SPECIES_CENTISKORCH",        "Centiskorch",        "FIRE",    "BUG",     "Radiator",         30,1200,2),
    # Kleavor
    ("SPECIES_KLEAVOR",            "Kleavor",            "BUG",     "ROCK",    "Axe",              18,890, 3),
    # Hisuian Growlithe line
    ("SPECIES_HISUIAN_GROWLITHE",  "Growlithe-H",        "FIRE",    "ROCK",    "Puppy",            8, 230, 1),
    ("SPECIES_HISUIAN_ARCANINE",   "Arcanine-H",         "FIRE",    "ROCK",    "Legendary",        19,1680,2),
    # Alolan Geodude line
    ("SPECIES_ALOLAN_GEODUDE",     "Geodude-A",          "ROCK",    "ELECTRIC","Rock",             4, 200, 1),
    ("SPECIES_ALOLAN_GRAVELER",    "Graveler-A",         "ROCK",    "ELECTRIC","Rock",             10,1050,2),
    ("SPECIES_ALOLAN_GOLEM",       "Golem-A",            "ROCK",    "ELECTRIC","Megaton",          14,3000,3),
    # Probopass
    ("SPECIES_PROBOPASS",          "Probopass",          "ROCK",    "STEEL",   "Compass",          14,3000,3),
    # Rockruff line
    ("SPECIES_ROCKRUFF",           "Rockruff",           "ROCK",    "ROCK",    "Puppy",            5, 92,  1),
    ("SPECIES_LYCANROC",           "Lycanroc",           "ROCK",    "ROCK",    "Wolf",             8, 250, 2),
    # Dreepy line
    ("SPECIES_DREEPY",             "Dreepy",             "DRAGON",  "GHOST",   "Lingering",        5, 20,  1),
    ("SPECIES_DRAKLOAK",           "Drakloak",           "DRAGON",  "GHOST",   "Caretaker",        14,110, 2),
    ("SPECIES_DRAGAPULT",          "Dragapult",          "DRAGON",  "GHOST",   "Stealth",          30,500, 3),
    # Basculin line
    ("SPECIES_BASCULIN",           "Basculin",           "WATER",   "WATER",   "Hostile",          10,180, 2),
    ("SPECIES_BASCULEGION",        "Basculegion",        "WATER",   "GHOST",   "Big Fish",         30,1100,3),
    # Alolan Exeggutor
    ("SPECIES_ALOLAN_EXEGGUTOR",   "Exeggutor-A",        "GRASS",   "DRAGON",  "Coconut",          109,4155,3),
    # Deino line
    ("SPECIES_DEINO",              "Deino",              "DARK",    "DRAGON",  "Irate",            8, 174, 1),
    ("SPECIES_ZWEILOUS",           "Zweilous",           "DARK",    "DRAGON",  "Hostile",          14,500, 2),
    ("SPECIES_HYDREIGON",          "Hydreigon",          "DARK",    "DRAGON",  "Brutal",           18,1600,3),
    # Goomy line
    ("SPECIES_GOOMY",              "Goomy",              "DRAGON",  "DRAGON",  "Soft Tissue",      3, 28,  1),
    ("SPECIES_SLIGGOO",            "Sliggoo",            "DRAGON",  "DRAGON",  "Soft Tissue",      4, 175, 2),
    ("SPECIES_GOODRA",             "Goodra",             "DRAGON",  "DRAGON",  "Dragon",           20,1503,3),
    # Darkrai
    ("SPECIES_DARKRAI",            "Darkrai",            "DARK",    "DARK",    "Pitch-Black",      15,505, 3),
    # Zorua line
    ("SPECIES_ZORUA",              "Zorua",              "DARK",    "DARK",    "Tricky Fox",       7, 125, 1),
    ("SPECIES_ZOROARK",            "Zoroark",            "DARK",    "DARK",    "Illusion Fox",     16,731, 2),
    # Pawniard line
    ("SPECIES_PAWNIARD",           "Pawniard",           "DARK",    "STEEL",   "Sharp Blade",      5, 102, 1),
    ("SPECIES_BISHARP",            "Bisharp",            "DARK",    "STEEL",   "Sword Blade",      16,700, 2),
    ("SPECIES_KINGAMBIT",          "Kingambit",          "DARK",    "STEEL",   "Big Blade",        20,1200,3),
    # Bronzor line
    ("SPECIES_BRONZOR",            "Bronzor",            "STEEL",   "PSYCHIC", "Bronze",           5, 605, 1),
    ("SPECIES_BRONZONG",           "Bronzong",           "STEEL",   "PSYCHIC", "Bronze Bell",      13,1870,2),
    # Galarian Meowth line
    ("SPECIES_GALARIAN_MEOWTH",    "Meowth-G",           "STEEL",   "STEEL",   "Scratch Cat",      4, 75,  1),
    ("SPECIES_PERRSERKER",         "Perrserker",         "STEEL",   "STEEL",   "Viking",           8, 280, 2),
    # Alolan Meowth line
    ("SPECIES_ALOLAN_MEOWTH",      "Meowth-A",           "DARK",    "DARK",    "Scratch Cat",      4, 42,  1),
    ("SPECIES_ALOLAN_PERSIAN",     "Persian-A",          "DARK",    "DARK",    "Classy Cat",       11,330, 2),
    # Duraludon line
    ("SPECIES_DURALUDON",          "Duraludon",          "STEEL",   "DRAGON",  "Alloy",            18,400, 2),
    ("SPECIES_ARCHALUDON",         "Archaludon",         "STEEL",   "DRAGON",  "Alloy",            20,600, 3),
    # Tinkatink line
    ("SPECIES_TINKATINK",          "Tinkatink",          "FAIRY",   "STEEL",   "Metalsmith",       4, 89,  1),
    ("SPECIES_TINKATUFF",          "Tinkatuff",          "FAIRY",   "STEEL",   "Hammer",           7, 225, 2),
    ("SPECIES_TINKATON",           "Tinkaton",           "FAIRY",   "STEEL",   "Hammer",           7, 1128,3),
    # Alolan Diglett line
    ("SPECIES_ALOLAN_DIGLETT",     "Diglett-A",          "GROUND",  "STEEL",   "Mole",             2, 10,  1),
    ("SPECIES_ALOLAN_DUGTRIO",     "Dugtrio-A",          "GROUND",  "STEEL",   "Mole",             7, 666, 2),
    # Magnezone
    ("SPECIES_MAGNEZONE",          "Magnezone",          "ELECTRIC","STEEL",   "Magnet Area",      12,1803,3),
    # Flabebe line
    ("SPECIES_FLABEBE",            "Flabébé",            "FAIRY",   "FAIRY",   "Single Bloom",     1, 1,   1),
    ("SPECIES_FLOETTE",            "Floette",            "FAIRY",   "FAIRY",   "Single Bloom",     2, 9,   2),
    ("SPECIES_FLORGES",            "Florges",            "FAIRY",   "FAIRY",   "Garden",           11,100, 3),
    # Alolan Vulpix line
    ("SPECIES_ALOLAN_VULPIX",      "Vulpix-A",           "ICE",     "ICE",     "Fox",              6, 99,  1),
    ("SPECIES_ALOLAN_NINETALES",   "Ninetales-A",        "ICE",     "FAIRY",   "Fox",              11,199, 2),
    # Gen 4 Legendaries
    ("SPECIES_UXIE",               "Uxie",               "PSYCHIC", "PSYCHIC", "Knowledge",        3, 3,   3),
    ("SPECIES_MESPRIT",            "Mesprit",            "PSYCHIC", "PSYCHIC", "Emotion",          3, 3,   3),
    ("SPECIES_AZELF",              "Azelf",              "PSYCHIC", "PSYCHIC", "Willpower",        3, 3,   3),
    ("SPECIES_DIALGA",             "Dialga",             "STEEL",   "DRAGON",  "Temporal",         54,6830,3),
    ("SPECIES_PALKIA",             "Palkia",             "WATER",   "DRAGON",  "Spatial",          42,3360,3),
    ("SPECIES_HEATRAN",            "Heatran",            "FIRE",    "STEEL",   "Lava Dome",        17,4300,3),
    ("SPECIES_REGIGIGAS",          "Regigigas",          "NORMAL",  "NORMAL",  "Colossal",         37,4200,3),
    ("SPECIES_GIRATINA",           "Giratina",           "GHOST",   "DRAGON",  "Renegade",         69,7500,3),
    ("SPECIES_CRESSELIA",          "Cresselia",          "PSYCHIC", "PSYCHIC", "Lunar",            15,857, 3),
    ("SPECIES_PHIONE",             "Phione",             "WATER",   "WATER",   "Sea Drifter",      4, 31,  1),
    ("SPECIES_MANAPHY",            "Manaphy",            "WATER",   "WATER",   "Seafaring",        3, 14,  3),
    ("SPECIES_SHAYMIN",            "Shaymin",            "GRASS",   "GRASS",   "Gratitude",        2, 21,  3),
    ("SPECIES_ARCEUS",             "Arceus",             "NORMAL",  "NORMAL",  "Alpha",            32,3200,3),
]

# ─────────────────────────────────────────────────────────
# Learnsets: type -> list of (level, MOVE_XXX) tuples
# Levels are stage-adjusted automatically.
# ─────────────────────────────────────────────────────────
TYPE_LEARNSETS = {
    "NORMAL":   [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(5,"MOVE_HEADBUTT"),(13,"MOVE_TAKE_DOWN"),(21,"MOVE_BODY_SLAM"),(29,"MOVE_DOUBLE_EDGE"),(40,"MOVE_HYPER_BEAM")],
    "FIRE":     [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_EMBER"),(13,"MOVE_LEER"),(19,"MOVE_FLAME_WHEEL"),(28,"MOVE_FLAMETHROWER"),(38,"MOVE_FIRE_BLAST")],
    "WATER":    [(1,"MOVE_TACKLE"),(1,"MOVE_TAIL_WHIP"),(7,"MOVE_WATER_GUN"),(13,"MOVE_GROWL"),(21,"MOVE_BUBBLE_BEAM"),(30,"MOVE_SURF"),(40,"MOVE_HYDRO_PUMP")],
    "GRASS":    [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_ABSORB"),(13,"MOVE_GROWTH"),(21,"MOVE_RAZOR_LEAF"),(30,"MOVE_GIGA_DRAIN"),(40,"MOVE_SOLAR_BEAM")],
    "ELECTRIC": [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_THUNDER_SHOCK"),(13,"MOVE_THUNDER_WAVE"),(21,"MOVE_SPARK"),(30,"MOVE_THUNDERBOLT"),(40,"MOVE_THUNDER")],
    "ICE":      [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_POWDER_SNOW"),(13,"MOVE_LEER"),(21,"MOVE_ICY_WIND"),(30,"MOVE_AURORA_BEAM"),(40,"MOVE_BLIZZARD")],
    "FIGHTING": [(1,"MOVE_TACKLE"),(1,"MOVE_LEER"),(7,"MOVE_LOW_KICK"),(13,"MOVE_KARATE_CHOP"),(21,"MOVE_SEISMIC_TOSS"),(30,"MOVE_BRICK_BREAK"),(40,"MOVE_CROSS_CHOP")],
    "POISON":   [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_POISON_STING"),(13,"MOVE_ACID"),(21,"MOVE_SLUDGE"),(30,"MOVE_TOXIC"),(40,"MOVE_SLUDGE_BOMB")],
    "GROUND":   [(1,"MOVE_TACKLE"),(1,"MOVE_SAND_ATTACK"),(7,"MOVE_MUD_SHOT"),(13,"MOVE_GROWL"),(21,"MOVE_MAGNITUDE"),(30,"MOVE_DIG"),(40,"MOVE_EARTHQUAKE")],
    "FLYING":   [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_GUST"),(13,"MOVE_WING_ATTACK"),(21,"MOVE_AERIAL_ACE"),(30,"MOVE_AIR_CUTTER"),(40,"MOVE_FLY")],
    "PSYCHIC":  [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_CONFUSION"),(13,"MOVE_DISABLE"),(21,"MOVE_PSYBEAM"),(30,"MOVE_CALM_MIND"),(40,"MOVE_PSYCHIC")],
    "BUG":      [(1,"MOVE_TACKLE"),(1,"MOVE_STRING_SHOT"),(7,"MOVE_FURY_CUTTER"),(13,"MOVE_BITE"),(21,"MOVE_SIGNAL_BEAM"),(30,"MOVE_SLASH"),(40,"MOVE_HYPER_BEAM")],
    "ROCK":     [(1,"MOVE_TACKLE"),(1,"MOVE_DEFENSE_CURL"),(7,"MOVE_ROCK_THROW"),(13,"MOVE_LEER"),(21,"MOVE_ROLLOUT"),(30,"MOVE_ROCK_SLIDE"),(40,"MOVE_ROCK_BLAST")],
    "GHOST":    [(1,"MOVE_LICK"),(1,"MOVE_SPITE"),(7,"MOVE_NIGHT_SHADE"),(13,"MOVE_CONFUSE_RAY"),(21,"MOVE_SHADOW_BALL"),(30,"MOVE_WILL_O_WISP"),(40,"MOVE_DESTINY_BOND")],
    "DRAGON":   [(1,"MOVE_LEER"),(1,"MOVE_TACKLE"),(7,"MOVE_TWISTER"),(13,"MOVE_DRAGON_RAGE"),(21,"MOVE_DRAGON_CLAW"),(30,"MOVE_SLASH"),(40,"MOVE_HYPER_BEAM")],
    "DARK":     [(1,"MOVE_TACKLE"),(1,"MOVE_LEER"),(7,"MOVE_BITE"),(13,"MOVE_FAINT_ATTACK"),(21,"MOVE_TORMENT"),(30,"MOVE_CRUNCH"),(40,"MOVE_DARK_PULSE")],
    "STEEL":    [(1,"MOVE_TACKLE"),(1,"MOVE_HARDEN"),(7,"MOVE_METAL_SOUND"),(13,"MOVE_LEER"),(21,"MOVE_IRON_TAIL"),(30,"MOVE_IRON_DEFENSE"),(40,"MOVE_FLASH_CANNON")],
    "FAIRY":    [(1,"MOVE_TACKLE"),(1,"MOVE_GROWL"),(7,"MOVE_CHARM"),(13,"MOVE_SWEET_KISS"),(21,"MOVE_MOONLIGHT"),(30,"MOVE_DAZZLING_GLEAM"),(40,"MOVE_MOONBLAST")],
}

# Replace any Gen4+ only moves with Gen3 equivalents for FAIRY type
# DAZZLING_GLEAM and MOONBLAST don't exist in Gen3 FR - replace with Body Slam / Psychic
TYPE_LEARNSETS["FAIRY"][5] = (30, "MOVE_BODY_SLAM")
TYPE_LEARNSETS["FAIRY"][6] = (40, "MOVE_PSYCHIC")

# Additional overrides for specific moves that don't exist in Gen3:
# SIGNAL_BEAM exists in Gen3 (TM73 in Gen4 but it's TM - as a learn move it might not exist)
# Replace with PIN_MISSILE if it doesn't exist, or just SLASH
# FLASH_CANNON doesn't exist in Gen3 - replace with IRON_TAIL for Steel
TYPE_LEARNSETS["STEEL"][6] = (40, "MOVE_IRON_TAIL")
# DARK_PULSE doesn't exist in Gen3 - replace with CRUNCH
TYPE_LEARNSETS["DARK"][6]  = (40, "MOVE_CRUNCH")
# AIR_CUTTER might not exist in Gen3 - replace with AERIAL_ACE
TYPE_LEARNSETS["FLYING"][5] = (30, "MOVE_AERIAL_ACE")
# SIGNAL_BEAM is not in Gen3 learnable moves - replace with SLASH
TYPE_LEARNSETS["BUG"][4]   = (21, "MOVE_SLASH")
# SLUDGE might not have the exact macro - use ACID_ARMOR or just TOXIC earlier
TYPE_LEARNSETS["POISON"][4] = (21, "TOXIC")  # Will fix - use MOVE_TOXIC
TYPE_LEARNSETS["POISON"][4] = (21, "MOVE_ACID")
TYPE_LEARNSETS["POISON"][5] = (30, "MOVE_TOXIC")
# MUD_SHOT is Gen3 but check availability
# GIGA_DRAIN is Gen3
# ROCK_BLAST might not be in Gen3 - use ROCK_SLIDE
TYPE_LEARNSETS["ROCK"][5]  = (30, "MOVE_ROCK_SLIDE")
TYPE_LEARNSETS["ROCK"][6]  = (40, "MOVE_DOUBLE_EDGE")
# WILL_O_WISP is Gen3
# AURORA_BEAM is Gen3


def get_learnset(type1, gen_stage):
    """Return learnset moves scaled to gen_stage (1=basic, 2=mid, 3=final)."""
    base = TYPE_LEARNSETS.get(type1, TYPE_LEARNSETS["NORMAL"])
    moves = []
    for (lvl, move) in base:
        # Stage scaling: higher stage learns same moves sooner, plus more
        scaled_lvl = max(1, lvl - (gen_stage - 1) * 2)
        moves.append((scaled_lvl, move))
    # For stage 3, add a final powerful move
    if gen_stage == 3:
        # Add HYPER_BEAM or similar at high level (if not already HYPER_BEAM type)
        if type1 in ("NORMAL", "BUG", "ROCK", "DRAGON", "GROUND", "FLYING"):
            pass  # already has strong finale
        moves.append((50, "MOVE_HYPER_BEAM"))
    return sorted(moves, key=lambda x: x[0])


def species_to_name(macro):
    """Convert SPECIES_LUXIO -> sLuxioLevelUpLearnset"""
    parts = macro.replace("SPECIES_", "").split("_")
    name = "".join(p.capitalize() for p in parts)
    return f"s{name}LevelUpLearnset"


def gen_learnsets_append():
    """Generate the new learnset arrays to append to level_up_learnsets.h."""
    lines = []
    lines.append("\n// === Cynthia's Crown Step 5 learnsets ===\n")
    for row in SPECIES:
        macro, display, t1, t2, cat, h, w, stage = row
        var = species_to_name(macro)
        moves = get_learnset(t1, stage)
        lines.append(f"static const u16 {var}[] = {{\n")
        for (lvl, mv) in moves:
            lines.append(f"    LEVEL_UP_MOVE({lvl}, {mv}),\n")
        lines.append(f"    LEVEL_UP_END\n}};\n\n")
    return "".join(lines)


def gen_learnset_pointers_append():
    """Generate pointer entries to insert before the closing }; in the pointers file."""
    lines = []
    lines.append("    // === Cynthia's Crown Step 5 learnset pointers ===\n")
    for row in SPECIES:
        macro = row[0]
        var = species_to_name(macro)
        lines.append(f"    [{macro}] = {var},\n")
    return "".join(lines)


def gen_tmhm_append():
    """Generate TM/HM entries to insert before closing }; in tmhm_learnsets.h."""
    # Type -> applicable TMs
    TYPE_TMS = {
        "NORMAL":   "TMHM(TM17_PROTECT) | TMHM(TM18_RAIN_DANCE) | TMHM(TM21_FRUSTRATION) | TMHM(TM27_RETURN) | TMHM(TM32_DOUBLE_TEAM) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT) | TMHM(TM46_THIEF)",
        "FIRE":     "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM11_SUNNY_DAY) | TMHM(TM17_PROTECT) | TMHM(TM35_FLAMETHROWER) | TMHM(TM38_FIRE_BLAST) | TMHM(TM44_REST) | TMHM(TM50_OVERHEAT)",
        "WATER":    "TMHM(TM03_WATER_PULSE) | TMHM(TM06_TOXIC) | TMHM(TM07_HAIL) | TMHM(TM13_ICE_BEAM) | TMHM(TM17_PROTECT) | TMHM(TM18_RAIN_DANCE) | TMHM(TM44_REST) | TMHM(HM03_SURF) | TMHM(HM07_WATERFALL)",
        "GRASS":    "TMHM(TM06_TOXIC) | TMHM(TM09_BULLET_SEED) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM11_SUNNY_DAY) | TMHM(TM17_PROTECT) | TMHM(TM19_GIGA_DRAIN) | TMHM(TM22_SOLAR_BEAM) | TMHM(TM44_REST)",
        "ELECTRIC": "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM21_FRUSTRATION) | TMHM(TM24_THUNDERBOLT) | TMHM(TM25_THUNDER) | TMHM(TM34_SHOCK_WAVE) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT)",
        "ICE":      "TMHM(TM06_TOXIC) | TMHM(TM07_HAIL) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM13_ICE_BEAM) | TMHM(TM14_BLIZZARD) | TMHM(TM17_PROTECT) | TMHM(TM44_REST)",
        "FIGHTING": "TMHM(TM06_TOXIC) | TMHM(TM08_BULK_UP) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM31_BRICK_BREAK) | TMHM(TM44_REST) | TMHM(HM04_STRENGTH)",
        "POISON":   "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM36_SLUDGE_BOMB) | TMHM(TM44_REST)",
        "GROUND":   "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM26_EARTHQUAKE) | TMHM(TM28_DIG) | TMHM(TM37_SANDSTORM) | TMHM(TM44_REST) | TMHM(HM06_ROCK_SMASH)",
        "FLYING":   "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM21_FRUSTRATION) | TMHM(TM27_RETURN) | TMHM(TM40_AERIAL_ACE) | TMHM(TM44_REST) | TMHM(HM02_FLY)",
        "PSYCHIC":  "TMHM(TM04_CALM_MIND) | TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM16_LIGHT_SCREEN) | TMHM(TM17_PROTECT) | TMHM(TM29_PSYCHIC) | TMHM(TM33_REFLECT) | TMHM(TM44_REST)",
        "BUG":      "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM44_REST) | TMHM(TM46_THIEF) | TMHM(HM01_CUT)",
        "ROCK":     "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM23_IRON_TAIL) | TMHM(TM37_SANDSTORM) | TMHM(TM39_ROCK_TOMB) | TMHM(TM44_REST) | TMHM(HM06_ROCK_SMASH)",
        "GHOST":    "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM30_SHADOW_BALL) | TMHM(TM44_REST) | TMHM(TM46_THIEF) | TMHM(TM48_SKILL_SWAP)",
        "DRAGON":   "TMHM(TM02_DRAGON_CLAW) | TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM15_HYPER_BEAM) | TMHM(TM17_PROTECT) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT)",
        "DARK":     "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM12_TAUNT) | TMHM(TM17_PROTECT) | TMHM(TM30_SHADOW_BALL) | TMHM(TM44_REST) | TMHM(TM46_THIEF) | TMHM(TM49_SNATCH)",
        "STEEL":    "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM23_IRON_TAIL) | TMHM(TM37_SANDSTORM) | TMHM(TM44_REST) | TMHM(HM06_ROCK_SMASH)",
        "FAIRY":    "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM27_RETURN) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT)",
    }
    lines = []
    lines.append("    // === Cynthia's Crown Step 5 TM/HM learnsets ===\n")
    for row in SPECIES:
        macro, display, t1, t2 = row[0], row[1], row[2], row[3]
        t1_tms = TYPE_TMS.get(t1, TYPE_TMS["NORMAL"])
        if t2 != t1:
            t2_tms = TYPE_TMS.get(t2, "")
            combo = f"{t1_tms} | {t2_tms}" if t2_tms else t1_tms
        else:
            combo = t1_tms
        lines.append(f"    [{macro}] = TMHM_LEARNSET({combo}),\n\n")
    return "".join(lines)


def gen_pokedex_text_append():
    """Generate pokedex text entries for fr and lg text files."""
    fr_lines = ["\n// === Cynthia's Crown Step 5 Pokedex Texts ===\n\n"]
    lg_lines = ["\n// === Cynthia's Crown Step 5 Pokedex Texts (LG) ===\n\n"]
    for row in SPECIES:
        macro, display, t1, t2, cat = row[0], row[1], row[2], row[3], row[4]
        var_prefix = macro.replace("SPECIES_", "")
        # Build simple description
        desc_lines = f"A {t1.capitalize()}-type Pokémon\nknown as the {display}."
        unused = ""
        fr_lines.append(f"const u8 g{var_prefix.replace('_', '')}PokedexText[] = _(\n")
        fr_lines.append(f'    "{desc_lines}\\n"\n')
        fr_lines.append(f'    "$");\n\n')
        fr_lines.append(f"const u8 g{var_prefix.replace('_', '')}PokedexTextUnused[] = _(\"\");\n\n")
        # LG uses same text
        lg_lines.append(f"const u8 g{var_prefix.replace('_', '')}PokedexTextLG[] = _(\n")
        lg_lines.append(f'    "{desc_lines}\\n"\n')
        lg_lines.append(f'    "$");\n\n')
    return "".join(fr_lines), "".join(lg_lines)


def gen_pokedex_entries_append():
    """Generate pokedex_entries.h entries to insert before closing };."""
    lines = ["    // === Cynthia's Crown Step 5 Pokedex Entries ===\n"]
    for row in SPECIES:
        macro, display, t1, t2, cat, h, w, stage = row
        var_prefix = macro.replace("SPECIES_", "").replace("_", "")
        nat_macro = macro.replace("SPECIES_", "NATIONAL_DEX_")
        lines.append(f"\n    [{nat_macro}] =\n    {{\n")
        lines.append(f'        .categoryName = _("{cat}"),\n')
        lines.append(f"        .height = {h},\n")
        lines.append(f"        .weight = {w},\n")
        lines.append(f"        .description = g{var_prefix}PokedexText,\n")
        lines.append(f"        .unusedDescription = g{var_prefix}PokedexTextUnused,\n")
        lines.append(f"        .pokemonScale = 356,\n")
        lines.append(f"        .pokemonOffset = 17,\n")
        lines.append(f"        .trainerScale = 256,\n")
        lines.append(f"        .trainerOffset = 0,\n")
        lines.append(f"    }},\n")
    return "".join(lines)


def append_before_closing_brace(filepath, content, marker="};"):
    """Insert content before the last occurrence of marker in the file."""
    with open(filepath, "r") as f:
        text = f.read()
    idx = text.rfind(marker)
    if idx == -1:
        raise ValueError(f"Could not find '{marker}' in {filepath}")
    new_text = text[:idx] + content + text[idx:]
    with open(filepath, "w") as f:
        f.write(new_text)
    print(f"  Updated {filepath}")


def append_to_file(filepath, content):
    with open(filepath, "a") as f:
        f.write(content)
    print(f"  Appended to {filepath}")


def main():
    import os
    # 1. Append learnset arrays to level_up_learnsets.h
    ls_path = "src/data/pokemon/level_up_learnsets.h"
    if "sLuxioLevelUpLearnset" not in open(ls_path).read():
        append_to_file(ls_path, gen_learnsets_append())
    else:
        print(f"  Skipping {ls_path} (already has Step 5 data)")

    # 2. Insert learnset pointers before }; in level_up_learnset_pointers.h
    lp_path = "src/data/pokemon/level_up_learnset_pointers.h"
    if "SPECIES_LUXIO" not in open(lp_path).read():
        append_before_closing_brace(lp_path, gen_learnset_pointers_append())
    else:
        print(f"  Skipping {lp_path} (already has Step 5 data)")

    # 3. Insert TM/HM entries before }; in tmhm_learnsets.h
    tm_path = "src/data/pokemon/tmhm_learnsets.h"
    if "SPECIES_LUXIO" not in open(tm_path).read():
        append_before_closing_brace(tm_path, gen_tmhm_append())
    else:
        print(f"  Skipping {tm_path} (already has Step 5 data)")

    # 4. Append pokedex texts to pokedex_text_fr.h
    fr_text, lg_text = gen_pokedex_text_append()
    fr_path = "src/data/pokemon/pokedex_text_fr.h"
    if "LUXIO" not in open(fr_path).read():
        append_to_file(fr_path, fr_text)
    else:
        print(f"  Skipping {fr_path} (already has Step 5 data)")

    lg_path = "src/data/pokemon/pokedex_text_lg.h"
    if "LUXIO" not in open(lg_path).read():
        # LG text file might use a different variable naming scheme; use FR texts
        append_to_file(lg_path, fr_text.replace("PokedexText[]", "PokedexTextLG[]")
                                        .replace("PokedexTextUnused[]", "PokedexTextUnusedLG[]"))
    else:
        print(f"  Skipping {lg_path} (already has Step 5 data)")

    # 5. Insert pokedex entries before }; in pokedex_entries.h
    pe_path = "src/data/pokemon/pokedex_entries.h"
    if "NATIONAL_DEX_LUXIO" not in open(pe_path).read():
        append_before_closing_brace(pe_path, gen_pokedex_entries_append())
    else:
        print(f"  Skipping {pe_path} (already has Step 5 data)")

    print("Done.")


if __name__ == "__main__":
    main()
