## 19-12-2025
### Merlijn
    -KlaarZetten van workspace, Github en folder scructuur.
    -Placeholder commentaar bij elke functie geschreven, puur voor het idee duidelijk te maken


## 29-12-2025
### Merlijn
    - Hernoemen van incorrecte Enum in Struct size_t (TileValue tileType > TileType tileType) (volg struct voor namen van enum, design had verkeerde naam)
    - Toevoegen van SetTileState(tile_t *targetTile, TileState state), om functionaliteit te reflecteren van SetTileType voor netheid, leesbaarheid en encapsulatie.
    - definieren van volgende functies in tile.c
        - TileType GetTileType(tile_t *targetTile)
        - TileState GetTileState(tile_t *targetTile)
        - bool IsTileMine(tile_t *targetTile)
        - void SetTileType(tile_t *targetTile, TileType type)
        - void SetTileState(tile_t *targetTile, TileState state)
        - void SetSurroundingMineCount(tile_t *targetTile, int value)
        - void FlagTile(tile_t *targetTile)
        - void RemoveFlagTile(tile_t *targetTile)
        - void RevealTile(tile_t *targetTile)
        - tile_t *CreateTile()
        - void DestroyTile(tile_t *targetTile)