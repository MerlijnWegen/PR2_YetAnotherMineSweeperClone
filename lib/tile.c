#include <stdio.h>
#include <stdlib.h>
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
typedef struct{
    TileType tileType;
    TileState tileState;
    int surroundingMines_Count;
} tile_t;

TileType GetTileType(tile_t *targetTile){
    return targetTile->tileType;
}

TileState GetTileState(tile_t *targetTile){
    return targetTile->tileState;
}

//get number of mines surrounding the tile
int GetSurroundingMineCount(tile_t *targetTile){
    return targetTile->surroundingMines_Count;
}

// is the tile targeted a mine? (takes priority over count)
bool IsTileMine(tile_t *targetTile){
    if(GetTileType(targetTile) == MINE){
        return true;
    }
    else{
        return false;
    }
}

//sets the tile type based off of enum
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
        targetTile->tileType = state;
    }
}

//sets surroundingminecount based off of surrounding tiles
void SetSurroundingMineCount(tile_t *targetTile, int value){
    int surroundingMines = GetSurroundingMineCount(targetTile);
    if(surroundingMines > 9){
        fprintf(stderr,"Warning: Too many mines around tile \"%d\". This number shouldn't be higher then 9", surroundingMines);
    }
    targetTile->surroundingMines_Count = surroundingMines;
}

//"flag" tile
void FlagTile(tile_t *targetTile){
    setTileState(targetTile,FLAGGED);
}

//removes "flag" from tile
void RemoveFlagTile(tile_t *targetTile){
    SetTileState(targetTile,HIDDEN);
}

//revealstile (player can't undo reveal)
void RevealTile(tile_t *targetTile){
    SetTileState(targetTile,REVEALED);
}

//memory
tile_t *CreateTile(){
    tile_t *tile = malloc(sizeof(tile_t));
    if(tile == NULL){
        fprintf(stderr,"Fatal: could not allocate memory for tile.");
        exit(EXIT_FAILURE);
    }else{
        return tile;
    }
}
void DestroyTile(tile_t *targetTile){
    free(targetTile);
}