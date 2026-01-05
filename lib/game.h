#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <stdint.h>
#include "tile.h"
#include "grid.h"
#include "settings.h"
#include <time.h>

typedef struct game_t game_t;

typedef enum GameState{
    PLAYING,  //grid fill of tiles
    GAMEWON,  //GAMEOVER screen, but player won
    GAMELOST, //GameOVER Screen but player lost
    MENU, //INSIDE of A menu before starting the game
    RESTART_MENU //Inside of A menu, before
}GameState;

//Gets gameState of Game based off of the GameState Enum
GameState GetGameState(game_t *game);

//Sets gameState of Game based off of the GameState Enum
void SetGameState(game_t *game, GameState state);

// gets time in uint64_t since the "game started" (from the second the grid of tiles loads in.)
uint64_t GetTimeStarted(game_t *game);

//get gridpoointer
grid_t *GetGrid(game_t *game);
settings_t *GetGameSettings(game_t *game);

// is the game currently running (can the player see the grid of tiles)
bool IsGameRunning(game_t *game);

// has the player triggered a game condition WON/LOST?
bool IsGameOver(game_t *game);

//load in the tiles empty until player clicks the first tile, then fill grid.
void StartGame(game_t *game);

//changes screen to a different menu
void GameOver(game_t *game);
//memory

game_t *CreateGame(settings_t *settings);
void DestroyGame(game_t *game);
#endif //GAME_H