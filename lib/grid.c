#include "tile.h"
#include "grid.h"
#include "settings.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    tile_t *tiles;
    int gridWidth; // init both from Settings_t
    int gridHeight; // init both from Settings_t
    int tilesFlagged_Total;
    int tilesContainingMines_Total;
    int tilesRevealed_Total;
} grid_t;


grid_t *Initgrid(grid_t *grid){
    tile_t **tiles = grid->tiles;
    int gridsize = getGridSize(grid);
    for(int i = 0; i < gridsize; i++){
        *(tiles + i) = CreateTile(); //forced to use this, because i made a design mistake in design, would've preffered to use grid->tiles[i] = ... for ease of use.
    }
}
    

void fillgrid(grid_t *grid);

void CalculateAllTiles(grid_t *grid);

void RevealAllTiles(grid_t *grid){
    tile_t **tiles = grid->tiles;
    int gridsize = getGridSize(grid);
    for(int i = 0; i < gridsize; i++){
        SetTileState(*(tiles + i), REVEALED);
    }
}

int getGridSize(grid_t *grid){
    return grid->gridHeight * grid->gridWidth;
}

grid_t *CreateGrid(settings_t *settings){
    int height = GetGridHeight(settings);
    int width = GetGridWidth(settings);
    grid_t *grid = malloc(sizeof(grid_t));
    if(grid == NULL){
        fprintf(stderr,"Fatal: Could not allocate memory for grid.");
        exit(EXIT_FAILURE);
    }
    else{
        grid->tiles = malloc(width * height * sizeof(tile_t*));
        if(grid->tiles == NULL){
            fprintf(stderr,"Fatal: Could not allocate memory for tile array.");
            free(grid);
            exit(EXIT_FAILURE);
        }
        grid->gridHeight = height;
        grid->gridWidth = width;
        grid->tilesContainingMines_Total = GetMineTotal(settings);
        grid->tilesFlagged_Total = 0;
        grid->tilesRevealed_Total = 0;
    }
}
void DestroyGrid(grid_t *grid){
    free(grid->tiles);
    free(grid);
}