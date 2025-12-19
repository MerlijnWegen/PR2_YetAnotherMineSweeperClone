# Design of yet another Minesweeper clone

**Group members**: Jesper Frederiks(580029), Merlijn Wegen (516735)

This document gives the high-level design of a chess game implementation. It specifies the data structures that are used, the functions that operate on those data structures, and describes how the different components interact with each other to implement the game of chess.

## Game overview

The game minesweeper is played on a X by Y grid of tiles, each tile can either be empty or contain a landmine but what each tile contains is hidden at the start, 
The goal of the game is that the player correctly reveals all the empty tiles, and flags the landmines, only if the Player correctly flagged all the landmines, and revealed all the empty tiles do they win the game, otherwise if during the game the player reveals a landmine, they lose.

the player must identify which tiles are landmines using the revealed tiles
The player can left click a tile to reveal it a tile and right click to Flag it.

When a empty tile is revealed, it will reveal the number of landmines in the surrounding 8 tiles around it, if none are present the surrounding tiles are revealed until it contains a number.

## Design components

The following "entities" will be used to represent the game state (a high-level description is given first, followed by a more detailed description of each data structure in C code):

- `Tile`: Represents each individual tile, it contains the value (0 to 8, or MINE) and the current state (HIDDEN,FLAGGED or REVEALED) and the functions of reading, and writing the value and state of each tile.
  
- `Grid`: Represents the grid of all tiles, it contains a width * height amount of Tiles and the functions to initialise the grid,clear the grid and most of the game's functionality.
  
- `Settings`: Represents the player settings themselves, reading a settings.txt file that the player can alter to change the difficulty of the game beyond the basic EASY, NORMAL or HARD gamemodes.
  
- `Game`: Represents the Game itself and it's remaining functionality, using the desired settings/difficulty to initialise the core game (such as the size of the grid and the amount of mines), starting, ending and resetting the game.

- `UI`: Represents the game window, contains the methods the player uses to interact with the game, displaying it's current state and altering it depending on wher and how the player clicks tiles, difficulty, resetting the game etc.



### Data Structures and enumerations

#### Tile
A tile is representend using the following structure and enumerations:

```c
typedef struct{
    TileValue tileType;
    TileState tileState;
    int surroundingMines_Count;
} tile_t;

typedef enum TileType{
    EMPTY,
    MINE
} TileType;

typedef enum TileState{
    HIDDEN,
    FLAGGED,
    REVEALED,
} TileState;
```

#### Grid
A Grid is representend using the following structure:

```c
typedef struct{
    tile_t *tiles;
    int gridWidth; // init both from Settings_t
    int gridHeight; // init both from Settings_t
    int tilesFlagged_Total;
    int tilesContainingMines_Total;
    int tilesRevealed_Total;
} grid_t;
```

#### Game
The game represents the following structure:

```c
typedef struct Game_t{
    grid_t *grid;
    settings_t *settings;
    GameState gameState;
    uint64_t timeElapsed;
} game_t;

typedef enum GameState{
    PLAYING,
    GAMEWON,
    GAMELOST,
    MENU,
    RESTART_MENU
} GameState;

#### settings
The game represents the following structure:

```c
typedef struct settings_t{
    GameMode difficulty;
    int mineTotal;
    int gridWidth;
    int gridHeight;
    int startingGraceSize;
} settings_t;

typedef enum{
    EASY,
    NORMAL,
    HARD,
    CUSTOM
} GameMode;
```

## Header files

### Tile.h
```c
#ifndef TILE_H
#define TILE_H
#include <stdbool.h>

//enums
typedef enum {
    EMPTY,
    MINE
} TileType;

typedef enum {
    HIDDEN,
    FLAGGED,
    REVEALED
} TileState;

//prototypes
typedef struct tile tile_t;

TileType GetTileType(tile_t *targetTile);
TileState GetTileState(tile_t *targetTile);
int GetSurroundingMineCount(tile_t *targetTile);
bool IsTileMine(tile_t *targetTile);

void SetTileType(tile_t *targetTile, TileType type);
void SetSurroundingMineCount(tile_t *targetTile, int value);

void FlagTile(tile_t *targetTile);
void RemoveFlagTile(tile_t *targetTile);
void RevealTile(tile_t *targetTile);

tile_t *CreateTile();
void DestroyTile(tile_t *targetTile);

#endif //TILE_H
```

### Grid.h
```c
#ifndef GRID_H
#define GRID_H
#include "tile.h"
#include "settings.h"

typedef struct grid_t grid_t;

//prototypes
grid_t *Initgrid(grid_t *grid);
void fillgrid(grid_t *grid);
void CalculateAllTiles(grid_t *grid);
void RevealAllTiles(grid_t *grid);

//memory
grid_t *CreateGrid(settings_t *settings);
void DestroyGrid(grid_t *grid);

#endif //GRID_H
```
### Game.h
```c
#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <stdint.h>
#include "tile.h"
#include "grid.h"
#include "settings.h"

typedef struct game_t game_t;

typedef enum GameState{
    PLAYING,
    GAMEWON,
    GAMELOST,
    MENU,
    RESTART_MENU
} GameState;

GameState GetGameState(game_t *game);
void SetGameState(game_t *game, GameState state);
uint64_t getTimeElapsed(game_t *game);

bool isGameRunning(game_t *game);
bool isGameOver(game_t *game);

void StartGame(game_t *game);
void GameOver(Game_t *game, bool hasWon);

//memory
game_t *CreateGame(settings_t *settings);
void DestroyGame(game_t *game);
#endif //GAME_H
```

### Settings.h
```c
#ifndef SETTINGS_H
#define SETTINGS_H
#include "tile.h"
#include "grid.h"

typedef struct settings_t settings_t;

GameMode GetGameMode(settings_t *settings);
int GetGridWidth(settings_t *settings);
int GetGridHeight(settings_t *settings);
int GetMineCount(settings_t *settings);



void SetGameMode(settings_t *settings, GameMode difficulty);
void SetGridWidth(settings_t *settings, int width);
void SetGridHeight(settings_t *settings,int height);
void SetMineCount(settings_t *settings, int minecount);

//memory
settings_t *CreateSettings(void);
void DestroySettings(settings_t *settings);
#endif //SETTINGS_H
```

### UI.h
```c
#ifndef UI_H
#define UI_H
#include "game.h"
#include "settings.h"

typedef enum{
    S, //Start
    C, //Config Settings
    Q, //quit
} MenuInput;

//user input
GameMode ShowGameModeSelectionScreen(void);
MenuInput GetUserInput(void);

//menu
void SwitchMenu(MenuInput input);
void ShowSettingMenu(settings_t *settings);
void ShowMainMenu(void);
void ExitGame(settings_t *settings, game_t *game);

//util
void ClearScreen();
#endif //UI_H
```

## Interaction between components
```c
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "game.h"
#include "settings.h"
#include "UI.h"

int main(void){
    settings_t *settings = CreateSettings();
    game_t *game = CreateGame(settings);
    
    while(isGameRunning(game)){
        ShowMainMenu();
        MenuInput input = GetUserInput();
        SwitchMenu(input);
    }
    ExitGame(settings, game);
    return 0;
}
```