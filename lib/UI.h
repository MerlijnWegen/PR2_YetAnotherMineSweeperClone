#ifndef UI_H
#define UI_H
#include "game.h"
#include "settings.h"

typedef enum MenuInput{
    S, //Start
    C, //Config Settings
    Q, //Quit
    B, //Back
    M, //MENU (from Game)
    R, //REstart (from Game)
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
    CURSOR,
}Color;


//user input
bool RestartMenu(MenuInput input,bool *HasGameStarted);
void ShowGameModeSelectionScreen(settings_t *settings);
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
void PrintGrid(game_t *game,int cursor[2], bool *Debugflag);
void PrintTile(tile_t *tile,bool cursor, GameState gamestate, bool *DebugFlag);
void GameUIHandler(game_t *game,int cursor[2], bool *DebugFlag);
void GameInputHandler(game_t *game,int cursor[2], bool *DebugFlag);

//util
void ClearScreen();
void PrintTitle();

/// @brief based on https://stackoverflow.com/questions/50394654/receive-the-keys-as-soon-as-they-are-pressed-on-unix-console
void EnableRawInput();

/// @brief based on https://stackoverflow.com/questions/50394654/receive-the-keys-as-soon-as-they-are-pressed-on-unix-console
void DisableRawInput();
void GameUIGameLOST(game_t *game,int cursor[2]);
void GameUIGameWON(game_t *game);


#endif //UI_H

