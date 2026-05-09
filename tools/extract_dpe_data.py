#!/usr/bin/env python3
"""
Extract species and learnset data from DPE repo and generate FR-compatible
data files for all 164 new Step-5 species.

Run from repo root:
  python3 tools/extract_dpe_data.py
"""

import re, os, sys

DPE_BASE   = "/dev/shm/dpe/src/Base_Stats.c"
DPE_LEARN  = "/dev/shm/dpe/src/Learnsets.c"
DPE_DEX    = "/dev/shm/dpe/src/Pokedex_Data_Table.c"
FR_MOVES   = "include/constants/moves.h"
FR_ABILITIES = "include/constants/abilities.h"

# ───────────────────────────────────────────────────────────────────
# Step 1: Build move name mapping  DPE_NAME → FR_NAME
# Both files use  #define MOVE_XXXX  <number>
# We match by numeric value.
# ───────────────────────────────────────────────────────────────────
def build_move_map(dpe_moves_h, fr_moves_h):
    """Returns (dpe_to_fr, fr_valid_set)."""
    def load(path):
        d = {}
        for line in open(path):
            m = re.match(r'^\s*#define\s+(MOVE_\w+)\s+(0x[0-9a-fA-F]+|\d+)', line)
            if m:
                name, val = m.group(1), int(m.group(2), 0)
                d[val] = name
        return d
    # DPE moves file
    dpe_moves_file = "/dev/shm/dpe/include/moves.h"
    dpe_by_num = load(dpe_moves_file)
    fr_by_num  = load(fr_moves_h)
    fr_valid   = set(fr_by_num.values())
    # Mapping: dpe_name → fr_name (by matching numeric value)
    dpe_to_fr = {}
    for num, dpe_name in dpe_by_num.items():
        if num in fr_by_num:
            dpe_to_fr[dpe_name] = fr_by_num[num]
    return dpe_to_fr, fr_valid

# ───────────────────────────────────────────────────────────────────
# Step 2: Build ability mapping  DPE_ABILITY → FR_ABILITY
# ───────────────────────────────────────────────────────────────────
def build_ability_map(fr_abilities_h):
    """Map DPE ability names to closest FR equivalents (by number, then fallback)."""
    dpe_abilities_file = "/dev/shm/dpe/include/abilities.h"
    def load(path):
        d = {}
        for line in open(path):
            m = re.match(r'^\s*#define\s+(ABILITY_\w+)\s+(\d+)', line)
            if m:
                name, val = m.group(1), int(m.group(2))
                d[val] = name
        return d
    fr_by_num  = load(fr_abilities_h)
    dpe_by_num = {}
    if os.path.exists(dpe_abilities_file):
        dpe_by_num = load(dpe_abilities_file)
    # Reverse: dpe_name → number
    dpe_name_to_num = {}
    for line in open(dpe_abilities_file if os.path.exists(dpe_abilities_file) else fr_abilities_h):
        m = re.match(r'^\s*#define\s+(ABILITY_\w+)\s+(\d+)', line)
        if m:
            dpe_name_to_num[m.group(1)] = int(m.group(2))
    fr_valid_names = set(fr_by_num.values())
    fr_valid_names.add("ABILITY_NONE")
    # Map DPE ability name → FR ability name
    dpe_to_fr = {}
    for dpe_name, num in dpe_name_to_num.items():
        if num in fr_by_num:
            dpe_to_fr[dpe_name] = fr_by_num[num]
        else:
            dpe_to_fr[dpe_name] = "ABILITY_NONE"
    return dpe_to_fr, fr_valid_names

# ───────────────────────────────────────────────────────────────────
# Step 3: Parse DPE Base_Stats.c
# Returns dict: SPECIES_MACRO → {field: value}
# ───────────────────────────────────────────────────────────────────
def parse_base_stats(path):
    text = open(path).read()
    entries = {}
    # Split on "[SPECIES_..." block starts
    blocks = re.split(r'\[SPECIES_', text)
    for block in blocks[1:]:
        m_head = re.match(r'(\w+)\]\s*=\s*\{', block)
        if not m_head:
            continue
        macro = "SPECIES_" + m_head.group(1)
        fields = {}
        for fm in re.finditer(r'\.(\w+)\s*=\s*([^,\n]+)', block):
            field, val = fm.group(1).strip(), fm.group(2).strip()
            fields[field] = val
        entries[macro] = fields
    return entries

