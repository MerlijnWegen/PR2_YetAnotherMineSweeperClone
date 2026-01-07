#include "game.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct game_t{
    grid_t *grid;
    settings_t *settings;
    GameState gameState;
    uint64_t timeGameStarted;
}game_t;

GameState GetGameState(game_t *game){
    return game->gameState;
}

void SetGameState(game_t *game, GameState state){
    game->gameState = state;
}


uint64_t GetTimeStarted(game_t *game){
    time_t currenttime;
    time(&currenttime);
    return game->timeGameStarted - currenttime;
}

grid_t *GetGrid(game_t *game){
    return game->grid;
}
settings_t *GetGameSettings(game_t *game){
    return game->settings;
}

bool IsGameRunning(game_t *game){
    return game->gameState == PLAYING;
}

void GameLost(game_t *game){
    game->gameState = GAMELOST;
}

void CheckForGameWON(game_t *game){
    if(GetGridSize(game->grid) - GetRevealedCount(game->grid) == GetMineTotal(game->settings)){
        game->gameState = GAMEWON;
    }
}

void StartGame(game_t *game){
    game->grid = CreateGrid(game->settings);
    Initgrid(game->grid);
}

//broken cheats, you can use them but the game WILL break, debug only
void DebugCheats(game_t *game,int i){
    switch (i)
    {
    case 1: game->gameState = GAMELOST; break;
    case 2: game->gameState = GAMEWON; break;
    case 3: RevealAllTiles(game->grid); break;
    }
}
//memory

game_t *CreateGame(settings_t *settings){
    game_t *game = malloc(sizeof(game_t));
    if(game == NULL){
        fprintf(stderr,"Fatal: Could not allocate memory for game.");
        exit(EXIT_FAILURE);
    }
    time_t currenttime;
    time(&currenttime);
    game->settings = settings;
    game->gameState = PLAYING;
    game->timeGameStarted = (uint64_t)currenttime;
    return game;
}
void DestroyGame(game_t *game){
    DestroyGrid(game->grid);
    free(game);
}