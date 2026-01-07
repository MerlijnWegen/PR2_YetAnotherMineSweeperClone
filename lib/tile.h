#ifndef TILE_H
#define TILE_H
#include <stdbool.h>

//enums
typedef enum {
    EMPTY,
    MINE
}TileType;

typedef enum {
    HIDDEN,
    FLAGGED,
    REVEALED
}TileState;

//prototypes
typedef struct tile_t tile_t;


/// @brief get target tile type and returns value in enum
/// @param targetTile target
/// @return Tile type returned MINE / EMPTY
TileType GetTileType(tile_t *targetTile);


/// @brief gettarget tile state and returns value in enum
/// @param targetTile target
/// @return tile state returned REVEALED,HIDDEN,FLAGGED
TileState GetTileState(tile_t *targetTile);


/// @brief get the surrounding number of mines in target tile
/// @param targetTile target
/// @return numberof nearby mines in neighbours
int GetSurroundingMineCount(tile_t *targetTile);

/// @brief is target tile a mine? true if yes, false if no
/// @param targetTile target
/// @return true or false  depending if the tile is a MINE
bool IsTileMine(tile_t *targetTile);

/// @brief Set target tile type
/// @param targetTile target
/// @param type type to set it to
void SetTileType(tile_t *targetTile, TileType type);

/// @brief set target tile state
/// @param targetTile target
/// @param state state to set it to
void SetTileState(tile_t *targetTile, TileState state);

/// @brief set the value of surrounding mines in target tile
/// @param targetTile target
/// @param value amount of mines
void SetSurroundingMineCount(tile_t *targetTile, int value);

/// @brief Sets target tile state to FLAGGED
/// @param targetTile target
void FlagTile(tile_t *targetTile);

/// @brief sets the target tile back to HIDDEN
/// @param targetTile target
void RemoveFlagTile(tile_t *targetTile);

/// @brief set target tile state to REVEALED (player cannot undo this)
/// @param targetTile target
void RevealTile(tile_t *targetTile);

/// @brief allocates memory for tile, and returns pointer to memory (blank tile)
/// @return pointer to tile
tile_t *CreateTile();

/// @brief free target tile from memory heap
/// @param targetTile target
void DestroyTile(tile_t *targetTile);

#endif //TILE_H