# ───────────────────────────────────────────────────────────────────
# Step 4: Parse DPE Learnsets.c
# Returns dict: learnset_var_name → [(level, dpe_move_name), ...]
# ───────────────────────────────────────────────────────────────────
def parse_learnsets(path):
    text = open(path).read()
    learnsets = {}
    # Match: static const struct LevelUpMove sXxxLevelUpLearnset[] = {
    blocks = re.split(r'static\s+const\s+struct\s+LevelUpMove\s+', text)
    for block in blocks[1:]:
        m_head = re.match(r'(s\w+LevelUpLearnset)\s*\[\]\s*=\s*\{', block)
        if not m_head:
            continue
        var_name = m_head.group(1)
        moves = []
        for mm in re.finditer(r'LEVEL_UP_MOVE\s*\(\s*(\d+)\s*,\s*(MOVE_\w+)\s*\)', block):
            moves.append((int(mm.group(1)), mm.group(2)))
        learnsets[var_name] = moves
    return learnsets

# ───────────────────────────────────────────────────────────────────
# Step 5: Parse DPE Pokedex_Data_Table.c
# Returns dict: NATIONAL_DEX_MACRO → {category, height, weight, description}
# ───────────────────────────────────────────────────────────────────
def parse_dex_data(path):
    text = open(path).read()
    entries = {}
    blocks = re.split(r'\[DEX_', text)
    for block in blocks[1:]:
        m_head = re.match(r'(\w+)\]\s*=\s*\{', block)
        if not m_head:
            continue
        macro = "NATIONAL_DEX_" + m_head.group(1)
        fields = {}
        for fm in re.finditer(r'\.(\w+)\s*=\s*([^,\n]+)', block):
            field, val = fm.group(1).strip(), fm.group(2).strip()
            fields[field] = val
        # Extract description text if present
        m_desc = re.search(r'_\("([^"]+)"\)', block)
        if m_desc:
            fields['desc_text'] = m_desc.group(1)
        entries[macro] = fields
    return entries

# ───────────────────────────────────────────────────────────────────
# Species we need to add (same list as fix_step5_species.py)
# Format: (FR_MACRO, display_name, national_dex_macro, dpe_learnset_var)
# ───────────────────────────────────────────────────────────────────
# Map FR species macro → DPE learnset variable name
# (DPE uses  sLuxioLevelUpLearnset  for SPECIES_LUXIO, etc.)
def fr_macro_to_dpe_learnset_var(macro):
    """Convert SPECIES_LUXIO → sLuxioLevelUpLearnset"""
    name = macro.replace("SPECIES_", "")
    parts = name.split("_")
    camel = "".join(p.capitalize() for p in parts)
    return f"s{camel}LevelUpLearnset"

