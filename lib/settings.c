#include "settings.h"
#include <stdlib.h>
#include <stdio.h>

//default settings based off of wikipedia.org/wiki/minesweeper_(video_game) 29-12-2025 00:54
#define def_difficulty NORMAL

//Easy
#define easy_def_mineTotal 10
#define easy_def_gridWidth 9
#define easy_def_gridHeight 9
#define easy_def_startingGraceSize 4

//normal
#define norm_def_mineTotal 40
#define norm_def_gridWidth 16
#define norm_def_gridHeight 16
#define norm_def_startingGraceSize 2

//hard
#define hard_def_mineTotal 99
#define hard_def_gridWidth 30
#define hard_def_gridHeight 16
#define hard_def_startingGraceSize 0

//Custom
#define cstm_def_mineTotal 40
#define cstm_def_gridWidth 16
#define cstm_def_gridHeight 16
#define cstm_def_startingGraceSize 2




typedef struct settings_t{
    GameMode difficulty;
    int mineTotal;
    int gridWidth;
    int gridHeight;
    int startingGraceSize;
}settings_t;


GameMode GetGameMode(settings_t *settings){
    return settings->difficulty;
}

int GetGridWidth(settings_t *settings){
    return settings->gridWidth;
}


int GetGridHeight(settings_t *settings){
    return settings->gridHeight;
}


int GetMineTotal(settings_t *settings){
    return settings->mineTotal;
}

void SetGameMode(settings_t *settings, GameMode difficulty){
    switch (difficulty)
    {
    case EASY:
        settings->difficulty = EASY;
        settings->gridHeight = easy_def_gridHeight;
        settings->gridWidth = easy_def_gridWidth;
        settings->mineTotal = easy_def_mineTotal;
        settings->startingGraceSize = easy_def_startingGraceSize;
        break;

    case NORMAL:
        settings->difficulty = NORMAL;
        settings->gridHeight = norm_def_gridHeight;
        settings->gridWidth = norm_def_gridWidth;
        settings->mineTotal = norm_def_mineTotal;
        settings->startingGraceSize = norm_def_startingGraceSize;
        break;

    case HARD:
        settings->difficulty = HARD;
        settings->gridHeight = hard_def_gridHeight;
        settings->gridWidth = hard_def_gridWidth;
        settings->mineTotal = hard_def_mineTotal;
        settings->startingGraceSize = hard_def_startingGraceSize;
        break;
    default:
        settings->difficulty = CUSTOM;
        settings->gridHeight = cstm_def_gridHeight;
        settings->gridWidth = cstm_def_gridWidth;
        settings->mineTotal = cstm_def_mineTotal;
        settings->startingGraceSize = cstm_def_startingGraceSize;
    }
}

void SetGridWidth(settings_t *settings, int width){
    settings->gridHeight = width;
}

void SetGridHeight(settings_t *settings,int height){
    settings->gridHeight = height;
}

void SetMineTotal(settings_t *settings, int minecount){
    settings->mineTotal = minecount;
}

int GetGridGrace(settings_t *settings){
    return settings->startingGraceSize;
}
void SetGridGrace(settings_t *settings, int grace){
    settings->startingGraceSize = grace;
}



settings_t *CreateSettings(GameMode difficulty){
    settings_t *settings = malloc(sizeof(settings_t));
    if(settings == NULL){
        fprintf(stderr,"Fatal: could not allocate memory for settings");
        exit(EXIT_FAILURE);
    }
    else{
        SetGameMode(settings,difficulty);
        return settings;
    }
}

void DestroySettings(settings_t *settings){
    free(settings);
}