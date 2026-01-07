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


/// @brief Get GameState from game
/// @param game game pointer to get from
/// @return gamestate enum
GameState GetGameState(game_t *game);


/// @brief set GameState for target game
/// @param game game_t to set gamestate
/// @param state state to set it to.
void SetGameState(game_t *game, GameState state);


/// @brief Get starting time of game (beginning of playing)
/// @param game target game_t
/// @return time in uint64_t\n
/// *note: actually the wrong return type, but i cannot alter game_t struct to use the correct time_t
uint64_t GetTimeStarted(game_t *game);

/// @brief Get grid pointer from game
/// @param game target game_t
/// @return grid_t pointer
grid_t *GetGrid(game_t *game);

/// @brief get settings_t pointer from game
/// @param game target game_t
/// @return setting_t * pointer stored in game.
settings_t *GetGameSettings(game_t *game);

// is the game currently running (can the player see the grid of tiles)

/// @brief Is the game currently running, or has it reached a gamestate?
/// @param game target game_t
/// @return true if game state is PLAYING, otherwise false.
bool IsGameRunning(game_t *game);

/// @brief Simple function to set gameState to GAMELOST in target game_ts
/// @param game target game_t 
void GameLost(game_t *game);

/// @brief Check if game has been won (Hidden tiles les == MINE total), sets gamestate to GAMEWON if true
/// @param game target game_t to check
void CheckForGameWON(game_t *game);

/// @brief Sets up grid for UI and Fillgrid
/// @param game target game_t
void StartGame(game_t *game);

/// @brief broken debugging cheats to instantly win/lose game, or to reveal all tiles
/// @param game target game_t
/// @param i target cheat
    /// 1 = lose game
    /// 2 = win game
    /// 3 = reveal all tiles
/// *Note: cheats WILL break gamelogic.
void DebugCheats(game_t *game,int i);


/// @brief create Game_t using settings, using heap
/// @param settings for game
/// @return pointer to game_t memory on stack
game_t *CreateGame(settings_t *settings);

/// @brief free memory of gamepointer (includes grid & tiles)
/// @param game target game_t
void DestroyGame(game_t *game);
#endif //GAME_H