# All 164 new species in FR order
NEW_SPECIES_MACROS = [
    "SPECIES_LUXIO","SPECIES_LUXRAY","SPECIES_FRAXURE","SPECIES_HAXORUS",
    "SPECIES_DOUBLADE","SPECIES_AEGISLASH","SPECIES_GALARIAN_LINOONE","SPECIES_OBSTAGOON",
    "SPECIES_STARLY","SPECIES_STARAVIA","SPECIES_STARAPTOR",
    "SPECIES_MUNCHLAX","SPECIES_PORYGON_Z",
    "SPECIES_HISUIAN_ZORUA","SPECIES_HISUIAN_ZOROARK",
    "SPECIES_FLETCHLING","SPECIES_FLETCHINDER","SPECIES_TALONFLAME",
    "SPECIES_URSALUNA",
    "SPECIES_SALANDIT","SPECIES_SALAZZLE",
    "SPECIES_LITWICK","SPECIES_LAMPENT","SPECIES_CHANDELURE",
    "SPECIES_CHIMCHAR","SPECIES_MONFERNO","SPECIES_INFERNAPE",
    "SPECIES_PIPLUP","SPECIES_PRINPLUP","SPECIES_EMPOLEON",
    "SPECIES_BUIZEL","SPECIES_FLOATZEL",
    "SPECIES_MAGMORTAR","SPECIES_ELECTIVIRE",
    "SPECIES_ROTOM","SPECIES_ROTOM_HEAT","SPECIES_ROTOM_WASH",
    "SPECIES_ROTOM_FROST","SPECIES_ROTOM_FAN","SPECIES_ROTOM_MOW",
    "SPECIES_TOXEL","SPECIES_TOXTRICITY",
    "SPECIES_TYNAMO","SPECIES_EELEKTRIK","SPECIES_EELEKTROSS",
    "SPECIES_ROSERADE","SPECIES_TANGROWTH",
    "SPECIES_LEAFEON","SPECIES_GLACEON","SPECIES_SYLVEON",
    "SPECIES_FERROSEED","SPECIES_FERROTHORN",
    "SPECIES_PUMPKABOO","SPECIES_GOURGEIST",
    "SPECIES_PHANTUMP","SPECIES_TREVENANT",
    "SPECIES_GALARIAN_MR_MIME","SPECIES_MR_RIME",
    "SPECIES_MAMOSWINE","SPECIES_FROSLASS","SPECIES_WEAVILE",
    "SPECIES_GALARIAN_DARUMAKA","SPECIES_GALARIAN_DARMANITAN",
    "SPECIES_ANNIHILAPE",
    "SPECIES_GALARIAN_FARFETCHD","SPECIES_SIRFETCHD",
    "SPECIES_PANCHAM","SPECIES_PANGORO",
    "SPECIES_CROAGUNK","SPECIES_TOXICROAK",
    "SPECIES_RIOLU","SPECIES_LUCARIO",
    "SPECIES_SCRAGGY","SPECIES_SCRAFTY",
    "SPECIES_SKRELP","SPECIES_DRAGALGE",
    "SPECIES_GIBLE","SPECIES_GABITE","SPECIES_GARCHOMP",
    "SPECIES_GLISCOR","SPECIES_RHYPERIOR",
    "SPECIES_DRILBUR","SPECIES_EXCADRILL",
    "SPECIES_SANDILE","SPECIES_KROKOROK","SPECIES_KROOKODILE",
    "SPECIES_GOLETT","SPECIES_GOLURK",
    "SPECIES_HONCHKROW","SPECIES_TOGEKISS","SPECIES_YANMEGA",
    "SPECIES_HAWLUCHA",
    "SPECIES_ROOKIDEE","SPECIES_CORVISQUIRE","SPECIES_CORVIKNIGHT",
    "SPECIES_GALLADE",
    "SPECIES_INKAY","SPECIES_MALAMAR",
    "SPECIES_LARVESTA","SPECIES_VOLCARONA",
    "SPECIES_GRUBBIN","SPECIES_CHARJABUG","SPECIES_VIKAVOLT",
    "SPECIES_SIZZLIPEDE","SPECIES_CENTISKORCH",
    "SPECIES_KLEAVOR",
    "SPECIES_HISUIAN_GROWLITHE","SPECIES_HISUIAN_ARCANINE",
    "SPECIES_ALOLAN_GEODUDE","SPECIES_ALOLAN_GRAVELER","SPECIES_ALOLAN_GOLEM",
    "SPECIES_PROBOPASS",
    "SPECIES_ROCKRUFF","SPECIES_LYCANROC",
    "SPECIES_DREEPY","SPECIES_DRAKLOAK","SPECIES_DRAGAPULT",
    "SPECIES_BASCULIN","SPECIES_BASCULEGION",
    "SPECIES_ALOLAN_EXEGGUTOR",
    "SPECIES_DEINO","SPECIES_ZWEILOUS","SPECIES_HYDREIGON",
    "SPECIES_GOOMY","SPECIES_SLIGGOO","SPECIES_GOODRA",
    "SPECIES_DARKRAI",
    "SPECIES_ZORUA","SPECIES_ZOROARK",
    "SPECIES_PAWNIARD","SPECIES_BISHARP","SPECIES_KINGAMBIT",
    "SPECIES_BRONZOR","SPECIES_BRONZONG",
    "SPECIES_GALARIAN_MEOWTH","SPECIES_PERRSERKER",
    "SPECIES_ALOLAN_MEOWTH","SPECIES_ALOLAN_PERSIAN",
    "SPECIES_DURALUDON","SPECIES_ARCHALUDON",
    "SPECIES_TINKATINK","SPECIES_TINKATUFF","SPECIES_TINKATON",
    "SPECIES_ALOLAN_DIGLETT","SPECIES_ALOLAN_DUGTRIO",
    "SPECIES_MAGNEZONE",
    "SPECIES_FLABEBE","SPECIES_FLOETTE","SPECIES_FLORGES",
    "SPECIES_ALOLAN_VULPIX","SPECIES_ALOLAN_NINETALES",
    "SPECIES_UXIE","SPECIES_MESPRIT","SPECIES_AZELF",
    "SPECIES_DIALGA","SPECIES_PALKIA","SPECIES_HEATRAN",
    "SPECIES_REGIGIGAS","SPECIES_GIRATINA","SPECIES_CRESSELIA",
    "SPECIES_PHIONE","SPECIES_MANAPHY","SPECIES_SHAYMIN","SPECIES_ARCEUS",
]

