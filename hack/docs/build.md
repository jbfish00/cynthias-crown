# Build instructions — Cynthia's Crown

Builds run inside **WSL2 + Ubuntu**. Do *not* try to build directly from Windows Git Bash — agbcc and the pret Makefile assume a Linux toolchain.

## One-time setup (Ubuntu in WSL)

```bash
# 1. Build dependencies
sudo apt update
sudo apt install -y build-essential binutils-arm-none-eabi gcc-arm-none-eabi \
    git libpng-dev g++ make python3 python3-pip golang-go

# 2. agbcc (required for the matching, non-modern build)
cd ~
git clone https://github.com/pret/agbcc.git
cd agbcc
./build.sh
./install.sh "/mnt/c/Users/jbren/Documents/Pokemon ROM Hacks/Mono Cynthia"

# 3. poryscript (used in later steps)
go install github.com/huderlem/poryscript@latest
echo 'export PATH=$PATH:$HOME/go/bin' >> ~/.bashrc && source ~/.bashrc
```

## Build the ROM

```bash
cd "/mnt/c/Users/jbren/Documents/Pokemon ROM Hacks/Mono Cynthia"

# Recommended for hack iteration (faster, uses modern arm-none-eabi-gcc):
make -j$(nproc) modern

# Or, for a bit-matching vanilla FireRed build:
make -j$(nproc)
sha1sum pokefirered.gba
# Expected (vanilla retail FRLG 1.0 US): 41cb23d8dccc8ebd7c649cd8fbb58eeace6e2fdc
```

## Run it

Open the produced `pokefirered.gba` in mGBA. Save states under `*.sav` are gitignored.

## Cleaning

```bash
make clean        # remove build artifacts
make tidy         # lighter cleanup, keeps tools
```

## Troubleshooting

- *"agbcc: command not found"* — `install.sh` was not run with this folder as its argument; rerun step 2 above.
- *Errors about file paths with spaces* — always quote the project path.
- *Permission denied on `/mnt/c/...`* — ensure the file is not open in Windows; close Porymap/VS Code temporarily.
