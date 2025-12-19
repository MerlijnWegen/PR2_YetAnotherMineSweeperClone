#ifndef GRID_H
#define GRID_H
#include "tile.h"
#include "settings.h"

typedef struct grid_t grid_t;

//prototypes
grid_t *Initgrid(grid_t *grid);
void fillgrid(grid_t *grid);
void CalculateAllTiles(grid_t *grid);
void RevealAllTiles(grid_t *grid);

//memory
grid_t *CreateGrid(settings_t *settings);
void DestroyGrid(grid_t *grid);

#endif //GRID_H