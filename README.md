# Battleship
 
A two-player, turn-based Battleship game written in C, playable in the Windows console. Players place their fleets on a configurable grid, then take turns firing at each other's ships until one side is completely sunk.
 
## Features
 
- Configurable board size (up to 15×15)
- Variable fleet size (ships range from size 1 up to the configured maximum)
- Color-coded console rendering using ANSI escape codes
- Collision detection during ship placement
- Hit/miss/sunk feedback with short delays for readability
- Full memory cleanup on exit
## Requirements
 
- Windows (uses `windows.h`, `conio.h`, `Sleep()`, and `system("cls")`)
- A C compiler that supports C99 or later (tested with MSVC)
> **Note:** This project is Windows-only due to its use of Win32 APIs. It will not compile or run on Linux/macOS without significant modification.
 
## Building
 
### With MSVC (Visual Studio)
 
Open the project folder in Visual Studio and build normally, or from the Developer Command Prompt:
 
```
cl main.c /Fe:battleship.exe
```
 
### With MinGW/GCC on Windows
 
```
gcc main.c -o battleship.exe -lm
```
 
## How to Play
 
### 1. Configure the game
 
On startup, you will be prompted to enter:
 
- **Board size** — an N×N grid (maximum 15)
- **Max ship size** — also determines the number of ships; must be at most 70% of the board dimension
### 2. Place your ships
 
Each player places their ships one by one, from size 1 up to the configured maximum. For each ship:
 
- Choose an **orientation**: `1` for vertical, `2` for horizontal
- Enter the **X and Y starting coordinates** (1-indexed)
Invalid placements (out of bounds or colliding with an existing ship) are rejected with an error message.
 
### 3. Take turns firing
 
On your turn, both your ship map and your hit map are displayed. Enter the X and Y coordinates to fire at. Results:
 
| Symbol | Meaning |
|--------|---------|
| `H` | Your ship (intact) |
| `X` | Hit (yours or enemy's) |
| `O` | Miss |
| `*` | Unknown / empty water |
 
- A **hit** lets you fire again immediately (chain shots until you miss)
- A **miss** ends your turn; press `Enter` to pass to the opponent
### 4. Winning
 
The game ends when all of one player's ships are sunk. The surviving player is declared the winner.
 
## Project Structure
 
| File | Responsibility |
|------|---------------|
| `main.c` | Entry point; game loop, settings, player init, memory cleanup |
| `dataStructures.h` | `Field`, `Ship`, `Player`, and `Settings` struct definitions |
| `playerInit.h` | Player initialization, ship placement logic, collision/bounds validation |
| `gameRound.h` | Firing logic, hit detection, ship-sunk detection, round management |
| `utilityFunctions.h` | Map rendering, map updates, player switching, game-over check, memory free |
