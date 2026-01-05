#include "tile.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//prototypes
typedef struct tile_t{
    TileType tileType;
    TileState tileState;
    int surroundingMines_Count;
}tile_t;


TileType GetTileType(tile_t *targetTile){
    return targetTile->tileType;
}

TileState GetTileState(tile_t *targetTile){
    return targetTile->tileState;
}

int GetSurroundingMineCount(tile_t *targetTile){
    return targetTile->surroundingMines_Count;
}

bool IsTileMine(tile_t *targetTile){
    if(GetTileType(targetTile) == MINE){
        return true;
    }
    else{
        return false;
    }
}

void SetTileType(tile_t *targetTile, TileType type){
    if(type != EMPTY && type != MINE){
        fprintf(stderr,"Fatal: Tiletype set to invalid Type: \"%d\"", type);
        exit(EXIT_FAILURE);
    }else{
        targetTile->tileType = type;
    }
}

void SetTileState(tile_t *targetTile, TileState state){
    if(state < HIDDEN || state > REVEALED){
        fprintf(stderr,"Fatal: Tilestate set to invalid state: \"%d\"", state);
        exit(EXIT_FAILURE);
    }else{
        targetTile->tileState = state;
    }
}

void SetSurroundingMineCount(tile_t *targetTile, int value){
    targetTile->surroundingMines_Count = value;
}

void FlagTile(tile_t *targetTile){
    SetTileState(targetTile,FLAGGED);
}

void RemoveFlagTile(tile_t *targetTile){
    SetTileState(targetTile,HIDDEN);
}

void RevealTile(tile_t *targetTile){
    SetTileState(targetTile,REVEALED);
}

tile_t *CreateTile(){
    tile_t *tile = malloc(sizeof(tile_t));
    if(tile == NULL){
        fprintf(stderr,"Fatal: could not allocate memory for tile.");
        exit(EXIT_FAILURE);
    }else{
        tile->tileType = EMPTY;
        tile->tileState = HIDDEN;
        tile->surroundingMines_Count = 0;
        return tile;
    }
}

void DestroyTile(tile_t *targetTile){
    free(targetTile);
}