# Cynthia's Crown

> A monotype journey through Kanto, twenty years on — with Cynthia walking beside you.

**Status:** Step 1 of 9 — repo scaffolding.

## What it is

A FireRed ROM hack built on [pret/pokefirered](https://github.com/pret/pokefirered). At the start of the game the player chooses one of the 18 types at a Type Shrine and is bound to a monotype team for the rest of their journey — with a clear, generous exception system so each type stays viable across all 8 Gyms, the Elite Four, and a post-game Johto. Cynthia, restarting her own journey in Kanto, is the secondary rival: friendly, mythologically-minded, recurring.

Modern niceties (Phys/Spec split, updated AI, improved movesets, ~40–50 added species drawn from later generations) are layered in over a clean pret base.

## Highlights

- 18 type paths, each with a distinct starter and signature-move pool.
- Soft-locked enforcement at Gyms / story battles, with a Type Shrine to swap teams cleanly.
- Cynthia as recurring secondary rival — battles, lore, post-game arc.
- Kanto refresh: same map skeleton, twenty-years-later visual + narrative updates.
- Post-game: a similarly future-shifted Johto.

## Build

Build inside WSL2 + Ubuntu — full instructions in [hack/docs/build.md](hack/docs/build.md). TL;DR:

```bash
cd "/mnt/c/Users/jbren/Documents/Pokemon ROM Hacks/Mono Cynthia"
make -j$(nproc) modern
```

## Project layout

```
hack/
├── custom_code/    # New C modules (type lock, signature moves, party check)
├── new_maps/       # Porymap working files for new/modified maps
├── poryscripts/    # Poryscript sources, compiled to data/scripts/*.inc
├── docs/           # Ruleset, species list, story beats, build instructions
└── assets/         # Custom sprites, tilesets, music
```

Pret's tree (`src/`, `include/`, `data/`, etc.) is preserved unmodified during scaffolding so we can pull upstream updates cleanly. Mods land starting in Step 2.

## Roadmap

1. Repo scaffolding *(this step)*
2. Type-selection event + per-type starter distribution
3. Mono-type enforcement: party checker, signature-move table, Type Shrine NPC
4. Species, moves, abilities — add ~40–50 mons + modern movesets
5. Main rival rewrite + Cynthia integration (sprites, OW, trainer data)
6. Kanto map refresh + new areas
7. Story / Gym / League / League dialogue rewrites
8. Post-game Johto access and content
9. Balance, QoL, polish, testing

## Credits

- [pret/pokefirered](https://github.com/pret/pokefirered) — base decompilation.
- [pret/agbcc](https://github.com/pret/agbcc) — matching toolchain.
- [huderlem/poryscript](https://github.com/huderlem/poryscript) — scripting language.
- [huderlem/porymap](https://github.com/huderlem/porymap) — map editor.
- [Skeli789/Complete-Fire-Red-Upgrade](https://github.com/Skeli789/Complete-Fire-Red-Upgrade) — feature inspiration (Phys/Spec split, AI, movesets).

## Notice

This repository contains source code only. No retail ROMs, patched ROMs, or copyrighted Pokémon assets are distributed here. To build, supply your own legally obtained FireRed ROM as a build reference where required.

The original pret README is preserved at [docs/upstream-README.md](docs/upstream-README.md).