# Also the 4 Step-1 species that need correct learnsets
STEP1_SPECIES_MACROS = [
    "SPECIES_SHINX", "SPECIES_AXEW", "SPECIES_HONEDGE", "SPECIES_GALARIAN_ZIGZAGOON",
]


def fr_learnset_varname(macro):
    """SPECIES_GALARIAN_LINOONE → sGalarianLinooneLevelUpLearnset (matches our current FR file)"""
    name = macro.replace("SPECIES_", "")
    parts = name.split("_")
    camel = "".join(p.capitalize() for p in parts)
    return f"s{camel}LevelUpLearnset"


def dpe_learnset_varname(macro):
    """SPECIES_GALARIAN_LINOONE → sGalarianLinooneLevelUpLearnset (same in DPE)"""
    return fr_learnset_varname(macro)


def convert_moves(dpe_moves, move_map, fr_valid):
    """Filter and convert [(level, dpe_move)] to valid FR moves."""
    result = []
    for (lvl, dpe_mv) in dpe_moves:
        fr_mv = move_map.get(dpe_mv)
        if fr_mv and fr_mv in fr_valid and fr_mv != "MOVE_NONE":
            result.append((lvl, fr_mv))
    return result


def gen_learnset_append(all_macros, learnsets, move_map, fr_valid):
    lines = ["\n// === Cynthia's Crown Step 5 learnsets (from DPE, Gen-3 filtered) ===\n\n"]
    for macro in all_macros:
        varname = fr_learnset_varname(macro)
        dpe_var = dpe_learnset_varname(macro)
        dpe_moves = learnsets.get(dpe_var, [])
        fr_moves = convert_moves(dpe_moves, move_map, fr_valid)
        # Ensure at least 2 moves
        if not fr_moves:
            fr_moves = [(1, "MOVE_TACKLE"), (1, "MOVE_GROWL")]
        elif len(fr_moves) == 1:
            fr_moves.append((5, "MOVE_GROWL"))
        lines.append(f"static const u16 {varname}[] = {{\n")
        for (lvl, mv) in fr_moves:
            lines.append(f"    LEVEL_UP_MOVE({lvl}, {mv}),\n")
        lines.append(f"    LEVEL_UP_END\n}};\n\n")
    return "".join(lines)


def gen_learnset_pointers(all_macros):
    lines = ["    // === Cynthia's Crown Step 5 learnset pointers ===\n"]
    for macro in all_macros:
        varname = fr_learnset_varname(macro)
        lines.append(f"    [{macro}] = {varname},\n")
    return "".join(lines)


