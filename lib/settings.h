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