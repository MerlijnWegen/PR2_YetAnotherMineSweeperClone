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

TileType GetTileType(tile_t *targetTile);
TileState GetTileState(tile_t *targetTile);
int GetSurroundingMineCount(tile_t *targetTile);
bool IsTileMine(tile_t *targetTile);

void SetTileType(tile_t *targetTile, TileType type);
void SetSurroundingMineCount(tile_t *targetTile, int value);

void FlagTile(tile_t *targetTile);
void RemoveFlagTile(tile_t *targetTile);
void RevealTile(tile_t *targetTile);

tile_t *CreateTile();
void DestroyTile(tile_t *targetTile);

#endif //TILE_H