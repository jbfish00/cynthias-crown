# hack/poryscripts

Poryscript (`.pory`) sources for new events. Compiled to `.inc` files placed into `data/scripts/` or `data/maps/<MapName>/scripts.inc` by the build.

Compile (manual, until we wire into `Makefile`):

```
poryscript -i hack/poryscripts/<name>.pory -o data/scripts/<name>.inc
```
