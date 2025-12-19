Functionheaders
------ Tile.h ------------------------------------
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

------ Grid.h ------------------------------------
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
------ Game.h ------------------------------------
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

------ Settings.h ------------------------------------
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

------ UI.h ------------------------------------
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
------ Main.h ------------------------------------
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



