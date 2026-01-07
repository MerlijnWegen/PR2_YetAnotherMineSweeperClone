## 19-12-2025
### Merlijn
- KlaarZetten van workspace, Github en folder scructuur.
- Placeholder commentaar bij elke functie geschreven, puur voor het idee duidelijk te maken


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
## 05-01-2025
### Merlijn
#### Veranderingen
- uint64_t timeElapsed veranderd naar uint64_t timeGameStarted in Game_t
- Voor functionaliteit moet ik weten waneer de game begonnen is, niet hoelang het al geduurt heeft.
-  game
 -  Hernoemen van GetTimeElapsed naar GetTimeStarted
 -  GameOver, bool HasWon verwijderd, overbodig.
-  settings
 -  Verwijderen van gamemode enum uit settings.c (overbodig, bevindt zich in settings.h)
 -  Fixed bug waar setting_t CreateSetting niet een gamemode declareerde.
-  tile
 -  Verwijderen van tileType & TileState enum uit tile.c (overbodig, bevidnt zich in tile.h)
 -  Fixed bug waar SetTileState TileType veranderede ipv TileState.
 -  Verbeterede implemenatie van SetSurroundingMinecount, 
#### Toevoegingen
- game
 - uint64_t GetTimeStarted, nodig voor het beginnen van de game IPV time elapsed.
 - grid_t GetGrid, functie die nodig is voor UI & Game, anders is het onmogelijk om bij de tiles te komen.
 - settings_t, functie die nodig is om de huidige settings van de game te pakken.
- grid
 - Betere implementatie van grid_t naar **tile_t over alle functies
 - Fillgrid, vult de grid_t met empty tiles, mbv CreateTile
 - CalculateAlltiles, voegd een waarde toe aan alle tiles als er Mines nearby zijn, slaat het op in elke tile hoeveel mines in de buurt zijn.
 - RevealAllTiles,functie om alle tiles te laten zien (debug/gamelost)
 - GetTile, functie die nodig is voor GRID, UI & game, anders is het onmogelijk om bij tiles te komen.
 - DestroyGrid implementatie, fixt een memoryleak waar tiles niet correct ge-freed werden.
- Settings
 - Int GetGridGrace, help functie om de waarde van startinggrace size te krijgen.
 - void SetGridGrade, help functie om waarde van StartingGrace in te zetten.
- UI
  - Implementeren van UI, het visuele aspect van de game, vindt zich plaats in de terminal
  - Color Enum toegevoegd voor kleuren van text
  - void SwitchMenu, nodig voor het implementeren van menu's voor de game, wisselt van menu
  - ShowSettingMenu, vooraf gemaakte layout voor settings Menu, laat huidige waarde zien van settings, mogelijk om waardes aan te passen
  - ShowMainMenu, vooraf gemaakte layout voor main menu. user kan starten, config of quit.
  - Exitgame, destroyd alle objecten en sluit spel af
  - int AdjustSettings, vraagt user om niewe waarde voor de instelling, dan returned het als een int om toe te passen op settings.
  - void AdjustDifficulity, zelfde idee als adjustSettings, maar veranderd difficulty direct
  - void SetTextColor, maakt het mogelijk om de text kleur te verandered op basis van preset Color ENUM.
  - void ShowGameScreen, laat grid van mines zien met behulp van settextcolor, printgrid en printTile
  - void Printgrid, print de grid van game uit, mbv printtile
  - void PrintTile, print char uit voor elke tile in grid op basis van tilestate & type.
  - void Clearscreen, clears terminal, nodig voor updates van game en wisselen van screen in menus.
  - PrintTile, voorafgemaakte minesweeper logo.
### ANDERS
- refactoren van functies naar PascalCase

## 07-01-2025
### Merlijn
*notitie, dit is deze logbook update is geschreven op 02:30 , dus verwacht (zeer) lichte onzin.
#### Veranderingen
- game.c
  - nieuwe implemenatie voor isgamerunning getgamestate > game->gamestate
  - Startgame implementatie veranderd, zet nu aleen maar een nieuwe grid klaar voor fillgrid en calculatealltiles
  - destroygame verwijderd nu ook grid.
- grid.c
  - betere implementatie voor fillgrid, houdt nu rekening mee met grace,, veilge zone rond de cursor.
- settings.c
  - waardes van startingGrace aangepast, uit testen bleek deze te hoog.
- ui.c
  - implementeren van ShoWGameModeSelectionScreen... maar is niet gebruikt.
  - toevoegen van waardes aan getUserinput, slechte functie, maar het werkt (amper)
  - printgrid implementeren voor functionaliteit van cursor
  - printgTile, correcte implementatie van testing naar mines en hidden correct uit te printen
  - SetTextColor toevoegen van cursor
#### Toevoegingen
- main.c
  - Gamewin / gamelose logica
  - debugflag voor... testing
- game.c
  - void GameLost, returned Gamelost, triggered waneer MINE wordt gerevealed in gameinput.
  - void CheckForGameWon, simpele functie die kijkt als er evenveel mines als hidden tiles zijn, zet gamesate naar GAMEWON
  - debugcheats, buggy broken en amper functionele functie voor het testen van de game.
- grid.c
  - void AddFlagged, telt hoeveelheid flagged tiles op, was functionaliteit vergeten in design
  - int GetFlagged count, returned hoeveelheid flagged tiles, was functionaliteit vergeten in design
  - int getrevealedcount, returned hoeveelheid revealed tiles, was functionaliteit vergeten in design
  - void addRevealed, telt hoeveelheid revealed tiles op, was functionaleit vergeten in design
  - void subrtractflagged, telt af hoeveelheid flagged tiles,     ^
  - void FloodReveal, waneer een lege tile zonder waarde is gerevealed zal het alle lege tiles erond heen ook revealen, gebruitk een array om dit te herhalen met elk verbonden tile
- UI.c
  - bool RestartMenu, functie voor na GAMEOVER, dat user limieteert om te restarten of terug naar menu, returned bool voor logica in while loop
  - void GameUiHandler functie voor de UI te printen tijdens het spelen van de game.
  - void GameInputHandler, functie voor de logica van controls voor het spel te handelen,
  - void EnableRawInput, functie voor het enablen van directie invoer, door ECHO en CANON te disabelen
    - Gebaseerd op https://stackoverflow.com/questions/50394654/receive-the-keys-as-soon-as-they-are-pressed-on-unix-console
  - void DisableRawInput, functie voor het enablen van directie invoer, door ECHO en CANON te enablen
    - Gebaseerd op https://stackoverflow.com/questions/50394654/receive-the-keys-as-soon-as-they-are-pressed-on-unix-console
  - void GameUiGameLOSt, functie voor het uitprinten van een premade layout voor als player verlies, zonder functionaliteit om te spelen
  - void GameUIGameWON, functie voor het uitprintend van een premade layout voor als de player wint, laat zien hoelang player heefd geduurt in minuten en seconden.





## 02-01-2025
### Merlijn
#### Veranderingen
#### Toevoegingen