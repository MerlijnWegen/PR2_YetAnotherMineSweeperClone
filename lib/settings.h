#ifndef SETTINGS_H
#define SETTINGS_H
#include "tile.h"
#include "grid.h"

typedef struct settings_t settings_t;

typedef enum{
    EASY,
    NORMAL,
    HARD,
    CUSTOM
} GameMode;

//Gets current gamemove, based off of the gamemode Enum
GameMode GetGameMode(settings_t *settings);

//gets the width of the grid (in tiles)
int GetGridWidth(settings_t *settings);

//gets the height of the grid (in tiles)
int GetGridHeight(settings_t *settings);

//get the total of amount of mines to generate.
int GetMineCount(settings_t *settings);


// changes difficulty in settings
void SetGameMode(settings_t *settings, GameMode difficulty);

// sets the width of the grid (in tiles)
void SetGridWidth(settings_t *settings, int width);

//sets the height of the grid (in tiles)
void SetGridHeight(settings_t *settings,int height);

//sets the total amount of Mines to generate
void SetMineCount(settings_t *settings, int minecount);

//memory
settings_t *CreateSettings(void);
void DestroySettings(settings_t *settings);
#endif //SETTINGS_H