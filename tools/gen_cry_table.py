#!/usr/bin/env python3
"""Generate sStep5SpeciesIdToCryId[] for src/data/pokemon/cry_ids.h.

Each new species is assigned the cry of a thematically similar Kanto/Johto/Hoenn
Pokemon that already exists in the GBA sound bank.

  Kanto/Johto cries: use SPECIES_* constant (cry ID = species number)
  Hoenn cries: use CRY_* constant (defined in hoenn_cries.h)

Run:
    python3 tools/gen_cry_table.py
"""

# (species_constant, cry_constant, comment)
MAPPINGS = [
    # 412 - Pre-Step5 base forms (Shinx/Axew/Honedge line and Galarian Zigzagoon)
    ("SPECIES_SHINX",              "SPECIES_GROWLITHE",   "Electric lion cub"),
    ("SPECIES_AXEW",               "CRY_BAGON",           "Dragon tusk"),
    ("SPECIES_HONEDGE",            "SPECIES_GASTLY",      "Ghost sword"),
    ("SPECIES_GALARIAN_ZIGZAGOON", "CRY_ZIGZAGOON",       "Same family"),
    # 416
    ("SPECIES_LUXIO",              "SPECIES_JOLTEON",     "Electric cat mid"),
    ("SPECIES_LUXRAY",             "SPECIES_RAIKOU",      "Electric lion final"),
    ("SPECIES_FRAXURE",            "CRY_SHELGON",         "Dragon tusk mid"),
    ("SPECIES_HAXORUS",            "CRY_SALAMENCE",       "Dragon tusk final"),
    ("SPECIES_DOUBLADE",           "SPECIES_HAUNTER",     "Ghost twin swords"),
    ("SPECIES_AEGISLASH",          "SPECIES_GENGAR",      "Ghost king sword"),
    ("SPECIES_GALARIAN_LINOONE",   "CRY_LINOONE",         "Same family"),
    ("SPECIES_OBSTAGOON",          "CRY_MIGHTYENA",       "Rock-star punk"),
    # 424
    ("SPECIES_STARLY",             "CRY_TAILLOW",         "Small flying bird"),
    ("SPECIES_STARAVIA",           "CRY_SWELLOW",         "Mid flying bird"),
    ("SPECIES_STARAPTOR",          "CRY_SWELLOW",         "Large flying bird"),
    ("SPECIES_MUNCHLAX",           "SPECIES_SNORLAX",     "Same family"),
    ("SPECIES_PORYGON_Z",          "SPECIES_PORYGON2",    "Same family"),
    ("SPECIES_HISUIAN_ZORUA",      "CRY_SABLEYE",         "Ghost fox small"),
    ("SPECIES_HISUIAN_ZOROARK",    "CRY_ABSOL",           "Ghost fox large"),
    # 431
    ("SPECIES_FLETCHLING",         "CRY_TAILLOW",         "Small fire bird"),
    ("SPECIES_FLETCHINDER",        "CRY_SWELLOW",         "Mid fire bird"),
    ("SPECIES_TALONFLAME",         "SPECIES_MOLTRES",     "Fire/Flying final"),
    ("SPECIES_URSALUNA",           "SPECIES_URSARING",    "Same family"),
    ("SPECIES_SALANDIT",           "CRY_NUMEL",           "Fire lizard small"),
    ("SPECIES_SALAZZLE",           "CRY_CAMERUPT",        "Fire/Poison final"),
    # 437
    ("SPECIES_LITWICK",            "SPECIES_GASTLY",      "Ghost/Fire candle small"),
    ("SPECIES_LAMPENT",            "SPECIES_HAUNTER",     "Ghost/Fire lamp mid"),
    ("SPECIES_CHANDELURE",         "SPECIES_GENGAR",      "Ghost/Fire chandelier"),
    # 440
    ("SPECIES_CHIMCHAR",           "CRY_TORCHIC",         "Fire monkey starter"),
    ("SPECIES_MONFERNO",           "CRY_COMBUSKEN",       "Fire/Fighting mid"),
    ("SPECIES_INFERNAPE",          "CRY_BLAZIKEN",        "Fire/Fighting final"),
    ("SPECIES_PIPLUP",             "CRY_MUDKIP",          "Water starter small"),
    ("SPECIES_PRINPLUP",           "CRY_MARSHTOMP",       "Water starter mid"),
    ("SPECIES_EMPOLEON",           "CRY_SWAMPERT",        "Water/Steel final"),
    ("SPECIES_BUIZEL",             "SPECIES_MARILL",      "Water weasel small"),
    ("SPECIES_FLOATZEL",           "SPECIES_DEWGONG",     "Water weasel final"),
    ("SPECIES_MAGMORTAR",          "SPECIES_MAGMAR",      "Same family"),
    ("SPECIES_ELECTIVIRE",         "SPECIES_ELECTABUZZ",  "Same family"),
    # 450
    ("SPECIES_ROTOM",              "SPECIES_VOLTORB",     "Electric ghost small"),
    ("SPECIES_ROTOM_HEAT",         "SPECIES_MAGMAR",      "Electric/Fire form"),
    ("SPECIES_ROTOM_WASH",         "SPECIES_STARYU",      "Electric/Water form"),
    ("SPECIES_ROTOM_FROST",        "SPECIES_JYNX",        "Electric/Ice form"),
    ("SPECIES_ROTOM_FAN",          "SPECIES_ZAPDOS",      "Electric/Flying form"),
    ("SPECIES_ROTOM_MOW",          "SPECIES_ELECTRODE",   "Electric/Grass form"),
    ("SPECIES_TOXEL",              "SPECIES_ELEKID",      "Electric/Poison baby"),
    ("SPECIES_TOXTRICITY",         "SPECIES_ELECTABUZZ",  "Electric/Poison punk"),
    ("SPECIES_TYNAMO",             "SPECIES_MAGNEMITE",   "Electric eel small"),
    ("SPECIES_EELEKTRIK",          "SPECIES_MAGNETON",    "Electric eel mid"),
    ("SPECIES_EELEKTROSS",         "SPECIES_ELECTRODE",   "Electric eel final"),
    # 461
    ("SPECIES_ROSERADE",           "CRY_ROSELIA",         "Same family"),
    ("SPECIES_TANGROWTH",          "SPECIES_TANGELA",     "Same family"),
    ("SPECIES_LEAFEON",            "SPECIES_EEVEE",       "Grass Eeveelution"),
    ("SPECIES_GLACEON",            "SPECIES_EEVEE",       "Ice Eeveelution"),
    ("SPECIES_SYLVEON",            "SPECIES_CLEFAIRY",    "Fairy Eeveelution"),
    ("SPECIES_FERROSEED",          "CRY_ARON",            "Grass/Steel seed"),
    ("SPECIES_FERROTHORN",         "CRY_LAIRON",          "Grass/Steel final"),
    # 468
    ("SPECIES_PUMPKABOO",          "CRY_SHUPPET",         "Ghost/Grass pumpkin small"),
    ("SPECIES_GOURGEIST",          "CRY_BANETTE",         "Ghost/Grass pumpkin final"),
    ("SPECIES_PHANTUMP",           "CRY_SHUPPET",         "Ghost/Grass stump small"),
    ("SPECIES_TREVENANT",          "CRY_BANETTE",         "Ghost/Grass tree final"),
    ("SPECIES_GALARIAN_MR_MIME",   "SPECIES_MR_MIME",     "Same family"),
    ("SPECIES_MR_RIME",            "SPECIES_MR_MIME",     "Same family"),
    ("SPECIES_MAMOSWINE",          "SPECIES_SWINUB",      "Same family"),
    ("SPECIES_FROSLASS",           "CRY_GLALIE",          "Same family"),
    ("SPECIES_WEAVILE",            "SPECIES_SNEASEL",     "Same family"),
    ("SPECIES_GALARIAN_DARUMAKA",  "SPECIES_SEEL",        "Ice bear small"),
    ("SPECIES_GALARIAN_DARMANITAN","SPECIES_LAPRAS",      "Ice bear final"),
    ("SPECIES_ANNIHILAPE",         "SPECIES_PRIMEAPE",    "Same family"),
    ("SPECIES_GALARIAN_FARFETCHD", "SPECIES_FARFETCHD",   "Same family"),
    ("SPECIES_SIRFETCHD",          "SPECIES_HITMONLEE",   "Fighting bird"),
    ("SPECIES_PANCHAM",            "CRY_MAKUHITA",        "Fighting panda small"),
    ("SPECIES_PANGORO",            "CRY_HARIYAMA",        "Fighting/Dark panda final"),
    ("SPECIES_CROAGUNK",           "CRY_GULPIN",          "Poison/Fighting toad small"),
    ("SPECIES_TOXICROAK",          "CRY_SWALOT",          "Poison/Fighting toad final"),
    ("SPECIES_RIOLU",              "CRY_MAKUHITA",        "Fighting/Steel pup"),
    ("SPECIES_LUCARIO",            "CRY_BRELOOM",         "Fighting/Steel final"),
    ("SPECIES_SCRAGGY",            "SPECIES_SNUBBULL",    "Dark/Fighting small"),
    ("SPECIES_SCRAFTY",            "SPECIES_GRANBULL",    "Dark/Fighting final"),
    # 490
    ("SPECIES_SKRELP",             "SPECIES_HORSEA",      "Poison/Water seahorse"),
    ("SPECIES_DRAGALGE",           "SPECIES_DRAGONAIR",   "Poison/Dragon seaweed"),
    ("SPECIES_GIBLE",              "CRY_BAGON",           "Dragon/Ground small"),
    ("SPECIES_GABITE",             "CRY_SHELGON",         "Dragon/Ground mid"),
    ("SPECIES_GARCHOMP",           "CRY_SALAMENCE",       "Dragon/Ground final"),
    ("SPECIES_GLISCOR",            "SPECIES_GLIGAR",      "Same family"),
    ("SPECIES_RHYPERIOR",          "SPECIES_RHYDON",      "Same family"),
    ("SPECIES_DRILBUR",            "SPECIES_DIGLETT",     "Ground mole small"),
    ("SPECIES_EXCADRILL",          "SPECIES_DUGTRIO",     "Ground/Steel drill"),
    ("SPECIES_SANDILE",            "CRY_TRAPINCH",        "Ground/Dark croc small"),
    ("SPECIES_KROKOROK",           "CRY_VIBRAVA",         "Ground/Dark croc mid"),
    ("SPECIES_KROOKODILE",         "CRY_FLYGON",          "Ground/Dark croc final"),
    ("SPECIES_GOLETT",             "CRY_BALTOY",          "Ground/Ghost golem small"),
    ("SPECIES_GOLURK",             "CRY_CLAYDOL",         "Ground/Ghost golem final"),
    ("SPECIES_HONCHKROW",          "SPECIES_MURKROW",     "Same family"),
    ("SPECIES_TOGEKISS",           "SPECIES_TOGETIC",     "Same family"),
    ("SPECIES_YANMEGA",            "SPECIES_YANMA",       "Same family"),
    ("SPECIES_HAWLUCHA",           "SPECIES_FARFETCHD",   "Fighting/Flying bird"),
    # 508
    ("SPECIES_ROOKIDEE",           "CRY_TAILLOW",         "Flying rook small"),
    ("SPECIES_CORVISQUIRE",        "CRY_SWELLOW",         "Flying rook mid"),
    ("SPECIES_CORVIKNIGHT",        "SPECIES_SKARMORY",    "Steel/Flying rook final"),
    ("SPECIES_GALLADE",            "CRY_GARDEVOIR",       "Same family"),
    ("SPECIES_INKAY",              "SPECIES_TENTACOOL",   "Dark/Psychic squid small"),
    ("SPECIES_MALAMAR",            "SPECIES_TENTACRUEL",  "Dark/Psychic squid final"),
    ("SPECIES_LARVESTA",           "CRY_WURMPLE",         "Bug/Fire larva"),
    ("SPECIES_VOLCARONA",          "CRY_BEAUTIFLY",       "Bug/Fire moth final"),
    ("SPECIES_GRUBBIN",            "CRY_WURMPLE",         "Bug larva"),
    ("SPECIES_CHARJABUG",          "CRY_CASCOON",         "Bug/Electric cocoon"),
    ("SPECIES_VIKAVOLT",           "CRY_DUSTOX",          "Bug/Electric final"),
    ("SPECIES_SIZZLIPEDE",         "CRY_WURMPLE",         "Fire/Bug centipede small"),
    ("SPECIES_CENTISKORCH",        "CRY_BRELOOM",         "Fire/Bug centipede final"),
    ("SPECIES_KLEAVOR",            "CRY_ARMALDO",         "Bug/Rock axe"),
    # 522
    ("SPECIES_HISUIAN_GROWLITHE",  "SPECIES_GROWLITHE",   "Same family"),
    ("SPECIES_HISUIAN_ARCANINE",   "SPECIES_ARCANINE",    "Same family"),
    ("SPECIES_ALOLAN_GEODUDE",     "SPECIES_GEODUDE",     "Same family"),
    ("SPECIES_ALOLAN_GRAVELER",    "SPECIES_GRAVELER",    "Same family"),
    ("SPECIES_ALOLAN_GOLEM",       "SPECIES_GOLEM",       "Same family"),
    ("SPECIES_PROBOPASS",          "CRY_NOSEPASS",        "Same family"),
    ("SPECIES_ROCKRUFF",           "CRY_POOCHYENA",       "Rock pup small"),
    ("SPECIES_LYCANROC",           "CRY_MIGHTYENA",       "Rock wolf final"),
    # 530
    ("SPECIES_DREEPY",             "SPECIES_DRATINI",     "Dragon/Ghost small"),
    ("SPECIES_DRAKLOAK",           "SPECIES_DRAGONAIR",   "Dragon/Ghost mid"),
    ("SPECIES_DRAGAPULT",          "CRY_SALAMENCE",       "Dragon/Ghost final"),
    ("SPECIES_BASCULIN",           "SPECIES_GOLDEEN",     "Water fish small"),
    ("SPECIES_BASCULEGION",        "SPECIES_SEAKING",     "Water/Ghost fish final"),
    ("SPECIES_ALOLAN_EXEGGUTOR",   "SPECIES_EXEGGUTOR",   "Same family"),
    ("SPECIES_DEINO",              "CRY_BAGON",           "Dark/Dragon small"),
    ("SPECIES_ZWEILOUS",           "CRY_SHELGON",         "Dark/Dragon mid"),
    ("SPECIES_HYDREIGON",          "CRY_SALAMENCE",       "Dark/Dragon final"),
    ("SPECIES_GOOMY",              "SPECIES_DRATINI",     "Dragon slime small"),
    ("SPECIES_SLIGGOO",            "SPECIES_DRAGONAIR",   "Dragon slime mid"),
    ("SPECIES_GOODRA",             "SPECIES_DRAGONITE",   "Dragon slime final"),
    # 542
    ("SPECIES_DARKRAI",            "SPECIES_GENGAR",      "Dark legendary"),
    ("SPECIES_ZORUA",              "CRY_POOCHYENA",       "Dark fox small"),
    ("SPECIES_ZOROARK",            "CRY_MIGHTYENA",       "Dark fox final"),
    ("SPECIES_PAWNIARD",           "CRY_ARON",            "Dark/Steel blade small"),
    ("SPECIES_BISHARP",            "CRY_LAIRON",          "Dark/Steel blade mid"),
    ("SPECIES_KINGAMBIT",          "CRY_AGGRON",          "Dark/Steel blade final"),
    ("SPECIES_BRONZOR",            "CRY_BELDUM",          "Steel/Psychic disc small"),
    ("SPECIES_BRONZONG",           "CRY_METANG",          "Steel/Psychic bell final"),
    ("SPECIES_GALARIAN_MEOWTH",    "SPECIES_MEOWTH",      "Same family"),
    ("SPECIES_PERRSERKER",         "SPECIES_PERSIAN",     "Same family"),
    ("SPECIES_ALOLAN_MEOWTH",      "SPECIES_MEOWTH",      "Same family"),
    ("SPECIES_ALOLAN_PERSIAN",     "SPECIES_PERSIAN",     "Same family"),
    ("SPECIES_DURALUDON",          "CRY_AGGRON",          "Steel/Dragon tower"),
    ("SPECIES_ARCHALUDON",         "CRY_METAGROSS",       "Steel/Dragon bridge"),
    ("SPECIES_TINKATINK",          "SPECIES_CLEFAIRY",    "Fairy/Steel hammer small"),
    ("SPECIES_TINKATUFF",          "SPECIES_CLEFABLE",    "Fairy/Steel hammer mid"),
    ("SPECIES_TINKATON",           "CRY_METAGROSS",       "Fairy/Steel hammer final"),
    ("SPECIES_ALOLAN_DIGLETT",     "SPECIES_DIGLETT",     "Same family"),
    ("SPECIES_ALOLAN_DUGTRIO",     "SPECIES_DUGTRIO",     "Same family"),
    ("SPECIES_MAGNEZONE",          "SPECIES_MAGNETON",    "Same family"),
    ("SPECIES_FLABEBE",            "SPECIES_CLEFAIRY",    "Fairy flower small"),
    ("SPECIES_FLOETTE",            "SPECIES_CLEFABLE",    "Fairy flower mid"),
    ("SPECIES_FLORGES",            "SPECIES_CLEFABLE",    "Fairy flower final"),
    ("SPECIES_ALOLAN_VULPIX",      "SPECIES_VULPIX",      "Same family"),
    ("SPECIES_ALOLAN_NINETALES",   "SPECIES_NINETALES",   "Same family"),
    # 567 - Sinnoh legends
    ("SPECIES_UXIE",               "CRY_JIRACHI",         "Psychic lake trio"),
    ("SPECIES_MESPRIT",            "CRY_JIRACHI",         "Psychic lake trio"),
    ("SPECIES_AZELF",              "CRY_JIRACHI",         "Psychic lake trio"),
    ("SPECIES_DIALGA",             "CRY_RAYQUAZA",        "Steel/Dragon time god"),
    ("SPECIES_PALKIA",             "CRY_KYOGRE",          "Water/Dragon space god"),
    ("SPECIES_HEATRAN",            "CRY_GROUDON",         "Fire/Steel lava legendary"),
    ("SPECIES_REGIGIGAS",          "CRY_REGISTEEL",       "Normal Regi-leader"),
    ("SPECIES_GIRATINA",           "CRY_RAYQUAZA",        "Ghost/Dragon distortion"),
    ("SPECIES_CRESSELIA",          "CRY_LATIAS",          "Psychic moon legendary"),
    ("SPECIES_PHIONE",             "CRY_KYOGRE",          "Water sea spirit small"),
    ("SPECIES_MANAPHY",            "CRY_KYOGRE",          "Water sea prince"),
    ("SPECIES_SHAYMIN",            "CRY_JIRACHI",         "Grass/Flying hedgehog legend"),
    ("SPECIES_ARCEUS",             "CRY_RAYQUAZA",        "Normal god of all"),
]

def main():
    print("#define STEP5_MON_SPECIES_START SPECIES_SHINX")
    print()
    print("static const u16 sStep5SpeciesIdToCryId[] =")
    print("{")
    for species, cry, comment in MAPPINGS:
        idx = f"[{species} - STEP5_MON_SPECIES_START]"
        print(f"    {idx:<52} = {cry},  /* {comment} */")
    print("};")

if __name__ == "__main__":
    main()
