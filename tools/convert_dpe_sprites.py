#!/usr/bin/env python3
"""
Convert DPE Gen 9 sprites to FireRed GBA format for Cynthia's Crown.

Source: /dev/shm/dpe/graphics/
- frontspr/gFrontSprite###Name.png  → front sprite + normal palette
- backspr/gBackShinySprite###Name.png → back sprite + shiny palette
- pokeicon/gIconSprite###Name.png    → icon

For each species this script:
1. Copies the DPE PNGs into graphics/pokemon/species_dir/
2. Extracts JASC palettes from the PNGs
3. Deletes stale compiled files so `make` rebuilds them
"""

import os
import sys
import shutil
from PIL import Image

DPE_DIR = "/dev/shm/dpe/graphics"
FRONTSPR = os.path.join(DPE_DIR, "frontspr")
BACKSPR  = os.path.join(DPE_DIR, "backspr")
ICONDIR  = os.path.join(DPE_DIR, "pokeicon")
PROJ_GFX = "graphics/pokemon"

# Full mapping: our species dir name → DPE sprite filename stem (number+name)
# Format: "our_dir": "DPE_stem"  where DPE files are gFrontSprite{stem}.png
SPECIES_MAP = {
    # Step 5 species (416-579) only — Step 1 (412-415) already have real sprites
    "luxio":               "457Luxio",
    "luxray":              "458Luxray",
    "fraxure":             "664Fraxure",
    "haxorus":             "665Haxorus",
    "doublade":            "788Doublade",
    "aegislash":           "789Aegislash",
    "galarian_linoone":    "1227LinooneG",
    "obstagoon":           "1154Obstagoon",
    "starly":              "449Starly",
    "staravia":            "450Staravia",
    "staraptor":           "451Staraptor",
    "munchlax":            "499Munchlax",
    "porygon_z":           "527PorygonZ",
    "hisuian_zorua":       "1244ZoruaH",
    "hisuian_zoroark":     "1245ZoroarkH",
    "fletchling":          "769Fletchling",
    "fletchinder":         "770Fletchinder",
    "talonflame":          "771Talonflame",
    "ursaluna":            "1253Ursaluna",
    "salandit":            "974Salandit",
    "salazzle":            "975Salazzle",
    "litwick":             "660Litwick",
    "lampent":             "661Lampent",
    "chandelure":          "662Chandelure",
    "chimchar":            "443Chimchar",
    "monferno":            "444Monferno",
    "infernape":           "445Infernape",
    "piplup":              "446Piplup",
    "prinplup":            "447Prinplup",
    "empoleon":            "448Empoleon",
    "buizel":              "471Buizel",
    "floatzel":            "472Floatzel",
    "magmortar":           "520Magmortar",
    "electivire":          "519Electivire",
    "rotom":               "532Rotom",
    "rotom_heat":          "713RotomHeat",
    "rotom_wash":          "714RotomWash",
    "rotom_frost":         "715RotomFrost",
    "rotom_fan":           "716RotomFan",
    "rotom_mow":           "717RotomMow",
    "toxel":               "1140Toxel",
    "toxtricity":          "1141Toxtricity",
    "tynamo":              "655Tynamo",
    "eelektrik":           "656Eelektrik",
    "eelektross":          "657Eelektross",
    "roserade":            "460Roserade",
    "tangrowth":           "518Tangrowth",
    "leafeon":             "523Leafeon",
    "glaceon":             "524Glaceon",
    "sylveon":             "808Sylveon",
    "ferroseed":           "650Ferroseed",
    "ferrothorn":          "651Ferrothorn",
    "pumpkaboo":           "818Pumpkaboo",
    "gourgeist":           "819Gourgeist",
    "phantump":            "816Phantump",
    "trevenant":           "817Trevenant",
    "galarian_mr_mime":    "1220MrMimeG",
    "mr_rime":             "1158MrRime",
    "mamoswine":           "526Mamoswine",
    "froslass":            "531Froslass",
    "weavile":             "514Weavile",
    "galarian_darumaka":   "1229DarumakaG",
    "galarian_darmanitan": "1230DarmanitanG",
    "annihilape":          "1341Annihilape",
    "galarian_farfetchd":  "1217FarfetchdG",
    "sirfetchd":           "1157Sirfetchd",
    "pancham":             "782Pancham",
    "pangoro":             "783Pangoro",
    "croagunk":            "506Croagunk",
    "toxicroak":           "507Toxicroak",
    "riolu":               "500Riolu",
    "lucario":             "501Lucario",
    "scraggy":             "612Scraggy",
    "scrafty":             "613Scrafty",
    "skrelp":              "798Skrelp",
    "dragalge":            "799Dragalge",
    "gible":               "496Gible",
    "gabite":              "497Gabite",
    "garchomp":            "498Garchomp",
    "gliscor":             "525Gliscor",
    "rhyperior":           "517Rhyperior",
    "drilbur":             "582Drilbur",
    "excadrill":           "583Excadrill",
    "sandile":             "604Sandile",
    "krokorok":            "605Krokorok",
    "krookodile":          "606Krookodile",
    "golett":              "675Golett",
    "golurk":              "676Golurk",
    "honchkrow":           "483Honchkrow",
    "togekiss":            "521Togekiss",
    "yanmega":             "522Yanmega",
    "hawlucha":            "809Hawlucha",
    "rookidee":            "1113Rookidee",
    "corvisquire":         "1114Corvisquire",
    "corviknight":         "1115Corviknight",
    "gallade":             "528Gallade",
    "inkay":               "794Inkay",
    "malamar":             "795Malamar",
    "larvesta":            "689Larvesta",
    "volcarona":           "690Volcarona",
    "grubbin":             "953Grubbin",
    "charjabug":           "954Charjabug",
    "vikavolt":            "955Vikavolt",
    "sizzlipede":          "1142Sizzlipede",
    "centiskorch":         "1143Centiskorch",
    "kleavor":             "1252Kleavor",
    "hisuian_growlithe":   "1234GrowlitheH",
    "hisuian_arcanine":    "1235ArcanineH",
    "alolan_geodude":      "1031GeodudeA",
    "alolan_graveler":     "1032GravelerA",
    "alolan_golem":        "1033GolemA",
    "probopass":           "529Probopass",
    "rockruff":            "961Rockruff",
    "lycanroc":            "962Lycanroc",
    "dreepy":              "1177Dreepy",
    "drakloak":            "1178Drakloak",
    "dragapult":           "1179Dragapult",
    "basculin":            "603BasculinRed",
    "basculegion":         "1254BasculegionM",
    "alolan_exeggutor":    "1037ExeggutorA",
    "deino":               "686Deino",
    "zweilous":            "687Zweilous",
    "hydreigon":           "688Hydreigon",
    "goomy":               "812Goomy",
    "sliggoo":             "813Sliggoo",
    "goodra":              "814Goodra",
    "darkrai":             "544Darkrai",
    "zorua":               "623Zorua",
    "zoroark":             "624Zoroark",
    "pawniard":            "677Pawniard",
    "bisharp":             "678Bisharp",
    "kingambit":           "1346Kingambit",
    "bronzor":             "489Bronzor",
    "bronzong":            "490Bronzong",
    "galarian_meowth":     "1212MeowthG",
    "perrserker":          "1155Perrserker",
    "alolan_meowth":       "1029MeowthA",
    "alolan_persian":      "1030PersianA",
    "duraludon":           "1176Duraludon",
    "archaludon":          "1392Archaludon",
    "tinkatink":           "1316Tinkatink",
    "tinkatuff":           "1317Tinkatuff",
    "tinkaton":            "1318Tinkaton",
    "alolan_diglett":      "1027DiglettA",
    "alolan_dugtrio":      "1028DugtrioA",
    "magnezone":           "515Magnezone",
    "flabebe":             "777Flabebe",
    "floette":             "778Floette",
    "florges":             "779Florges",
    "alolan_vulpix":       "1025VulpixA",
    "alolan_ninetales":    "1026NinetalesA",
    "uxie":                "533Uxie",
    "mesprit":             "534Mesprit",
    "azelf":               "535Azelf",
    "dialga":              "536Dialga",
    "palkia":              "537Palkia",
    "heatran":             "538Heatran",
    "regigigas":           "539Regigigas",
    "giratina":            "540Giratina",
    "cresselia":           "541Cresselia",
    "phione":              "542Phione",
    "manaphy":             "543Manaphy",
    "shaymin":             "545Shaymin",
    "arceus":              "546Arceus",
}


