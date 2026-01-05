#ifndef UI_H
#define UI_H
#include "game.h"
#include "settings.h"

typedef enum{
    S, //Start
    C, //Config Settings
    Q, //Quit
    B, //Back
}MenuInput;

typedef enum colors{
    RED,
    BLUE,
    GREEN,
    DEFAULT,
    YELLOW,
    PURPLE,
    BROWN,
    CYAN,
    WHITE,
}Color;

//user input
GameMode ShowGameModeSelectionScreen(void);
MenuInput GetUserInput(void);

//menu
void SwitchMenu(settings_t *settings, MenuInput input, bool *HasGameStarted);
void ShowSettingMenu(settings_t *settings);
void ShowMainMenu(void);
void ExitGame(settings_t *settings, game_t *game);

//settings
int AdjustSetting(int maxValue);
void AdjustDifficulty(settings_t *settings);

//colors
void SetTextColor();

//game
void ShowGameScreen(game_t *game);
void PrintGrid(game_t *game);
void PrintTile(tile_t *tile);


//util
void ClearScreen();
void PrintTitle();
#endif //UI_H