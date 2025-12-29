## 19-12-2025
### Merlijn
    -KlaarZetten van workspace, Github en folder scructuur.
    -Placeholder commentaar bij elke functie geschreven, puur voor het idee duidelijk te maken


## 29-12-2025
### Merlijn
#### Veranderingen
    - Hernoemen van incorrecte Enum in Struct size_t in tile.h (TileValue tileType > TileType tileType) 
      - volgt struct voor namen van enum, design had verkeerde naam, hernoemd om verwarring te verkomen.
    - hernoemen van incorrect Functie GetMineCount in settings.h (SetMineCount > GetMineTotal) 
      - functie naam komt niet overeen met struct settings_t, hernoemd om verwarring te verkomen.
    - hernoemen van incorrect Functie SetMineCount in settings.h (SetMineCount > SetMineTotal) 
      - functie naam komt niet overeen met struct settings_t, hernoemd om verwarring te verkomen.
  
#### Toevoegingen
    - Toevoegen van SetTileState(tile_t *targetTile, TileState state), om functionaliteit te reflecteren van SetTileType leesbaarheid en encapsulatie.
    - definieren van volgende functies in tile.c
        - TileType GetTileType(tile_t *targetTile)
        - TileState GetTileState(tile_t *targetTile)
        - int GetSurroundingMineCount(tile_t *targetTile)
        - bool IsTileMine(tile_t *targetTile)
        - void SetTileType(tile_t *targetTile, TileType type)
        - void SetTileState(tile_t *targetTile, TileState state)
        - void SetSurroundingMineCount(tile_t *targetTile, int value)
        - void FlagTile(tile_t *targetTile)
        - void RemoveFlagTile(tile_t *targetTile)
        - void RevealTile(tile_t *targetTile)
        - tile_t *CreateTile()
        - void DestroyTile(tile_t *targetTile)
    - Defineren van settings.c (gebruikt huidig Defines voor default waardes.)
    -  definieren van volgende functies in settings.c
        - GameMode GetGameMode(settings_t *settings)
        - int GetGridWidth(settings_t *settings)
        - int GetGridHeight(settings_t *settings)
        - int GetMineTotal(settings_t *settings)
        - void SetGameMode(settings_t *settings, GameMode difficulty)
        - void SetGridWidth(settings_t *settings, int width)
        - void SetGridHeight(settings_t *settings,int height)
        - void SetMineTotal(settings_t *settings, int minecount)
        - settings_t *CreateSettings(void)
        - void DestroySettings(settings_t *settings)
   - Helper functie int getGridSize(grid_t *grid) om te verkomen dat grid->width * grid->height elke keer gebruikt moet worden.
   - definieren van volgende functies in grid.c
       -   grid_t *Initgrid(grid_t *grid)
       -   void RevealAllTiles(grid_t *grid)
       -   int getGridSize(grid_t *grid)
       -   grid_t *CreateGrid(settings_t *settings)
       -   void DestroyGrid(grid_t *grid)