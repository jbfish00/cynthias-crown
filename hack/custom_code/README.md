# hack/custom_code

C sources added or overridden for Cynthia's Crown. Files here are wired into the build via additions to `src/` and `include/` (or via a small `subdir.mk` once we land Step 2+). Keeping new modules under this folder makes upstream merges straightforward — when conflicts arise they will be in pret's tree, not ours.

Planned modules (created in later steps):

- `type_lock.c` / `type_lock.h` — chosen-type storage (var/flag), starter table, eligibility query.
- `signature_moves.c` — per-type signature-move table (flat array keyed by type).
- `party_check.c` — pre-battle party validator + Type Shrine / Pokémon Center swap UI hook.
