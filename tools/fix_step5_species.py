#!/usr/bin/env python3
"""
Fix build/step5_species_info.inc:
  - Correct .abilities for all 168 species
  - Correct .bodyColor for all 168 species
  - Correct .evYield_* for all 168 species
  - Correct .expYield for all 168 species (was hardcoded 100 for all)

Run from repo root:
  python3 tools/fix_step5_species.py
"""

import re, sys

# Corrections dict: species_macro -> (ab1, ab2, body_color, exp_yield, ev_hp, ev_atk, ev_def, ev_spd, ev_spatk, ev_spdef)
# Abilities use string names matching include/constants/abilities.h
# body_color uses BODY_COLOR_X strings
# ev_* are integers (each in range 0-3, sum usually <= 3)

CORRECTIONS = {
    # ===== Step-1 species (412-415) =====
    "SPECIES_SHINX":               ("ABILITY_STATIC",      "ABILITY_INTIMIDATE",  "BODY_COLOR_BLUE",   64,  0,0,0,1,0,0),
    "SPECIES_AXEW":                ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_GREEN",  64,  0,1,0,0,0,0),
    "SPECIES_HONEDGE":             ("ABILITY_BATTLE_ARMOR","ABILITY_NONE",        "BODY_COLOR_BLUE",   65,  0,0,1,0,0,0),
    "SPECIES_GALARIAN_ZIGZAGOON":  ("ABILITY_PICKUP",      "ABILITY_NONE",        "BODY_COLOR_WHITE",  56,  0,0,0,1,0,0),

    # ===== New species (416-579) =====
    # 416-423 Evolutions of Step-1 species
    "SPECIES_LUXIO":               ("ABILITY_STATIC",      "ABILITY_INTIMIDATE",  "BODY_COLOR_BLUE",  127,  0,0,0,0,0,2),
    "SPECIES_LUXRAY":              ("ABILITY_INTIMIDATE",  "ABILITY_STATIC",      "BODY_COLOR_BLUE",  216,  0,0,0,0,0,3),
    "SPECIES_FRAXURE":             ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_GREEN", 144,  0,2,0,0,0,0),
    "SPECIES_HAXORUS":             ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_GREEN", 243,  0,3,0,0,0,0),
    "SPECIES_DOUBLADE":            ("ABILITY_BATTLE_ARMOR","ABILITY_NONE",        "BODY_COLOR_GRAY",  157,  0,0,2,0,0,0),
    "SPECIES_AEGISLASH":           ("ABILITY_SHELL_ARMOR", "ABILITY_NONE",        "BODY_COLOR_YELLOW",234,  0,0,3,0,0,0),
    "SPECIES_GALARIAN_LINOONE":    ("ABILITY_PICKUP",      "ABILITY_NONE",        "BODY_COLOR_WHITE", 147,  0,0,0,2,0,0),
    "SPECIES_OBSTAGOON":           ("ABILITY_GUTS",        "ABILITY_NONE",        "BODY_COLOR_WHITE", 261,  0,3,0,0,0,0),

    # 424-426 Starly line
    "SPECIES_STARLY":              ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_BROWN",  49,  0,0,0,1,0,0),
    "SPECIES_STARAVIA":            ("ABILITY_INTIMIDATE",  "ABILITY_NONE",        "BODY_COLOR_BROWN", 119,  0,0,0,2,0,0),
    "SPECIES_STARAPTOR":           ("ABILITY_INTIMIDATE",  "ABILITY_NONE",        "BODY_COLOR_BROWN", 218,  0,3,0,0,0,0),

    # 427 Munchlax
    "SPECIES_MUNCHLAX":            ("ABILITY_PICKUP",      "ABILITY_THICK_FAT",   "BODY_COLOR_BLUE",   78,  1,0,0,0,0,0),

    # 428 Porygon-Z
    "SPECIES_PORYGON_Z":           ("ABILITY_TRACE",       "ABILITY_NONE",        "BODY_COLOR_PINK",  241,  0,0,0,0,3,0),

    # 429-430 Hisuian Zorua line
    "SPECIES_HISUIAN_ZORUA":       ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_WHITE",  66,  0,0,0,0,1,0),
    "SPECIES_HISUIAN_ZOROARK":     ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_WHITE", 179,  0,0,0,0,2,0),

    # 431-433 Fletchling line
    "SPECIES_FLETCHLING":          ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_RED",    56,  0,0,0,1,0,0),
    "SPECIES_FLETCHINDER":         ("ABILITY_FLAME_BODY",  "ABILITY_NONE",        "BODY_COLOR_RED",   128,  0,0,0,2,0,0),
    "SPECIES_TALONFLAME":          ("ABILITY_FLAME_BODY",  "ABILITY_NONE",        "BODY_COLOR_RED",   175,  0,0,0,3,0,0),

    # 434 Ursaluna
    "SPECIES_URSALUNA":            ("ABILITY_GUTS",        "ABILITY_NONE",        "BODY_COLOR_BROWN", 243,  3,0,0,0,0,0),

    # 435-436 Salandit line
    "SPECIES_SALANDIT":            ("ABILITY_OBLIVIOUS",   "ABILITY_NONE",        "BODY_COLOR_GRAY",   64,  0,0,0,1,0,0),
    "SPECIES_SALAZZLE":            ("ABILITY_OBLIVIOUS",   "ABILITY_NONE",        "BODY_COLOR_PURPLE",168,  0,0,0,2,0,0),

    # 437-439 Litwick line
    "SPECIES_LITWICK":             ("ABILITY_FLASH_FIRE",  "ABILITY_FLAME_BODY",  "BODY_COLOR_YELLOW", 55,  0,0,0,0,1,0),
    "SPECIES_LAMPENT":             ("ABILITY_FLASH_FIRE",  "ABILITY_FLAME_BODY",  "BODY_COLOR_GRAY",  130,  0,0,0,0,2,0),
    "SPECIES_CHANDELURE":          ("ABILITY_FLASH_FIRE",  "ABILITY_FLAME_BODY",  "BODY_COLOR_PURPLE",234,  0,0,0,0,3,0),

    # 440-442 Chimchar line
    "SPECIES_CHIMCHAR":            ("ABILITY_BLAZE",       "ABILITY_NONE",        "BODY_COLOR_RED",    62,  0,0,0,1,0,0),
    "SPECIES_MONFERNO":            ("ABILITY_BLAZE",       "ABILITY_NONE",        "BODY_COLOR_RED",   142,  0,0,0,2,0,0),
    "SPECIES_INFERNAPE":           ("ABILITY_BLAZE",       "ABILITY_NONE",        "BODY_COLOR_RED",   240,  0,0,0,3,0,0),

    # 443-445 Piplup line
    "SPECIES_PIPLUP":              ("ABILITY_TORRENT",     "ABILITY_NONE",        "BODY_COLOR_BLUE",   63,  0,0,0,0,0,1),
    "SPECIES_PRINPLUP":            ("ABILITY_TORRENT",     "ABILITY_NONE",        "BODY_COLOR_BLUE",  142,  0,0,0,0,0,2),
    "SPECIES_EMPOLEON":            ("ABILITY_TORRENT",     "ABILITY_KEEN_EYE",    "BODY_COLOR_BLUE",  239,  0,0,0,0,3,0),

    # 446-447 Buizel line
    "SPECIES_BUIZEL":              ("ABILITY_SWIFT_SWIM",  "ABILITY_NONE",        "BODY_COLOR_YELLOW", 66,  0,0,0,1,0,0),
    "SPECIES_FLOATZEL":            ("ABILITY_SWIFT_SWIM",  "ABILITY_NONE",        "BODY_COLOR_YELLOW",173,  0,0,0,2,0,0),

    # 448-449 Trade evolutions
    "SPECIES_MAGMORTAR":           ("ABILITY_FLAME_BODY",  "ABILITY_VITAL_SPIRIT","BODY_COLOR_RED",   243,  0,0,0,0,3,0),
    "SPECIES_ELECTIVIRE":          ("ABILITY_STATIC",      "ABILITY_VITAL_SPIRIT","BODY_COLOR_YELLOW",243,  0,3,0,0,0,0),

    # 450-455 Rotom forms
    "SPECIES_ROTOM":               ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_RED",   182,  0,0,0,0,1,0),
    "SPECIES_ROTOM_HEAT":          ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_RED",   182,  0,0,0,0,1,0),
    "SPECIES_ROTOM_WASH":          ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",  182,  0,0,0,0,1,0),
    "SPECIES_ROTOM_FROST":         ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",  182,  0,0,0,0,1,0),
    "SPECIES_ROTOM_FAN":           ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_RED",   182,  0,0,0,0,1,0),
    "SPECIES_ROTOM_MOW":           ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_GREEN", 182,  0,0,0,0,1,0),

    # 456-457 Toxel line
    "SPECIES_TOXEL":               ("ABILITY_STATIC",      "ABILITY_NONE",        "BODY_COLOR_PURPLE", 48,  1,0,0,0,0,0),
    "SPECIES_TOXTRICITY":          ("ABILITY_PLUS",        "ABILITY_MINUS",       "BODY_COLOR_PURPLE",168,  0,0,0,0,2,0),

    # 458-460 Tynamo line
    "SPECIES_TYNAMO":              ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_WHITE",  55,  0,0,0,1,0,0),
    "SPECIES_EELEKTRIK":           ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",  142,  0,0,0,0,2,0),
    "SPECIES_EELEKTROSS":          ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",  232,  0,3,0,0,0,0),

    # 461-462 Single evolutions
    "SPECIES_ROSERADE":            ("ABILITY_NATURAL_CURE","ABILITY_POISON_POINT","BODY_COLOR_GREEN", 232,  0,0,0,0,3,0),
    "SPECIES_TANGROWTH":           ("ABILITY_CHLOROPHYLL", "ABILITY_NONE",        "BODY_COLOR_GREEN", 211,  0,0,2,0,0,0),

    # 463-465 New Eevee evolutions
    "SPECIES_LEAFEON":             ("ABILITY_CHLOROPHYLL", "ABILITY_NONE",        "BODY_COLOR_GREEN", 184,  0,0,2,0,0,0),
    "SPECIES_GLACEON":             ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_BLUE",  184,  0,0,0,0,0,2),
    "SPECIES_SYLVEON":             ("ABILITY_CUTE_CHARM",  "ABILITY_NONE",        "BODY_COLOR_PINK",  184,  0,0,0,0,0,2),

    # 466-467 Ferroseed line
    "SPECIES_FERROSEED":           ("ABILITY_ROUGH_SKIN",  "ABILITY_NONE",        "BODY_COLOR_GREEN",  61,  0,0,1,0,0,1),
    "SPECIES_FERROTHORN":          ("ABILITY_ROUGH_SKIN",  "ABILITY_NONE",        "BODY_COLOR_GREEN", 171,  0,0,2,0,0,1),

    # 468-469 Pumpkaboo line
    "SPECIES_PUMPKABOO":           ("ABILITY_PICKUP",      "ABILITY_NONE",        "BODY_COLOR_BROWN",  67,  1,0,0,0,0,0),
    "SPECIES_GOURGEIST":           ("ABILITY_PICKUP",      "ABILITY_NONE",        "BODY_COLOR_BROWN", 173,  2,0,0,0,0,0),

    # 470-471 Phantump line
    "SPECIES_PHANTUMP":            ("ABILITY_NATURAL_CURE","ABILITY_NONE",        "BODY_COLOR_BROWN",  62,  1,0,0,0,0,0),
    "SPECIES_TREVENANT":           ("ABILITY_NATURAL_CURE","ABILITY_NONE",        "BODY_COLOR_BROWN", 167,  2,0,0,0,0,0),

    # 472-473 Galarian Mr. Mime line
    "SPECIES_GALARIAN_MR_MIME":    ("ABILITY_SERENE_GRACE","ABILITY_NONE",        "BODY_COLOR_BLUE",  161,  0,0,0,1,0,0),
    "SPECIES_MR_RIME":             ("ABILITY_SERENE_GRACE","ABILITY_NONE",        "BODY_COLOR_WHITE", 207,  0,0,0,0,0,2),

    # 474-476 Single evolutions
    "SPECIES_MAMOSWINE":           ("ABILITY_OBLIVIOUS",   "ABILITY_NONE",        "BODY_COLOR_BROWN", 239,  0,3,0,0,0,0),
    "SPECIES_FROSLASS":            ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_WHITE", 168,  0,0,0,2,0,0),
    "SPECIES_WEAVILE":             ("ABILITY_PRESSURE",    "ABILITY_NONE",        "BODY_COLOR_BLACK", 179,  0,1,0,1,0,0),

    # 477-478 Galarian Darumaka line
    "SPECIES_GALARIAN_DARUMAKA":   ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_WHITE", 115,  0,1,0,0,0,0),
    "SPECIES_GALARIAN_DARMANITAN": ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_WHITE", 168,  0,2,0,0,0,0),

    # 479 Annihilape
    "SPECIES_ANNIHILAPE":          ("ABILITY_VITAL_SPIRIT","ABILITY_INNER_FOCUS", "BODY_COLOR_PURPLE",200,  0,3,0,0,0,0),

    # 480-481 Galarian Farfetch'd line
    "SPECIES_GALARIAN_FARFETCHD":  ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BROWN", 132,  0,1,0,0,0,0),
    "SPECIES_SIRFETCHD":           ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_WHITE", 221,  0,2,0,0,0,0),

    # 482-483 Pancham line
    "SPECIES_PANCHAM":             ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_GRAY",   70,  0,1,0,0,0,0),
    "SPECIES_PANGORO":             ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BLACK", 173,  0,2,0,0,0,0),

    # 484-485 Croagunk line
    "SPECIES_CROAGUNK":            ("ABILITY_POISON_POINT","ABILITY_NONE",        "BODY_COLOR_BLUE",   60,  0,1,0,0,0,0),
    "SPECIES_TOXICROAK":           ("ABILITY_POISON_POINT","ABILITY_NONE",        "BODY_COLOR_BLUE",  172,  0,2,0,0,0,0),

    # 486-487 Riolu line
    "SPECIES_RIOLU":               ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BLUE",   57,  0,1,0,0,0,0),
    "SPECIES_LUCARIO":             ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BLUE",  184,  0,1,0,0,1,0),

    # 488-489 Scraggy line
    "SPECIES_SCRAGGY":             ("ABILITY_SHED_SKIN",   "ABILITY_NONE",        "BODY_COLOR_YELLOW", 70,  0,1,0,0,0,0),
    "SPECIES_SCRAFTY":             ("ABILITY_SHED_SKIN",   "ABILITY_NONE",        "BODY_COLOR_RED",   171,  0,1,1,0,0,0),

    # 490-491 Skrelp line
    "SPECIES_SKRELP":              ("ABILITY_POISON_POINT","ABILITY_NONE",        "BODY_COLOR_BROWN",  64,  0,0,0,0,0,1),
    "SPECIES_DRAGALGE":            ("ABILITY_POISON_POINT","ABILITY_NONE",        "BODY_COLOR_BROWN", 173,  0,0,0,0,0,2),

    # 492-494 Gible line
    "SPECIES_GIBLE":               ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_BLUE",   60,  0,1,0,0,0,0),
    "SPECIES_GABITE":              ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_BLUE",  144,  0,2,0,0,0,0),
    "SPECIES_GARCHOMP":            ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_BLUE",  270,  0,3,0,0,0,0),

    # 495-496 Single evolutions
    "SPECIES_GLISCOR":             ("ABILITY_HYPER_CUTTER","ABILITY_SAND_VEIL",   "BODY_COLOR_PURPLE",179,  0,0,2,0,0,0),
    "SPECIES_RHYPERIOR":           ("ABILITY_LIGHTNING_ROD","ABILITY_NONE",       "BODY_COLOR_BROWN", 241,  0,0,3,0,0,0),

    # 497-498 Drilbur line
    "SPECIES_DRILBUR":             ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_GRAY",   66,  0,1,0,0,0,0),
    "SPECIES_EXCADRILL":           ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_GRAY",  178,  0,2,1,0,0,0),

    # 499-501 Sandile line
    "SPECIES_SANDILE":             ("ABILITY_INTIMIDATE",  "ABILITY_NONE",        "BODY_COLOR_BROWN",  58,  0,1,0,0,0,0),
    "SPECIES_KROKOROK":            ("ABILITY_INTIMIDATE",  "ABILITY_NONE",        "BODY_COLOR_BROWN", 123,  0,2,0,0,0,0),
    "SPECIES_KROOKODILE":          ("ABILITY_INTIMIDATE",  "ABILITY_NONE",        "BODY_COLOR_BROWN", 234,  0,3,0,0,0,0),

    # 502-503 Golett line
    "SPECIES_GOLETT":              ("ABILITY_NONE",        "ABILITY_NONE",        "BODY_COLOR_GREEN",  61,  1,0,0,0,0,0),
    "SPECIES_GOLURK":              ("ABILITY_NONE",        "ABILITY_NONE",        "BODY_COLOR_GREEN", 169,  0,3,0,0,0,0),

    # 504-506 Single evolutions
    "SPECIES_HONCHKROW":           ("ABILITY_INSOMNIA",    "ABILITY_NONE",        "BODY_COLOR_BLACK", 177,  0,2,0,0,0,0),
    "SPECIES_TOGEKISS":            ("ABILITY_HUSTLE",      "ABILITY_SERENE_GRACE","BODY_COLOR_WHITE", 245,  0,0,0,0,3,0),
    "SPECIES_YANMEGA":             ("ABILITY_SPEED_BOOST", "ABILITY_NONE",        "BODY_COLOR_GREEN", 180,  0,0,0,0,2,0),

    # 507 Hawlucha
    "SPECIES_HAWLUCHA":            ("ABILITY_LIMBER",      "ABILITY_NONE",        "BODY_COLOR_GREEN", 175,  0,2,0,0,0,0),

    # 508-510 Rookidee line
    "SPECIES_ROOKIDEE":            ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",   49,  0,0,0,1,0,0),
    "SPECIES_CORVISQUIRE":         ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_GRAY",  124,  0,0,0,2,0,0),
    "SPECIES_CORVIKNIGHT":         ("ABILITY_PRESSURE",    "ABILITY_NONE",        "BODY_COLOR_BLACK", 220,  0,0,3,0,0,0),

    # 511 Gallade
    "SPECIES_GALLADE":             ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_GREEN", 233,  0,3,0,0,0,0),

    # 512-513 Inkay line
    "SPECIES_INKAY":               ("ABILITY_SUCTION_CUPS","ABILITY_NONE",        "BODY_COLOR_PURPLE", 58,  0,1,0,0,0,0),
    "SPECIES_MALAMAR":             ("ABILITY_SUCTION_CUPS","ABILITY_NONE",        "BODY_COLOR_PURPLE",169,  0,2,0,0,0,0),

    # 514-515 Larvesta line
    "SPECIES_LARVESTA":            ("ABILITY_FLAME_BODY",  "ABILITY_SWARM",       "BODY_COLOR_WHITE",  72,  0,0,0,0,2,0),
    "SPECIES_VOLCARONA":           ("ABILITY_FLAME_BODY",  "ABILITY_SWARM",       "BODY_COLOR_YELLOW",248,  0,0,0,0,3,0),

    # 516-518 Grubbin line
    "SPECIES_GRUBBIN":             ("ABILITY_SWARM",       "ABILITY_NONE",        "BODY_COLOR_YELLOW", 60,  1,0,0,0,0,0),
    "SPECIES_CHARJABUG":           ("ABILITY_PLUS",        "ABILITY_NONE",        "BODY_COLOR_GRAY",  130,  0,0,2,0,0,0),
    "SPECIES_VIKAVOLT":            ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_GREEN", 225,  0,0,0,0,3,0),

    # 519-520 Sizzlipede line
    "SPECIES_SIZZLIPEDE":          ("ABILITY_FLASH_FIRE",  "ABILITY_WHITE_SMOKE", "BODY_COLOR_RED",    56,  1,0,0,0,0,0),
    "SPECIES_CENTISKORCH":         ("ABILITY_FLASH_FIRE",  "ABILITY_WHITE_SMOKE", "BODY_COLOR_RED",   170,  0,0,0,0,3,0),

    # 521 Kleavor
    "SPECIES_KLEAVOR":             ("ABILITY_SWARM",       "ABILITY_HUSTLE",      "BODY_COLOR_BROWN", 200,  0,2,0,0,0,0),

    # 522-523 Hisuian Growlithe line
    "SPECIES_HISUIAN_GROWLITHE":   ("ABILITY_INTIMIDATE",  "ABILITY_FLASH_FIRE",  "BODY_COLOR_BROWN",  70,  0,1,0,0,0,0),
    "SPECIES_HISUIAN_ARCANINE":    ("ABILITY_INTIMIDATE",  "ABILITY_FLASH_FIRE",  "BODY_COLOR_BROWN", 194,  0,3,0,0,0,0),

    # 524-526 Alolan Geodude line
    "SPECIES_ALOLAN_GEODUDE":      ("ABILITY_MAGNET_PULL", "ABILITY_STURDY",      "BODY_COLOR_GRAY",   60,  0,0,1,0,0,0),
    "SPECIES_ALOLAN_GRAVELER":     ("ABILITY_MAGNET_PULL", "ABILITY_STURDY",      "BODY_COLOR_GRAY",  137,  0,0,2,0,0,0),
    "SPECIES_ALOLAN_GOLEM":        ("ABILITY_MAGNET_PULL", "ABILITY_STURDY",      "BODY_COLOR_BROWN", 223,  0,0,3,0,0,0),

    # 527 Probopass
    "SPECIES_PROBOPASS":           ("ABILITY_MAGNET_PULL", "ABILITY_STURDY",      "BODY_COLOR_BROWN", 184,  1,0,0,0,0,2),

    # 528-529 Rockruff line
    "SPECIES_ROCKRUFF":            ("ABILITY_KEEN_EYE",    "ABILITY_VITAL_SPIRIT","BODY_COLOR_BROWN",  56,  0,1,0,0,0,0),
    "SPECIES_LYCANROC":            ("ABILITY_KEEN_EYE",    "ABILITY_SAND_VEIL",   "BODY_COLOR_BROWN", 170,  0,0,0,2,0,0),

    # 530-532 Dreepy line
    "SPECIES_DREEPY":              ("ABILITY_CLEAR_BODY",  "ABILITY_NONE",        "BODY_COLOR_BLUE",   54,  0,0,0,1,0,0),
    "SPECIES_DRAKLOAK":            ("ABILITY_CLEAR_BODY",  "ABILITY_NONE",        "BODY_COLOR_BLUE",  117,  0,0,0,2,0,0),
    "SPECIES_DRAGAPULT":           ("ABILITY_CLEAR_BODY",  "ABILITY_NONE",        "BODY_COLOR_BLUE",  300,  0,0,0,3,0,0),

    # 533-534 Basculin line
    "SPECIES_BASCULIN":            ("ABILITY_ROCK_HEAD",   "ABILITY_NONE",        "BODY_COLOR_RED",   161,  0,0,0,2,0,0),
    "SPECIES_BASCULEGION":         ("ABILITY_SWIFT_SWIM",  "ABILITY_NONE",        "BODY_COLOR_WHITE", 216,  0,2,0,0,0,0),

    # 535 Alolan Exeggutor
    "SPECIES_ALOLAN_EXEGGUTOR":    ("ABILITY_ILLUMINATE",  "ABILITY_NONE",        "BODY_COLOR_GREEN", 186,  0,0,0,0,2,1),

    # 536-538 Deino line
    "SPECIES_DEINO":               ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_BLUE",   60,  0,0,0,0,1,0),
    "SPECIES_ZWEILOUS":            ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_PURPLE",147,  0,0,0,0,2,0),
    "SPECIES_HYDREIGON":           ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_PURPLE",270,  0,0,0,0,3,0),

    # 539-541 Goomy line
    "SPECIES_GOOMY":               ("ABILITY_RAIN_DISH",   "ABILITY_NONE",        "BODY_COLOR_PURPLE", 60,  0,0,0,0,0,1),
    "SPECIES_SLIGGOO":             ("ABILITY_RAIN_DISH",   "ABILITY_NONE",        "BODY_COLOR_PURPLE",158,  0,0,0,0,0,2),
    "SPECIES_GOODRA":              ("ABILITY_RAIN_DISH",   "ABILITY_NONE",        "BODY_COLOR_PURPLE",270,  0,0,0,0,0,3),

    # 542 Darkrai
    "SPECIES_DARKRAI":             ("ABILITY_INSOMNIA",    "ABILITY_NONE",        "BODY_COLOR_BLACK", 270,  0,0,0,2,0,0),

    # 543-544 Zorua line
    "SPECIES_ZORUA":               ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_BLACK",  66,  0,1,0,0,0,0),
    "SPECIES_ZOROARK":             ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_BLACK", 179,  0,2,0,0,0,0),

    # 545-547 Pawniard line
    "SPECIES_PAWNIARD":            ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BLACK",  56,  0,1,0,0,0,0),
    "SPECIES_BISHARP":             ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BLACK", 172,  0,2,0,0,0,0),
    "SPECIES_KINGAMBIT":           ("ABILITY_INNER_FOCUS", "ABILITY_NONE",        "BODY_COLOR_BLACK", 275,  0,3,0,0,0,0),

    # 548-549 Bronzor line
    "SPECIES_BRONZOR":             ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_GRAY",   60,  0,0,1,0,0,0),
    "SPECIES_BRONZONG":            ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_GRAY",  175,  0,0,2,0,0,0),

    # 550-551 Galarian Meowth line
    "SPECIES_GALARIAN_MEOWTH":     ("ABILITY_PICKUP",      "ABILITY_NONE",        "BODY_COLOR_GRAY",   58,  0,1,0,0,0,0),
    "SPECIES_PERRSERKER":          ("ABILITY_BATTLE_ARMOR","ABILITY_NONE",        "BODY_COLOR_GRAY",  154,  0,2,0,0,0,0),

    # 552-553 Alolan Meowth line
    "SPECIES_ALOLAN_MEOWTH":       ("ABILITY_PICKUP",      "ABILITY_NONE",        "BODY_COLOR_GRAY",   58,  0,0,0,1,0,0),
    "SPECIES_ALOLAN_PERSIAN":      ("ABILITY_KEEN_EYE",    "ABILITY_NONE",        "BODY_COLOR_GRAY",  154,  0,0,0,2,0,0),

    # 554-555 Duraludon line
    "SPECIES_DURALUDON":           ("ABILITY_CLEAR_BODY",  "ABILITY_NONE",        "BODY_COLOR_GRAY",  160,  0,0,0,0,2,0),
    "SPECIES_ARCHALUDON":          ("ABILITY_SHELL_ARMOR", "ABILITY_NONE",        "BODY_COLOR_GRAY",  227,  0,0,0,0,3,0),

    # 556-558 Tinkatink line
    "SPECIES_TINKATINK":           ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_PINK",   60,  0,0,1,0,0,0),
    "SPECIES_TINKATUFF":           ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_PINK",  135,  0,0,2,0,0,0),
    "SPECIES_TINKATON":            ("ABILITY_HUSTLE",      "ABILITY_NONE",        "BODY_COLOR_PINK",  255,  0,0,3,0,0,0),

    # 559-560 Alolan Diglett line
    "SPECIES_ALOLAN_DIGLETT":      ("ABILITY_SAND_VEIL",   "ABILITY_ARENA_TRAP",  "BODY_COLOR_BROWN",  53,  0,0,0,1,0,0),
    "SPECIES_ALOLAN_DUGTRIO":      ("ABILITY_SAND_VEIL",   "ABILITY_ARENA_TRAP",  "BODY_COLOR_BROWN", 149,  0,0,0,2,0,0),

    # 561 Magnezone
    "SPECIES_MAGNEZONE":           ("ABILITY_MAGNET_PULL", "ABILITY_STURDY",      "BODY_COLOR_GRAY",  241,  0,0,0,0,3,0),

    # 562-564 Flabebe line
    "SPECIES_FLABEBE":             ("ABILITY_NONE",        "ABILITY_NONE",        "BODY_COLOR_WHITE",  61,  0,0,0,0,0,1),
    "SPECIES_FLOETTE":             ("ABILITY_NONE",        "ABILITY_NONE",        "BODY_COLOR_WHITE", 130,  0,0,0,0,0,2),
    "SPECIES_FLORGES":             ("ABILITY_NONE",        "ABILITY_NONE",        "BODY_COLOR_WHITE", 248,  0,0,0,0,0,3),

    # 565-566 Alolan Vulpix line
    "SPECIES_ALOLAN_VULPIX":       ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_WHITE",   60, 0,0,0,0,0,1),
    "SPECIES_ALOLAN_NINETALES":    ("ABILITY_SAND_VEIL",   "ABILITY_NONE",        "BODY_COLOR_WHITE",  179, 0,0,0,0,1,2),

    # ===== Gen 4 Legendaries (567-579) =====
    "SPECIES_UXIE":                ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_YELLOW",261,  0,0,0,0,0,2),
    "SPECIES_MESPRIT":             ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_PINK",  261,  0,0,0,0,2,0),
    "SPECIES_AZELF":               ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",  261,  0,0,0,0,2,0),
    "SPECIES_DIALGA":              ("ABILITY_PRESSURE",    "ABILITY_NONE",        "BODY_COLOR_BLUE",  306,  0,0,0,0,3,0),
    "SPECIES_PALKIA":              ("ABILITY_PRESSURE",    "ABILITY_NONE",        "BODY_COLOR_PURPLE",306,  0,0,0,0,3,0),
    "SPECIES_HEATRAN":             ("ABILITY_FLASH_FIRE",  "ABILITY_FLAME_BODY",  "BODY_COLOR_RED",   270,  0,0,0,0,3,0),
    "SPECIES_REGIGIGAS":           ("ABILITY_TRUANT",      "ABILITY_NONE",        "BODY_COLOR_WHITE", 302,  0,3,0,0,0,0),
    "SPECIES_GIRATINA":            ("ABILITY_PRESSURE",    "ABILITY_NONE",        "BODY_COLOR_BLACK", 306,  3,0,0,0,0,0),
    "SPECIES_CRESSELIA":           ("ABILITY_LEVITATE",    "ABILITY_NONE",        "BODY_COLOR_YELLOW",270,  0,0,0,0,0,3),
    "SPECIES_PHIONE":              ("ABILITY_RAIN_DISH",   "ABILITY_NONE",        "BODY_COLOR_BLUE",  216,  1,0,0,0,0,0),
    "SPECIES_MANAPHY":             ("ABILITY_RAIN_DISH",   "ABILITY_NONE",        "BODY_COLOR_BLUE",  270,  3,0,0,0,0,0),
    "SPECIES_SHAYMIN":             ("ABILITY_NATURAL_CURE","ABILITY_SERENE_GRACE","BODY_COLOR_GREEN", 270,  3,0,0,0,0,0),
    "SPECIES_ARCEUS":              ("ABILITY_NONE",        "ABILITY_NONE",        "BODY_COLOR_WHITE", 324,  3,0,0,0,0,0),
}

