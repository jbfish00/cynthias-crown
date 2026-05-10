#!/usr/bin/env python3
"""Patch the 141 'Unknown' Pokedex entries for Step 5 species.

Updates:
  src/data/pokemon/pokedex_entries.h  — categoryName, height, weight
  src/data/pokemon/pokedex_text_fr.h  — replaces placeholder text
  src/data/pokemon/pokedex_text_lg.h  — same as FR text

Run from repo root:
  python3 tools/gen_pokedex_entries.py
"""

import re

# ──────────────────────────────────────────────────────────────────────────────
# Species data: SPECIES_X -> (category_ALLCAPS, height_dm, weight_hg, description)
# description: exactly 3 lines separated by \n, each line ≤40 chars
# ──────────────────────────────────────────────────────────────────────────────
DATA = {
    "LUXIO":              ("SPARK",         9,  305, "Strong electricity flows through the\nmuscles under its black fur. It stuns\nfoes with devastating jolts."),
    "LUXRAY":             ("GLEAM EYES",    11, 420, "It can see through objects to any\ndistance. When its eyes glow gold, it\ncan spot even distant prey."),
    "FRAXURE":            ("AXE JAW",       10, 360, "Its tusks can cut through most solid\nobjects. This Pokemon grooms its tusks\nafter every battle it fights."),
    "HAXORUS":            ("AXE JAW",       18, 1055,"Its steel-hard tusks can destroy\nanything. Though fierce in battle, it\nis quite tame toward its trainer."),
    "DOUBLADE":           ("SWORD",         5,  45,  "The two swords communicate via\ntelepathy. They cooperate to confuse\nenemies and deal the final blow."),
    "AEGISLASH":          ("ROYAL SWORD",   17, 530, "It absorbs the life force of those\nwho wield it. Legends claim it once\nmade kings from chosen ones."),
    "GALARIAN_LINOONE":   ("RUSHING",       5,  325, "It darts across the ground at over\n60 mph. It startles others by running\ntoward them at full speed."),
    "OBSTAGOON":          ("BLOCKING",      16, 460, "It evolved from Linoone, hardened\nby Galar's harsh environment. It\nchallenges foes with a daunting roar."),
    "STARLY":             ("STARLING",      3,  20,  "It forms large flocks and is commonly\nseen in fields. Small and weak, it\nseeks safety in numbers."),
    "STARAVIA":           ("STARLING",      6,  155, "It inhabits forests and fields.\nAggressive by nature, it quickly\nattacks anything entering its territory."),
    "STARAPTOR":          ("PREDATOR",      12, 249, "It develops sharp claws and a bold\nattitude. Even when outnumbered, it\nshows no fear whatsoever."),
    "MUNCHLAX":           ("BIG EATER",     6,  1050,"It swallows whole large amounts of\nfood without tasting or chewing. It\ncaches food all over its body."),
    "PORYGON_Z":          ("VIRTUAL",       9,  340, "Additional programming was installed\nto make it more useful. It began\nbehaving oddly after the upgrade."),
    "HISUIAN_ZORUA":      ("TRICKY FOX",    7,  125, "A Zorua that could not return home.\nIts illusions reflect painful memories\nof a sorrowful past."),
    "HISUIAN_ZOROARK":    ("ILLUSION FOX",  16, 731, "Its fearsome illusions are fueled by\nsorrow and rage. Those who see them\nare driven half-mad with grief."),
    "FLETCHLING":         ("TINY ROBIN",    3,  17,  "Despite its mild appearance, it is\nquite ferocious. It flies swiftly and\npecks relentlessly at rivals."),
    "FLETCHINDER":        ("EMBER BIRD",    7,  160, "The hotter the flame sac, the more\npowerfully it can fly. Its swiftness\nin battle is unmatched."),
    "TALONFLAME":         ("SCORCHING",     12, 193, "It dives at enemies at 310 mph,\nraking them with its talons. Its\ndiving speed outdoes any other bird."),
    "URSALUNA":           ("PEAT",          24, 3000,"It plows through snow and ice with\nits stout body. Residing in peatlands,\nit is rarely encountered."),
    "SALANDIT":           ("TOXIC LIZARD",  6,  48,  "It burns its bodily fluids to create\npoisonous gas. Males attract females\nwith pheromones in the smoke."),
    "SALAZZLE":           ("TOXIC LIZARD",  12, 222, "Only females exist, and they command\na harem of male Salandit. It gives\npheromones to confuse opponents."),
    "LITWICK":            ("CANDLE",        3,  31,  "Its flame burns weakly. It leads\ntravelers astray, then consumes the\nlife force of those who follow."),
    "LAMPENT":            ("LAMP",          6,  130, "This ominous Pokemon enters towns\nnear dusk and wanders the streets.\nIt steals spirits to fuel its fire."),
    "CHANDELURE":         ("LURING",        10, 343, "The flames that burn within it\nconsume the spirit, leaving the body\na hollow shell lacking any will."),
    "CHIMCHAR":           ("CHIMP",         5,  62,  "It has a flame sac on its rump that\nburns even in rain. It is fearless\nand bursting with energy."),
    "MONFERNO":           ("PLAYFUL",       9,  220, "It uses ceilings and walls to launch\nitself. By enveloping itself in flame,\nit protects itself from attacks."),
    "INFERNAPE":          ("FLAME",         12, 550, "It uses its fire-cloaked fists for\nbattle. It is a powerful warrior\nwho will not yield to any enemy."),
    "PIPLUP":             ("PENGUIN",       4,  52,  "Because it is very proud, it does not\naccept food from people. It tries\nto walk upright but often falls."),
    "PRINPLUP":           ("PENGUIN",       8,  232, "It lives alone away from others.\nEvery one of them considers itself\nthe most important Pokemon of all."),
    "EMPOLEON":           ("EMPEROR",       17, 844, "The three horns extending from its\nbeak attest to its power. It leads a\ncolony of Piplup gracefully."),
    "BUIZEL":             ("SEA WEASEL",    7,  295, "It spins its two tails like a\npropeller to swim forward at high\nspeed. Its flotation sac is buoyant."),
    "FLOATZEL":           ("SEA WEASEL",    11, 335, "It evolved for fast swimming in cold\nseas. Its flotation sac inflates to\nkeep its head above the water."),
    "MAGMORTAR":          ("BLAST",         16, 680, "It launches balls of fire from the\ncannonlike holes in its arms. The\nballs can reach 3,600 degrees."),
    "ELECTIVIRE":         ("THUNDERBOLT",   18, 1386,"It has no concern for electricity\nbills. It generates 20,000 volts with\neach of its two tails."),
    "ROTOM":              ("PLASMA",        3,  3,   "Its body is made of plasma. It\ncan inhabit electrical appliances and\nuse them for its own mischief."),
    "ROTOM_HEAT":         ("PLASMA",        3,  3,   "Rotom has possessed an oven. It\nheats the air with cooking fire,\nburning foes severely."),
    "ROTOM_WASH":         ("PLASMA",        3,  3,   "Rotom has possessed a washing\nmachine. The swirling water inside\ncan catch and drown enemies."),
    "ROTOM_FROST":        ("PLASMA",        3,  3,   "Rotom has possessed a refrigerator.\nThe intense cold it generates can\nfreeze anything solid in moments."),
    "ROTOM_FAN":          ("PLASMA",        3,  3,   "Rotom has possessed a fan. Its\nspinning blades create powerful\ncutting winds that shred enemies."),
    "ROTOM_MOW":          ("PLASMA",        3,  3,   "Rotom has possessed a mower.\nThe spinning blades below it hack\nthrough grass and flesh alike."),
    "TOXEL":              ("BABY",          4,  110, "It stores poison in an internal\nsac. By touching foes with its body,\nit injects them with small doses."),
    "TOXTRICITY":         ("PUNK",          16, 400, "It stimulates its poison glands by\ndrumming on its chest. This poison\ncan paralyze its targets."),
    "TYNAMO":             ("ELEFISH",       2,  3,   "One alone has little power. But if\nthey gather in large numbers, they\ncan generate enough light to daze."),
    "EELEKTRIK":          ("ELEFISH",       12, 220, "Electricity-generating organs line\nits belly. It eats prey in one gulp\nand paralyzes it from within."),
    "EELEKTROSS":         ("ELEFISH",       20, 805, "They crawl out of the ocean with\ntheir arms. They electrocute their\nprey and drag it back to the sea."),
    "ROSERADE":           ("BOUQUET",       9,  145, "Each arm bears a bouquet of flowers.\nIt lures enemies with alluring aromas,\nthen strikes with whiplike arms."),
    "TANGROWTH":          ("OVERGROW",      20, 1284,"In the summer, growth is so excessive\nthat its arms are shrouded in a mass\nof thick, curly vines."),
    "LEAFEON":            ("VERDANT",       10, 255, "When it photosynthesizes, it fills\nthe surrounding area with clean air.\nIt is always surrounded by nature."),
    "GLACEON":            ("FRESH SNOW",    8,  259, "It can control its body temperature\nto freeze the atmosphere and create\ndiamond-dust flurries of ice."),
    "SYLVEON":            ("INTERTWINING",  10, 235, "It sends a soothing aura from its\nfeelers to calm fights. It wraps\nits ribbons around its trainer's arm."),
    "FERROSEED":          ("THORN SEED",    6,  188, "When threatened, it attacks by\nshooting a barrage of spikes. The\nspikes can pierce solid boulders."),
    "FERROTHORN":         ("THORN POD",     10, 1100,"It attaches to cave ceilings and\nfires steel spikes at anyone who\ndisturbs it."),
    "PUMPKABOO":          ("PUMPKIN",       4,  50,  "The light from its body helps it\nfind lost spirits to carry on to the\nafterlife. It favors dark places."),
    "GOURGEIST":          ("PUMPKIN",       9,  125, "It sings in an eerie voice in the\ndark of night. It wraps its arms\naround victims and takes their souls."),
    "PHANTUMP":           ("STUMP",         4,  70,  "These are created when spirits\npossess the stumps of trees. Children\nsay they hear voices from Phantump."),
    "TREVENANT":          ("ELDER TREE",    15, 710, "It can control trees at will.\nIt traps those who harm the forest\nand curses them to wander forever."),
    "GALARIAN_MR_MIME":   ("MIME",          14, 567, "It vigorously mimes cold climates.\nThis expression of its feelings\ngenerates a chill in the air."),
    "MR_RIME":            ("COMEDIAN",      15, 582, "It is highly skilled at tap dancing.\nWith a style both elegant and comical,\nit draws crowds of admirers."),
    "MAMOSWINE":          ("TWIN TUSK",     25, 2910,"Its massive twin tusks are made\nof ice. A herd of them crushed many\nthings as they marched long ago."),
    "FROSLASS":           ("SNOW LAND",     13, 267, "It freezes its prey and exhibits\nthem in its den. Researchers have\nfound many frozen Pokemon in its lair."),
    "WEAVILE":            ("SHARP CLAW",    11, 340, "It lives in cold regions. It\nleaves mysterious messages by cutting\ntree trunks with its sharp claws."),
    "GALARIAN_DARUMAKA":  ("ZEN CHARM",     8,  380, "Its flame-filled heart adapted to\nicy climes. It hurls tightly packed\nballs of snow at its enemies."),
    "GALARIAN_DARMANITAN":("ZEN CHARM",     17, 929, "Most of its body is composed of\nsuperheated ice. It charges at foes\nwith its entire body weight."),
    "ANNIHILAPE":         ("RAGE MONKEY",   12, 560, "When its anger grew beyond a certain\npoint, it acquired a power that\ntranscended the physical realm."),
    "GALARIAN_FARFETCHD": ("WILD DUCK",     8,  420, "It is very stubborn. Under the name\nof training, it spends all day\nwhacking boulders with a large leek."),
    "SIRFETCHD":          ("WILD DUCK",     8,  1177,"After years of training with the\nleek stalk it has carried since birth,\nit has grown into a brave knight."),
    "PANCHAM":            ("PLAYFUL",       6,  80,  "It does its best to look menacing,\nbut the leaf in its mouth softens\nthe effect. It tries to look dignified."),
    "PANGORO":            ("DAUNTING",      21, 1360,"It charges ahead and bashes enemies.\nIt stands firm once it has decided\nits course of action."),
    "CROAGUNK":           ("TOXIC MOUTH",   7,  230, "It mostly avoids attacking on its\nown. Its puffed-up cheeks warn prey\nof the poison it intends to use."),
    "TOXICROAK":          ("TOXIC MOUTH",   13, 444, "Its knuckle claws drip with poison.\nIt uses these claws to fight battles\nto settle territorial disputes."),
    "RIOLU":              ("EMANATION",     7,  202, "The aura from its body can express\nits feelings. When in danger, it\ncan flee at astonishing speed."),
    "LUCARIO":            ("AURA",          12, 540, "It senses the auras of all things.\nIt can see the movements of\nopponents even in pitch darkness."),
    "SCRAGGY":            ("SHEDDING",      6,  118, "Its skin is looser than it needs\nto be. The excess skin functions\nlike a protective shield in battle."),
    "SCRAFTY":            ("HOODLUM",       11, 300, "It can pull its elastic skin up\nto its neck for protection. It\nspits acidic fluid to blind its enemy."),
    "SKRELP":             ("MOCK KELP",     5,  73,  "It disguises itself as rotten kelp\nscattered along the seafloor. Prey\nthat comes near gets poisoned badly."),
    "DRAGALGE":           ("MOCK KELP",     18, 815, "The poison it spits can eat through\nthe bottom of a tanker. It guards\nits territory with great ferocity."),
    "GIBLE":              ("LAND SHARK",    7,  205, "It lives in caves warmed by\ngeothermal heat. It bites anything\nthat moves nearby without hesitation."),
    "GABITE":             ("CAVE",          14, 560, "A ruthless Pokemon, it targets the\nyoung of other species. It hoards\ngems and shiny objects in its den."),
    "GARCHOMP":           ("MACH",          19, 950, "It flies at jet-plane speed and\nnever allows prey to escape. It wraps\nfoes tightly in its massive wings."),
    "GLISCOR":            ("FANG SCORP",    20, 425, "It hides under cliffs to ambush\nprey. It grips them with its pincers\nand drains their energy slowly."),
    "RHYPERIOR":          ("DRILL",         24, 2823,"It launches boulders from the holes\nin its palms. Bores through rock and\nhides inside the tunnels it makes."),
    "DRILBUR":            ("MOLE",          3,  85,  "It can dig through the earth at\na speed of 30 mph. It builds nests\nby leaving paths of tunnels behind."),
    "EXCADRILL":          ("SUBTERRENE",    7,  404, "It can bore through almost anything.\nThe more energy it expends, the more\npowerful its spinning becomes."),
    "SANDILE":            ("DESERT CROC",   7,  152, "It lurks just under the desert\nsurface. The dark membrane over its\neyes shields them from the sun."),
    "KROKOROK":           ("DESERT CROC",   10, 333, "It uses sensors in its nose to aim\naccurately and strike prey even in\nthe total darkness of the night."),
    "KROOKODILE":         ("INTIMIDATION",  15, 964, "It can overpower opponents in almost\nany situation. Its jaws can crush\na truck without much effort."),
    "GOLETT":             ("AUTOMATON",     10, 920, "The energy that gives Golett life\nis a mystery. No one knows what kind\nof power resides inside its body."),
    "GOLURK":             ("AUTOMATON",     28, 3300,"Golurk was created to protect an\nancient civilization. Its flying\nspeed across the world is astonishing."),
    "HONCHKROW":          ("BIG BOSS",      9,  273, "Simply by cawing, it can gather\na flock of Murkrow in a dark night\nsky. It is called the darkness lord."),
    "TOGEKISS":           ("JUBILEE",       15, 380, "It will never appear before those\nwho harbor evil thoughts. It bestows\nbliss and luck on all who are kind."),
    "YANMEGA":            ("OGRE DARNER",   19, 515, "This predatory Pokemon creates\npowerful shock waves by beating its\nwings. It attacks in flying swarms."),
    "HAWLUCHA":           ("WRESTLING",     8,  215, "Although its body is small, its\nkick moves pack incredible power.\nIt always fights in exciting ways."),
    "ROOKIDEE":           ("ROOK",          2,  16,  "It will bravely challenge any\nopponent regardless of size. It\nprotects its nest with a fierce cry."),
    "CORVISQUIRE":        ("RAVEN",         8,  160, "It shows no mercy toward its\nflock. It has a high level of\nintelligence and strong leadership."),
    "CORVIKNIGHT":        ("RAVEN",         22, 750, "With flying skill and high attack\npower, it rules the skies. It\ndominates weaker Pokemon to build nests."),
    "GALLADE":            ("BLADE",         16, 547, "A master of courtesy and swordsmanship.\nIt fights by extending the blade on\nits elbow to protect others."),
    "INKAY":              ("REVOLVING",     4,  35,  "By rapidly flashing the spots on\nits body, it discharges electricity\nand confuses its prey deeply."),
    "MALAMAR":            ("OVERTURNING",   15, 470, "It hypnotizes opponents by flashing\nthe light-emitting spots on its body,\nthen attacks without hesitation."),
    "LARVESTA":           ("TORCH",         11, 288, "It is thought to be born from the\nsun. It was used to make the first\nsilk thousands of years ago."),
    "VOLCARONA":          ("SUN",           16, 460, "When volcanic ash darkened the sky,\nit flew through the heavens and its\nflames replaced the sun's light."),
    "GRUBBIN":            ("LARVA",         4,  44,  "Using its strong jaw, it can bore\nthrough hard tree trunks. It hides\nin leaf litter when threatened."),
    "CHARJABUG":          ("BATTERY",       5,  105, "Its sturdy body can withstand\nelectricity. It stores power by\neating and processing leaves."),
    "VIKAVOLT":           ("STAG BEETLE",   15, 450, "It zaps prey with electricity\ndischarged from its front jaws. Its\nwings give it remarkable speed."),
    "SIZZLIPEDE":         ("RADIATOR",      7,  10,  "It stores flammable gas from the\nfood it eats inside its body. When\nthreatened, it ignites this gas."),
    "CENTISKORCH":        ("RADIATOR",      30, 1200,"When it heats up, its body reaches\nmore than 1500 degrees. Touching it\ncauses severe burns immediately."),
    "KLEAVOR":            ("AXE",           18, 890, "Parts of its body have hardened\ninto stone. If its stone axes smash,\nthey are reforged by nature itself."),
    "HISUIAN_GROWLITHE":  ("PUPPY",         8,  230, "Its rocky fur is hard enough to\nturn away knife blades. It guards\nits territory together with partners."),
    "HISUIAN_ARCANINE":   ("LEGENDARY",     19, 1680,"Found throughout ancient Hisui, it\nis considered a sacred beast and is\nenshrined in regional mythology."),
    "ALOLAN_GEODUDE":     ("ROCK",          4,  200, "Electricity runs across its body.\nIt repels enemies by releasing\nelectric shocks from its whole form."),
    "ALOLAN_GRAVELER":    ("ROCK",          10, 1050,"Electricity builds up inside its\ngranite body. It rolls down rocky\npaths scattering sparks as it goes."),
    "ALOLAN_GOLEM":       ("MEGATON",       14, 3000,"It launches electricity from its\nbody to attack. The electric charge\ndoes not reach inside its hard shell."),
    "PROBOPASS":          ("COMPASS",       14, 3000,"It uses its three small noses to\ngenerate powerful magnetic fields.\nIt can attract and control iron sand."),
    "ROCKRUFF":           ("PUPPY",         5,  92,  "It greets its master by rubbing\nits neck against them. The rocks\non its neck can be used as weapons."),
    "LYCANROC":           ("WOLF",          8,  250, "When properly raised from a Rockruff,\nit becomes a reliable partner that\nteaches teamwork and loyalty."),
    "DREEPY":             ("LINGERING",     5,  20,  "If in good shape, it can fly at\nover 120 mph. It acts as a target\nfor Drakloak during battle."),
    "DRAKLOAK":           ("CARETAKER",     14, 110, "Without a Dreepy to place on its\nhead, it becomes unstable and rampages\nuntil it finds one to carry."),
    "DRAGAPULT":          ("STEALTH",       30, 500, "When not battling, it strolls with\nDreepy inside its hollow horns. It\nis a swift and deadly predator."),
    "BASCULIN":           ("HOSTILE",       10, 180, "Red and blue Basculin are very\naggressive. They are always fighting\neach other, so they never intermix."),
    "BASCULEGION":        ("BIG FISH",      30, 1100,"It is possessed by the souls of\nBasculin that perished before reaching\nthe ocean. A mighty river fish."),
    "ALOLAN_EXEGGUTOR":   ("COCONUT",       109,4155,"The tropical sun fills it with\nenergy. Its heads each think\ndifferent thoughts and argue a lot."),
    "DEINO":              ("IRATE",         8,  174, "Because it is blind, it checks\nsurroundings by biting at everything.\nIt often ends up hurting itself."),
    "ZWEILOUS":           ("HOSTILE",       14, 500, "The two heads are rivals. Each\nhead eats independently and they\ncompete fiercely for food each day."),
    "HYDREIGON":          ("BRUTAL",        18, 1600,"The three heads consume everything\nin their path. The main head does\nall the thinking for the three."),
    "GOOMY":              ("SOFT TISSUE",   3,  28,  "It is the weakest Dragon-type\nPokemon. Its slimy body repels water\nand its mucus can dissolve things."),
    "SLIGGOO":            ("SOFT TISSUE",   4,  175, "It extends four antennae that detect\nsmells from miles away. It slips\naway from enemies with sticky slime."),
    "GOODRA":             ("DRAGON",        20, 1503,"An extremely loving Pokemon. It\nclings to its trainer and gives them\na hug, covering them with slime."),
    "DARKRAI":            ("PITCH-BLACK",   15, 505, "It lures people into darkness and\ncauses them endless nightmares. Those\nnear it feel a deep chill."),
    "ZORUA":              ("TRICKY FOX",    7,  125, "It hides its true form in illusions.\nApparently, it often transforms into\na human child to mislead others."),
    "ZOROARK":            ("ILLUSION FOX",  16, 810, "Each has the power to generate\nillusions that trap enemies in a\ndream world they cannot escape."),
    "PAWNIARD":           ("SHARP BLADE",   5,  102, "Blades cover its body. In battle,\nit slashes opponents with these blades\nand replaces broken ones if needed."),
    "BISHARP":            ("SWORD BLADE",   16, 700, "Pawniard obey orders from Bisharp.\nIt leads them into battle as their\nsupreme commander on the field."),
    "KINGAMBIT":          ("SWORD BLADE",   20, 1200,"It leads a group of Bisharp. Its\nphysical strength is extreme enough\nto push through thick steel obstacles."),
    "BRONZOR":            ("BRONZE",        5,  605, "Ancient people believed it had\nmysterious power and used it for\nfortune-telling in many regions."),
    "BRONZONG":           ("BRONZE BELL",   13, 1870,"It was covered in seawater and\ndiscovered at an archaeological site.\nIt has a voice that carries far."),
    "GALARIAN_MEOWTH":    ("CONSTANCY",     4,  75,  "Living with a savage trainer for\nyears toughened its body and made\nit fiercer than ordinary Meowth."),
    "PERRSERKER":         ("VIKING",        8,  285, "It has separated from the group\nand gone its own way. The steel\nclaws on its face are favorite weapons."),
    "ALOLAN_MEOWTH":      ("ISLAND CAT",    4,  43,  "Its coat is fine and silky soft.\nRumor has it that this Meowth\nlived with a king long, long ago."),
    "ALOLAN_PERSIAN":     ("CLASSY CAT",    11, 330, "The round face is a symbol of\nthose who spend their days in comfort\nand luxury. It is extremely prideful."),
    "DURALUDON":          ("ALLOY",         18, 400, "Its two arms are made of different\ntypes of metal. The strength of the\nalloy varies when the two combine."),
    "ARCHALUDON":         ("BRIDGE",        19, 650, "It has crossed many a suspension\nbridge. The components of its body\nare stronger than Duraludon's own."),
    "TINKATINK":          ("METALSMITH",    4,  88,  "It flings around the hammer it\nhas made itself. If it breaks its\nhammer, it immediately makes a new one."),
    "TINKATUFF":          ("HAMMER",        7,  590, "The hammer it wields is its most\nprized possession. It works hard to\npolish it every single day."),
    "TINKATON":           ("HAMMER",        7,  1128,"It smashes opponents with its\nhuge hammer. Its weapon is the\nresult of gathering material for years."),
    "ALOLAN_DIGLETT":     ("MOLE",          2,  10,  "The three hair strands are highly\npowerful sensory organs. They detect\nnearby vibrations with precision."),
    "ALOLAN_DUGTRIO":     ("MOLE",          7,  667, "Three golden hairs move in\nsynchronized fashion. They are thought\nto embody a local mountain god."),
    "MAGNEZONE":          ("MAGNETIC",      12, 1805,"Exposure to a special magnetic field\nchanged the molecular structure of\nits internal magnets completely."),
    "FLABEBE":            ("SINGLE BLOOM",  1,  1,   "It draws out and controls the\npower of flowers. The flower it\nholds is most likely part of its body."),
    "FLOETTE":            ("SINGLE BLOOM",  2,  9,   "It flutters around fields of flowers\nand cares for the flowers and for\npeople it considers friends."),
    "FLORGES":            ("GARDEN",        11, 100, "It claims a flower garden as its\nown. The power of the flowers\nallows it to manipulate the enemy."),
    "ALOLAN_VULPIX":      ("SNOW FOX",      6,  99,  "A Vulpix exposed to severe cold\nover many generations. It summons\nblizzards to freeze nearby enemies."),
    "ALOLAN_NINETALES":   ("FOX",           11, 199, "It is said to live in perpetual\nsnow. It creates whirlwinds of\npowdery snow, blocking all sight."),
    "UXIE":               ("KNOWLEDGE",     3,  3,   "It is considered a deity of lakes.\nThe gaze of its large eyes can\nwipe the memories of anyone nearby."),
    "MESPRIT":            ("EMOTION",       3,  3,   "It sleeps at the bottom of a lake.\nIt is said to have taught humans\nthe joy and sorrow of living."),
    "AZELF":              ("WILLPOWER",     3,  3,   "It sleeps at the bottom of a lake\nfor weeks without surfacing. It is\nsaid to give willpower to all."),
    "DIALGA":             ("TEMPORAL",      54, 6830,"It has the ability to control\ntime. It appears in ancient texts\nand is said to have shaped time."),
    "PALKIA":             ("SPATIAL",       42, 3360,"It has the ability to warp space.\nIt lives in a gap in the spatial\ndimension parallel to our world."),
    "HEATRAN":            ("LAVA DOME",     17, 4300,"Boiling blood runs through its\nbody. It lumbers through the blistering\nvolcanic environment."),
    "REGIGIGAS":          ("COLOSSAL",      37, 4200,"According to legend, it was once\nused to tow continents with ropes.\nIt sleeps in a cave to the north."),
    "GIRATINA":           ("RENEGADE",      69, 7500,"It was banished for its violence.\nIt lurks in a world on the other\nside, silently seeking revenge."),
    "CRESSELIA":          ("LUNAR",         15, 856, "Fragments of its shining body\ncleave the sky on moonless nights.\nIt appears to bring peaceful dreams."),
    "PHIONE":             ("SEA DRIFTER",   4,  31,  "It lives in warm seas. It always\nreturns to its birthplace no matter\nhow far away it may have drifted."),
    "MANAPHY":            ("SEAFARING",     3,  14,  "Born on a cold seafloor, it creates\na strong bond with its master as\nsoon as it hatches from its Egg."),
    "SHAYMIN":            ("GRATITUDE",     2,  21,  "The flowers on its body burst\ninto bloom if it is lovingly held.\nIt can walk on snow without sinking."),
    "ARCEUS":             ("ALPHA",         32, 3200,"It is described in mythology as\nthe Pokemon that shaped the universe\nwith its one thousand arms."),
}


