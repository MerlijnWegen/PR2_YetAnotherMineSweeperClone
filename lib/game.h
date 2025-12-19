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
void GameOver(game_t *game, bool hasWon);

//memory
game_t *CreateGame(settings_t *settings);
void DestroyGame(game_t *game);
#endif //GAME_H