def gen_tmhm(all_macros):
    """Generate TM/HM learnsets using type-based approach."""
    TYPE_TMS = {
        "TYPE_NORMAL":   "TMHM(TM17_PROTECT) | TMHM(TM21_FRUSTRATION) | TMHM(TM27_RETURN) | TMHM(TM32_DOUBLE_TEAM) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT) | TMHM(TM46_THIEF)",
        "TYPE_FIRE":     "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM11_SUNNY_DAY) | TMHM(TM17_PROTECT) | TMHM(TM35_FLAMETHROWER) | TMHM(TM38_FIRE_BLAST) | TMHM(TM44_REST) | TMHM(TM50_OVERHEAT)",
        "TYPE_WATER":    "TMHM(TM03_WATER_PULSE) | TMHM(TM06_TOXIC) | TMHM(TM07_HAIL) | TMHM(TM13_ICE_BEAM) | TMHM(TM17_PROTECT) | TMHM(TM18_RAIN_DANCE) | TMHM(TM44_REST) | TMHM(HM03_SURF) | TMHM(HM07_WATERFALL)",
        "TYPE_GRASS":    "TMHM(TM06_TOXIC) | TMHM(TM09_BULLET_SEED) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM11_SUNNY_DAY) | TMHM(TM17_PROTECT) | TMHM(TM19_GIGA_DRAIN) | TMHM(TM22_SOLAR_BEAM) | TMHM(TM44_REST)",
        "TYPE_ELECTRIC": "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM21_FRUSTRATION) | TMHM(TM24_THUNDERBOLT) | TMHM(TM25_THUNDER) | TMHM(TM34_SHOCK_WAVE) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT)",
        "TYPE_ICE":      "TMHM(TM06_TOXIC) | TMHM(TM07_HAIL) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM13_ICE_BEAM) | TMHM(TM14_BLIZZARD) | TMHM(TM17_PROTECT) | TMHM(TM44_REST)",
        "TYPE_FIGHTING": "TMHM(TM06_TOXIC) | TMHM(TM08_BULK_UP) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM31_BRICK_BREAK) | TMHM(TM44_REST) | TMHM(HM04_STRENGTH)",
        "TYPE_POISON":   "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM36_SLUDGE_BOMB) | TMHM(TM44_REST)",
        "TYPE_GROUND":   "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM26_EARTHQUAKE) | TMHM(TM28_DIG) | TMHM(TM37_SANDSTORM) | TMHM(TM44_REST) | TMHM(HM06_ROCK_SMASH)",
        "TYPE_FLYING":   "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM21_FRUSTRATION) | TMHM(TM27_RETURN) | TMHM(TM40_AERIAL_ACE) | TMHM(TM44_REST) | TMHM(HM02_FLY)",
        "TYPE_PSYCHIC":  "TMHM(TM04_CALM_MIND) | TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM16_LIGHT_SCREEN) | TMHM(TM17_PROTECT) | TMHM(TM29_PSYCHIC) | TMHM(TM33_REFLECT) | TMHM(TM44_REST)",
        "TYPE_BUG":      "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM44_REST) | TMHM(TM46_THIEF) | TMHM(HM01_CUT)",
        "TYPE_ROCK":     "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM23_IRON_TAIL) | TMHM(TM37_SANDSTORM) | TMHM(TM39_ROCK_TOMB) | TMHM(TM44_REST) | TMHM(HM06_ROCK_SMASH)",
        "TYPE_GHOST":    "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM30_SHADOW_BALL) | TMHM(TM44_REST) | TMHM(TM46_THIEF) | TMHM(TM48_SKILL_SWAP)",
        "TYPE_DRAGON":   "TMHM(TM02_DRAGON_CLAW) | TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM15_HYPER_BEAM) | TMHM(TM17_PROTECT) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT)",
        "TYPE_DARK":     "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM12_TAUNT) | TMHM(TM17_PROTECT) | TMHM(TM30_SHADOW_BALL) | TMHM(TM44_REST) | TMHM(TM46_THIEF) | TMHM(TM49_SNATCH)",
        "TYPE_STEEL":    "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM23_IRON_TAIL) | TMHM(TM37_SANDSTORM) | TMHM(TM44_REST) | TMHM(HM06_ROCK_SMASH)",
        "TYPE_FAIRY":    "TMHM(TM06_TOXIC) | TMHM(TM10_HIDDEN_POWER) | TMHM(TM17_PROTECT) | TMHM(TM27_RETURN) | TMHM(TM44_REST) | TMHM(TM45_ATTRACT)",
    }
    lines = ["    // === Cynthia's Crown Step 5 TM/HM learnsets ===\n"]
    # We need type info - read from our already-fixed step5_species_info.inc
    types = get_types_from_species_info()
    for macro in all_macros:
        t1, t2 = types.get(macro, ("TYPE_NORMAL", "TYPE_NORMAL"))
        t1_tms = TYPE_TMS.get(t1, TYPE_TMS["TYPE_NORMAL"])
        if t2 != t1:
            t2_tms = TYPE_TMS.get(t2, "")
            combo = f"{t1_tms} | {t2_tms}" if t2_tms else t1_tms
        else:
            combo = t1_tms
        lines.append(f"    [{macro}] = TMHM_LEARNSET({combo}),\n\n")
    return "".join(lines)