def species_to_text_var(species_key):
    """GALARIAN_LINOONE -> gGALARIANLINOONEPokedexText"""
    stripped = species_key.replace("_", "")
    return f"g{stripped}PokedexText"


def species_to_national_dex(species_key):
    return f"NATIONAL_DEX_{species_key}"


def update_pokedex_entries(path, data):
    text = open(path).read()
    changes = 0

    for species_key, (category, height, weight, _desc) in data.items():
        national = species_to_national_dex(species_key)

        # Match the entry block: from [NATIONAL_DEX_X] = { to the next }, (or };)
        pat = re.compile(
            rf'(\[{re.escape(national)}\]\s*=\s*\{{\s*)'
            rf'(\.categoryName\s*=\s*_\("[^"]*"\))'
            rf'(.*?\.height\s*=\s*)(\d+)'
            rf'(.*?\.weight\s*=\s*)(\d+)',
            re.DOTALL
        )
        def replacer(m):
            return (
                m.group(1)
                + f'.categoryName = _("{category}")'
                + m.group(3) + str(height)
                + m.group(5) + str(weight)
            )
        new_text, n = pat.subn(replacer, text)
        if n:
            text = new_text
            changes += n
        else:
            print(f"  WARNING: could not find entry for {national}")

    open(path, 'w').write(text)
    print(f"  Updated {changes} entries in {path}")


