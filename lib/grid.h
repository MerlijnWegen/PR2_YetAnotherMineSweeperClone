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

//Creates a empty grid, All tiles hidden no mines yet.
grid_t *Initgrid(grid_t *grid);

//Fill the grid, with mines and value, force the tile the player clicked on and surrounding tiles based off of grace to be empty
void fillgrid(grid_t *grid,int cursor[2],int *grace);

// calculate the amount of nearby mines and fill it in for each tile.
void CalculateAllTiles(grid_t *grid);

//when player clicks a mine, reveal entire screen, highlight "exploded" mines (in red or something)
void RevealAllTiles(grid_t *grid);

void FloodReveal(grid_t *grid, int StartX, int StartY);

//helper to determine grid size.
int GetGridSize(grid_t *grid);

//get Tile by xy
tile_t *GetTile(grid_t *grid,int x, int y);

//memory
grid_t *CreateGrid(settings_t *settings);
void DestroyGrid(grid_t *grid);

#endif //GRID_H