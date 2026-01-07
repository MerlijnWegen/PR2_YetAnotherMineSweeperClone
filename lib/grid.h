#ifndef GRID_H
#define GRID_H
#include "tile.h"
#include "settings.h"

typedef struct grid_t grid_t;

void AddFlagged(grid_t *grid);
int GetFlaggedCount(grid_t *grid);

void AddRevealed(grid_t *grid);
int GetRevealedCount(grid_t *grid);

void SubtractFlagged(grid_t *grid);

/// @brief initialises grid filling it with tiles.
/// @param grid to initialize
/// @return grid_t element pointer
void Initgrid(grid_t *grid);


/// @brief Fills the grid with mines, but creates a safe area using the cursor and the grace area around it.
/// @param grid target grid_t to fill with mines
/// @param cursor cursor of user reveal (first click)
/// @param grace range of tiles which are safe around user's reveal
void fillgrid(grid_t *grid,int cursor[2],int *grace);

// calculate the amount of nearby mines and fill it in for each tile.

/// @brief calculate the amount of nearby mines for each tile and assigns the value to it.
/// @param grid target grid_t to
void CalculateAllTiles(grid_t *grid);

//when player clicks a mine, reveal entire screen, highlight "exploded" mines (in red or something)

/// @brief reveals all tiles (only used in debug)
/// @param grid target_grid to reveal all tiles of
void RevealAllTiles(grid_t *grid);

/// @brief Reveal a flood of empty tiles, startX and startY needs to be empty (minessurround == 0)
/// @param grid target_grid to flood reveal
/// @param StartX cursor X
/// @param StartY cursor Y
void FloodReveal(grid_t *grid, int StartX, int StartY);

/// @brief helper function to grid size (width * height)
/// @param grid target grid_t
/// @return number of elements of grid
int GetGridSize(grid_t *grid);

/// @brief get Tile pointer based off of X & Y
/// @param grid target grid to get tile of
/// @param x target X
/// @param y Target Y
/// @return tile_t pointer
tile_t *GetTile(grid_t *grid,int x, int y);

//memory

/// @brief assigns memory to grid, returns a pointer to memory
/// @param settings to initialize it with
/// @return pointer to memory
grid_t *CreateGrid(settings_t *settings);

/// @brief Frees memory of grid (includes all tiles)
/// @param grid target grid_t to free
void DestroyGrid(grid_t *grid);

#endif //GRID_H