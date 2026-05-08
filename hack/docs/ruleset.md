# Cynthia's Crown — Ruleset

## Mono-type rule

After choosing a primary type at the start of the game, the player's party is restricted to Pokémon of that type — with one exception (below). Enforcement runs before Gym battles, Rivals, Elite Four, Champion, and key story battles. Violations soft-lock the trigger and offer a Type Shrine / Pokémon Center swap.

## Exception: signature-move pass

Any Pokémon (or any member of its evolution line) that **learns a signature move of the chosen type** is legal. Signature moves are high-power STAB moves that define the type. Initial table (subject to balancing in Step 4):

| Type     | Signature moves (any one qualifies)                |
|----------|----------------------------------------------------|
| Normal   | Hyper Beam, Tri Attack, Boomburst                  |
| Fire     | Flamethrower, Fire Blast, Overheat                 |
| Water    | Surf, Hydro Pump, Scald                            |
| Electric | Thunderbolt, Thunder, Volt Switch                  |
| Grass    | Energy Ball, Giga Drain, Leaf Storm                |
| Ice      | Ice Beam, Blizzard, Freeze-Dry                     |
| Fighting | Close Combat, Aura Sphere, Focus Blast             |
| Poison   | Sludge Bomb, Gunk Shot, Toxic                      |
| Ground   | Earthquake, Earth Power, High Horsepower           |
| Flying   | Hurricane, Brave Bird, Air Slash                   |
| Psychic  | Psychic, Psyshock, Future Sight                    |
| Bug      | Bug Buzz, X-Scissor, Megahorn                      |
| Rock     | Stone Edge, Rock Slide, Power Gem                  |
| Ghost    | Shadow Ball, Shadow Claw, Hex                      |
| Dragon   | Draco Meteor, Dragon Pulse, Outrage                |
| Dark     | Dark Pulse, Crunch, Foul Play                      |
| Steel    | Iron Head, Flash Cannon, Meteor Mash               |
| Fairy    | Moonblast, Dazzling Gleam, Play Rough              |

> **Open question for Step 3 design**: do we check learnability at *current level*, *full level-up tree*, or *level-up + TM/HM*? Recommendation: full level-up tree — keeps the gimmick generous and forward-compatible with reordered movesets.

## Reward for dedication

Players who complete a Gym (or major battle) with a fully *pure* mono-type party (no signature-move-pass exceptions used) receive bonus rewards: rare candies, type-themed held items, special Cynthia dialogues. Tracking via a separate flag set on each enforcement check.

## Starter assignment

Player picks type *first*, then receives the type's assigned starter:

| Type     | Starter                                       |
|----------|-----------------------------------------------|
| Normal   | Porygon                                       |
| Electric | Shinx                                         |
| Ice      | Swinub                                        |
| Fighting | Mankey                                        |
| Poison   | Nidoran ♂ / ♀ (player picks gender)          |
| Ground   | Trapinch                                      |
| Flying   | (regional bird — TBD: Pidgey / Starly / Fletchling) |
| Psychic  | Abra (knows Confusion at start)               |
| Bug      | Pinsir, Scyther, or Heracross (player picks)  |
| Rock     | Any fossil mon (Omanyte / Kabuto / Aerodactyl) |
| Ghost    | Gastly                                        |
| Dragon   | Axew                                          |
| Dark     | Galarian Zigzagoon                            |
| Steel    | Honedge                                       |
| Fairy    | Togepi                                        |
| Fire     | Any Fire starter across generations           |
| Water    | Any Water starter across generations          |
| Grass    | Any Grass starter across generations          |