def update_pokedex_texts(path, data):
    text = open(path).read()
    changes = 0

    for species_key, (category, height, weight, desc) in data.items():
        var = species_to_text_var(species_key)

        # Match the text variable: gXXXPokedexText[] = _( ... );
        pat = re.compile(
            rf'(const u8 {re.escape(var)}\[\]\s*=\s*_\()([^;]+?)(\);)',
            re.DOTALL
        )

        def replacer(m, d=desc):
            # Format as three line strings
            lines = d.split('\n')
            quoted = '\n    '.join(f'"{line}\\n"' for line in lines)
            # Remove trailing \n from last line, add period if missing
            last = lines[-1]
            quoted = '\n    '.join(
                f'"{line}\\n"' if i < len(lines) - 1 else f'"{line}."'
                if not line.endswith(('.', '!', '?')) else f'"{line}"'
                for i, line in enumerate(lines)
            )
            return f'(const u8 {var}[] = _(\n    {quoted})'

        # Simpler approach: just replace the whole thing
        def simple_replacer(m, d=desc, v=var):
            lines = d.split('\n')
            parts = []
            for i, line in enumerate(lines):
                if i < len(lines) - 1:
                    parts.append(f'"{line}\\n"')
                else:
                    # Last line: no trailing \n
                    parts.append(f'"{line}"')
            body = '\n    '.join(parts)
            return f'const u8 {v}[] = _(\n    {body});'

        new_text, n = pat.subn(simple_replacer, text)
        if n:
            text = new_text
            changes += n
        else:
            print(f"  WARNING: could not find text var {var}")

    open(path, 'w').write(text)
    print(f"  Updated {changes} text entries in {path}")


def main():
    print("Updating pokedex entries...")
    update_pokedex_entries("src/data/pokemon/pokedex_entries.h", DATA)

    print("Updating FR pokedex text...")
    update_pokedex_texts("src/data/pokemon/pokedex_text_fr.h", DATA)

    print("Updating LG pokedex text...")
    update_pokedex_texts("src/data/pokemon/pokedex_text_lg.h", DATA)

    print("Done. Run: make -j$(nproc)")


if __name__ == "__main__":
    main()
