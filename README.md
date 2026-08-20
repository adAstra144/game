# Text Based Dungeon CLI Game

A turn-based dungeon crawler that runs entirely in the terminal. Navigate branching paths, fight enemies with a turn-based combat system, collect gold, and spend it to level up your stats.

## Features

- Turn-based combat with speed-based turn order, attack/defend/run options, and enemy special moves
- Branching path navigation with multiple routes to explore
- Quest tracking (e.g. the Wizard's skeleton-hunting quest)
- Stat upgrade system — spend gold earned in combat to boost HP, ATK, and SPEED
- Enemy variety via a shared base class (`Skeleton`, `King Goblin`, more to come)
- Simple in-game tutorial covering the message/symbol system

## Prerequisites

- A C++ compiler (g++, C++17 or later)
- CMake (3.10+)
- Make

On Ubuntu/Linux Mint:

```bash
sudo apt install build-essential cmake
```

## Installation

1. Clone the repo:

   ```bash
   git clone https://github.com/adAstra144/game.git
   cd game
   ```

2. Build it:

   ```bash
   chmod +x ./build.sh
   ./build.sh
   ```

   This configures and compiles the project into a `build/` directory. If you ever move or rename the project folder, run `./build.sh clean` first — CMake caches absolute paths and a stale cache will break the build.

3. Run it:

   ```bash
   ./build/game
   ```

   (Replace with your actual executable name if it differs — check the `add_executable(...)` line in `CMakeLists.txt`.)

### Manual build (without the script)

```bash
mkdir -p build && cd build
cmake ..
cmake --build .
```

## Project Structure

```
include/       Header files (mirrors src/)
src/           Source files
  enemy/       Enemy base class and subclasses
  paths/       Branching story paths
  player/      Player class and stat/upgrade logic
main.cpp       Entry point
build.sh       One-command build script
```

## Notes

- Save states are not currently implemented — each run starts fresh.
- See `notes.md` for the current roadmap and known TODOs.