def png_to_jasc_pal(png_path: str) -> str:
    """Extract 16-color indexed palette from PNG and return as JASC-PAL text."""
    img = Image.open(png_path).convert("P")
    raw = img.getpalette()  # [R,G,B, R,G,B, ...] × 256
    lines = ["JASC-PAL", "0100", "16"]
    for i in range(16):
        r, g, b = raw[i*3], raw[i*3+1], raw[i*3+2]
        lines.append(f"{r} {g} {b}")
    return "\n".join(lines) + "\n"


def delete_compiled(species_dir: str) -> None:
    """Remove stale compiled files so make rebuilds them."""
    for ext in ("front.4bpp", "front.4bpp.lz",
                "back.4bpp", "back.4bpp.lz",
                "normal.gbapal", "normal.gbapal.lz",
                "shiny.gbapal", "shiny.gbapal.lz",
                "icon.4bpp"):
        p = os.path.join(species_dir, ext)
        if os.path.exists(p):
            os.remove(p)


def process_species(dirname: str, dpe_stem: str) -> bool:
    """Convert one species. Returns True on success, False if DPE file missing."""
    front_src = os.path.join(FRONTSPR, f"gFrontSprite{dpe_stem}.png")
    back_src  = os.path.join(BACKSPR,  f"gBackShinySprite{dpe_stem}.png")
    icon_src  = os.path.join(ICONDIR,  f"gIconSprite{dpe_stem}.png")
    dest_dir  = os.path.join(PROJ_GFX, dirname)

    if not os.path.exists(front_src):
        print(f"  MISSING front: {front_src}")
        return False
    if not os.path.isdir(dest_dir):
        print(f"  MISSING dest dir: {dest_dir}")
        return False

    # Front sprite → front.png + normal.pal
    shutil.copy2(front_src, os.path.join(dest_dir, "front.png"))
    normal_pal = png_to_jasc_pal(front_src)
    with open(os.path.join(dest_dir, "normal.pal"), "w") as f:
        f.write(normal_pal)

    # Back sprite (shiny-colored) → back.png + shiny.pal
    if os.path.exists(back_src):
        shutil.copy2(back_src, os.path.join(dest_dir, "back.png"))
        shiny_pal = png_to_jasc_pal(back_src)
    else:
        # Fall back: use front as back, normal palette as shiny
        shutil.copy2(front_src, os.path.join(dest_dir, "back.png"))
        shiny_pal = normal_pal
    with open(os.path.join(dest_dir, "shiny.pal"), "w") as f:
        f.write(shiny_pal)

    # Icon
    if os.path.exists(icon_src):
        shutil.copy2(icon_src, os.path.join(dest_dir, "icon.png"))
    else:
        # Fall back: keep existing icon (shinx placeholder)
        pass

    # Remove stale compiled files so make rebuilds
    delete_compiled(dest_dir)
    return True


def main():
    ok = 0
    fail = 0
    for dirname, stem in SPECIES_MAP.items():
        result = process_species(dirname, stem)
        if result:
            ok += 1
            print(f"  OK: {dirname} ← DPE {stem}")
        else:
            fail += 1

    print(f"\nDone: {ok} converted, {fail} failed.")
    print("\nNow run:  make modern")
    print("This will recompile all .4bpp, .gbapal, .lz files from the new PNGs.")


if __name__ == "__main__":
    main()