def fix_species_block(lines, species_name, corr):
    """Return a new list of lines with corrections applied to a species block."""
    ab1, ab2, color, exp_yield, ev_hp, ev_atk, ev_def, ev_spd, ev_spatk, ev_spdef = corr
    out = []
    for line in lines:
        stripped = line.strip()
        if stripped.startswith(".abilities ="):
            out.append(f"        .abilities = {{{ab1}, {ab2}}},\n")
        elif stripped.startswith(".bodyColor ="):
            out.append(f"        .bodyColor = {color},\n")
        elif stripped.startswith(".expYield ="):
            out.append(f"        .expYield = {exp_yield},\n")
        elif stripped.startswith(".evYield_HP ="):
            out.append(f"        .evYield_HP = {ev_hp},\n")
        elif stripped.startswith(".evYield_Attack ="):
            out.append(f"        .evYield_Attack = {ev_atk},\n")
        elif stripped.startswith(".evYield_Defense ="):
            out.append(f"        .evYield_Defense = {ev_def},\n")
        elif stripped.startswith(".evYield_Speed ="):
            out.append(f"        .evYield_Speed = {ev_spd},\n")
        elif stripped.startswith(".evYield_SpAttack ="):
            out.append(f"        .evYield_SpAttack = {ev_spatk},\n")
        elif stripped.startswith(".evYield_SpDefense ="):
            out.append(f"        .evYield_SpDefense = {ev_spdef},\n")
        else:
            out.append(line)
    return out