def get_types_from_species_info():
    """Parse types from build/step5_species_info.inc."""
    types = {}
    text = open("build/step5_species_info.inc").read()
    blocks = re.split(r'\[SPECIES_', text)
    for block in blocks[1:]:
        m_head = re.match(r'(\w+)\]\s*=', block)
        if not m_head:
            continue
        macro = "SPECIES_" + m_head.group(1)
        m_types = re.search(r'\.types\s*=\s*\{(TYPE_\w+),\s*(TYPE_\w+)\}', block)
        if m_types:
            types[macro] = (m_types.group(1), m_types.group(2))
    return types


def gen_dex_entries(all_macros, dex_data, base_stats):
    """Generate pokedex_entries.h additions."""
    lines = ["    // === Cynthia's Crown Step 5 Pokedex Entries ===\n"]
    for macro in all_macros:
        nat = macro.replace("SPECIES_", "NATIONAL_DEX_")
        var_prefix = macro.replace("SPECIES_", "").replace("_", "")
        # Try to get data from DPE
        dpe_entry = dex_data.get(nat, {})
        cat = dpe_entry.get("categoryName", '"Unknown"')
        cat = cat.strip('_(")')
        h   = dpe_entry.get("height", "5")
        w   = dpe_entry.get("weight", "100")
        # Clean up the values
        try:
            h_val = int(h.strip())
        except:
            h_val = 5
        try:
            w_val = int(w.strip())
        except:
            w_val = 100
        lines.append(f"\n    [{nat}] =\n    {{\n")
        lines.append(f'        .categoryName = _("{cat}"),\n')
        lines.append(f"        .height = {h_val},\n")
        lines.append(f"        .weight = {w_val},\n")
        lines.append(f"        .description = g{var_prefix}PokedexText,\n")
        lines.append(f"        .unusedDescription = g{var_prefix}PokedexTextUnused,\n")
        lines.append(f"        .pokemonScale = 356,\n")
        lines.append(f"        .pokemonOffset = 17,\n")
        lines.append(f"        .trainerScale = 256,\n")
        lines.append(f"        .trainerOffset = 0,\n")
        lines.append(f"    }},\n")
    return "".join(lines)


def gen_dex_texts(all_macros, dex_data):
    """Generate pokedex text strings."""
    lines = ["\n// === Cynthia's Crown Step 5 Pokedex Texts ===\n\n"]
    types = get_types_from_species_info()
    for macro in all_macros:
        nat = macro.replace("SPECIES_", "NATIONAL_DEX_")
        var_prefix = macro.replace("SPECIES_", "").replace("_", "")
        dpe_entry = dex_data.get(nat, {})
        desc = dpe_entry.get("desc_text", "")
        t1 = types.get(macro, ("TYPE_NORMAL","TYPE_NORMAL"))[0].replace("TYPE_","").capitalize()
        if desc:
            # Truncate to FR limit (< 200 chars), split into two lines
            desc = desc.replace("\n", " ").strip()
            if len(desc) > 100:
                desc = desc[:97] + "..."
            # Split into two lines of ~50 chars each
            words = desc.split()
            line1, line2 = [], []
            for w in words:
                if len(" ".join(line1 + [w])) <= 50:
                    line1.append(w)
                else:
                    line2.append(w)
            l1 = " ".join(line1)
            l2 = " ".join(line2)
            if l2:
                text = f"{l1}\\n{l2}"
            else:
                text = l1
        else:
            name = macro.replace("SPECIES_", "").replace("_", " ").title()
            text = f"A {t1}-type Pokemon.\\nIts true power remains\\nunknown."
        lines.append(f"const u8 g{var_prefix}PokedexText[] = _(\n")
        lines.append(f'    "{text}\\n"\n')
        lines.append(f'    "$");\n\n')
        lines.append(f"const u8 g{var_prefix}PokedexTextUnused[] = _(\"\");\n\n")
    return "".join(lines)


