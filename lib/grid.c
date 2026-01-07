#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "grid.h"



typedef struct grid_t{
    tile_t *tiles; //should've been **tiles, but alas. Design mistake i'm not allowed to fix, was meant to be a grid, not a flat array
    int gridWidth; // init both from Settings_t
    int gridHeight; // init both from Settings_t
    int tilesFlagged_Total;
    int tilesContainingMines_Total;
    int tilesRevealed_Total;
}grid_t;


void AddFlagged(grid_t *grid){
    grid->tilesFlagged_Total++;
}

int GetFlaggedCount(grid_t *grid){
    return grid->tilesFlagged_Total;
}

int GetRevealedCount(grid_t *grid){
    return grid->tilesRevealed_Total;
}


void AddRevealed(grid_t *grid){
    grid->tilesRevealed_Total++;
}

void SubtractFlagged(grid_t *grid){
    if(grid->tilesContainingMines_Total > 0){
        grid->tilesFlagged_Total--;
    }
}



grid_t *Initgrid(grid_t *grid){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris
    int gridsize = GetGridSize(grid);
    for(int i = 0; i < gridsize; i++){
        tiles[i] = CreateTile(); 
    }
    return grid;
}
    

void fillgrid(grid_t *grid,int cursor[2],int *grace){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris
    int mineTotal = grid->tilesContainingMines_Total;
    int mineCount = 0;
    int graceRange = *grace;

    int width = grid->gridHeight;


    while(mineCount < mineTotal){
        int random = rand() % GetGridSize(grid);
        int randomX = random % width;
        int randomY = random / width;

        if(GetTileType(tiles[random]) == MINE){
            continue;
        }

        if(randomX <= cursor[0] + graceRange && randomX >= cursor[0] - graceRange && randomY <= cursor[1] + graceRange && randomY >= cursor[1] - graceRange){
            continue;
        }

        SetTileType(tiles[random],MINE);
        mineCount++;
    }
}
    

void CalculateAllTiles(grid_t *grid){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris;

    int width = grid->gridWidth;
    int height = grid->gridHeight;

    for(int i = 0; i < width * height; i++){
        int minecount = 0;
        int x = i % width;
        int y = i / width;

        for(int row = -1; row <= 1; row++){
            for(int column = -1; column <= 1;column++){
                if(row == 0 && column == 0){
                    continue;
                }
                int targetX = x + column;
                int targetY = y + row;
                int targetIndex = ((targetY * width) + targetX);

                if(targetX < 0 || targetX >= width || targetY < 0 || targetY >= height){
                    continue;
                }
                if(GetTileType(tiles[targetIndex]) == MINE){
                    minecount++;
                }
            }
        }
        SetSurroundingMineCount(tiles[i],minecount);
    }
}

void RevealAllTiles(grid_t *grid){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris
    int gridsize = GetGridSize(grid);

    for(int i = 0; i < gridsize; i++){
        SetTileState(tiles[i], REVEALED);
    }
}

void FloodReveal(grid_t *grid, int StartX, int StartY){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris
    int gridSize = grid->gridWidth * grid->gridHeight;

    int RevealList[gridSize][2];
    int head = 0;
    int tail = 0;

    RevealList[tail][0] = StartX;
    RevealList[tail][1] = StartY;
    tail++;

    while(head < tail){
        int x = RevealList[head][0];
        int y = RevealList[head][1];
        head++;

        if(x < 0 || x >= grid->gridWidth || y < 0 || y >= grid->gridHeight){
            continue;
        }
        tile_t *tile = tiles[(y * grid->gridWidth) + x];
        if(GetTileState(tile) == REVEALED || GetTileState(tile) == FLAGGED){
            continue;
        }
        AddRevealed(grid);
        RevealTile(tile);
        if(GetSurroundingMineCount(tile) > 0){
            continue;
        }

        for(int neighborY = -1; neighborY  <= 1; neighborY ++){
            for(int neighborX = -1; neighborX <= 1;neighborX++){
                if(neighborX == 0 && neighborY == 0){
                    continue;
                }

                int targetX = neighborX + x;
                int targetY = neighborY + y;


                if(targetX  < 0 || targetX  >= grid->gridWidth || targetY < 0 || targetY >= grid->gridHeight){
                    continue;
                }
                tile_t *target = tiles[(targetY * grid->gridWidth) + targetX ];
                if(GetTileState(target) == HIDDEN){
                    if(GetSurroundingMineCount(target) == 0){
                        RevealList[tail][0] = targetX;
                        RevealList[tail][1] = targetY;
                        tail++;
                    }   
                    else{
                        RevealTile(target);
                        AddRevealed(grid);
                    }
                }
            }
        }
    }
}

int GetGridSize(grid_t *grid){
    return grid->gridHeight * grid->gridWidth;
}

tile_t *GetTile(grid_t *grid,int x, int y){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris
    return tiles[(y * grid->gridWidth) + x];
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
    return grid;
}

void DestroyGrid(grid_t *grid){
    tile_t **tiles = (tile_t **)grid->tiles; //hubris
    int gridsize= GetGridSize(grid);
    for(int i = 0; i < gridsize;i++){
        DestroyTile(tiles[i]);
    }
    free(grid->tiles);
    free(grid);
}