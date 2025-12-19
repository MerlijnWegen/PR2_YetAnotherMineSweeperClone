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

// get tile type based off of enum
TileType GetTileType(tile_t *targetTile);

// get tile state based off of enum
TileState GetTileState(tile_t *targetTile);

//get number of mines surrounding the tile
int GetSurroundingMineCount(tile_t *targetTile);

// is the tile targeted a mine? (takes priority over count)
bool IsTileMine(tile_t *targetTile);

//sets the tile type based off of enum
void SetTileType(tile_t *targetTile, TileType type);

//sets surroundingminecount based off of surrounding tiles
void SetSurroundingMineCount(tile_t *targetTile, int value);

//"flag" tile
void FlagTile(tile_t *targetTile);

//removes "flag" from tile
void RemoveFlagTile(tile_t *targetTile);

//revealstile (player can't undo reveal)
void RevealTile(tile_t *targetTile);

//memory
tile_t *CreateTile();
void DestroyTile(tile_t *targetTile);

#endif //TILE_H