def append_before_closing_brace(filepath, content, marker="};"):
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
    print("Building move mapping...")
    move_map, fr_valid = build_move_map("/dev/shm/dpe/include/moves.h", FR_MOVES)
    print(f"  {len(move_map)} DPE moves mapped, {len(fr_valid)} valid FR moves")

    print("Building ability mapping...")
    ab_map, fr_ab_valid = build_ability_map(FR_ABILITIES)
    print(f"  {len(ab_map)} DPE abilities mapped")

    print("Parsing DPE Base_Stats.c...")
    base_stats = parse_base_stats(DPE_BASE)
    print(f"  {len(base_stats)} species found")

    print("Parsing DPE Learnsets.c...")
    learnsets = parse_learnsets(DPE_LEARN)
    print(f"  {len(learnsets)} learnsets found")

    print("Parsing DPE Pokedex data...")
    dex_data = parse_dex_data(DPE_DEX)
    print(f"  {len(dex_data)} dex entries found")

    all_macros = NEW_SPECIES_MACROS  # Only the 164 NEW species (not Step-1, they already have learnsets)

    # Check which species are missing learnsets in DPE
    missing = [m for m in all_macros if dpe_learnset_varname(m) not in learnsets]
    if missing:
        print(f"  Warning: No DPE learnset for: {missing[:10]}...")

    print("\nGenerating learnsets...")
    ls_content = gen_learnset_append(all_macros, learnsets, move_map, fr_valid)
    ls_path = "src/data/pokemon/level_up_learnsets.h"
    if "sLuxioLevelUpLearnset" not in open(ls_path).read():
        append_to_file(ls_path, ls_content)
    else:
        print(f"  Skipping {ls_path} (already updated)")

    print("\nGenerating learnset pointers...")
    lp_path = "src/data/pokemon/level_up_learnset_pointers.h"
    if "SPECIES_LUXIO" not in open(lp_path).read():
        append_before_closing_brace(lp_path, gen_learnset_pointers(all_macros))
    else:
        print(f"  Skipping {lp_path} (already updated)")

    print("\nGenerating TM/HM learnsets...")
    tm_path = "src/data/pokemon/tmhm_learnsets.h"
    if "SPECIES_LUXIO" not in open(tm_path).read():
        append_before_closing_brace(tm_path, gen_tmhm(all_macros))
    else:
        print(f"  Skipping {tm_path} (already updated)")

    print("\nGenerating Pokedex texts...")
    dex_texts = gen_dex_texts(all_macros, dex_data)
    fr_path = "src/data/pokemon/pokedex_text_fr.h"
    if "LUXIO" not in open(fr_path).read():
        append_to_file(fr_path, dex_texts)
    else:
        print(f"  Skipping {fr_path} (already updated)")

    # LG text file uses same texts
    lg_path = "src/data/pokemon/pokedex_text_lg.h"
    if "LUXIO" not in open(lg_path).read():
        append_to_file(lg_path, dex_texts)
    else:
        print(f"  Skipping {lg_path} (already updated)")

    print("\nGenerating Pokedex entries...")
    pe_path = "src/data/pokemon/pokedex_entries.h"
    if "NATIONAL_DEX_LUXIO" not in open(pe_path).read():
        append_before_closing_brace(pe_path, gen_dex_entries(all_macros, dex_data, base_stats))
    else:
        print(f"  Skipping {pe_path} (already updated)")

    print("\nAll done!")


if __name__ == "__main__":
    main()