def main():
    input_path = "build/step5_species_info.inc"
    output_path = "build/step5_species_info.inc"

    with open(input_path, "r") as f:
        content = f.read()

    # Split into individual species entries by finding [SPECIES_X] = { ... },
    # We'll process line by line with a state machine.
    lines = content.splitlines(keepends=True)

    result = []
    current_species = None
    current_block = []
    in_block = False

    for line in lines:
        # Detect species block start: "    [SPECIES_XXX] ="
        m = re.match(r'^\s+\[(SPECIES_\w+)\]\s*=\s*$', line)
        if m:
            # Flush previous block
            if in_block and current_species:
                if current_species in CORRECTIONS:
                    current_block = fix_species_block(current_block, current_species, CORRECTIONS[current_species])
                result.extend(current_block)
            current_species = m.group(1)
            current_block = [line]
            in_block = True
        elif in_block:
            current_block.append(line)
            # End of block: line is "    },"
            if re.match(r'^\s+\},\s*$', line):
                if current_species in CORRECTIONS:
                    current_block = fix_species_block(current_block, current_species, CORRECTIONS[current_species])
                result.extend(current_block)
                current_block = []
                current_species = None
                in_block = False
        else:
            result.append(line)

    # Flush any remaining block
    if in_block and current_block:
        if current_species and current_species in CORRECTIONS:
            current_block = fix_species_block(current_block, current_species, CORRECTIONS[current_species])
        result.extend(current_block)

    with open(output_path, "w") as f:
        f.writelines(result)

    print(f"Fixed {len(CORRECTIONS)} species entries in {output_path}")

if __name__ == "__main__":
    main()
