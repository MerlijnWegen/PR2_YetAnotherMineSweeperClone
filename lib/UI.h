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


/// @brief Restart menu post game, (R to restart M to menu)
/// @param input user input
/// @param HasGameStarted set to true or false depending on choice
/// @return true if valid input was entered, false otherwise
bool RestartMenu(MenuInput input,bool *HasGameStarted);

/// @brief Show gamemeode selection screen (currently unused)
/// @param settings target settings to modify
void ShowGameModeSelectionScreen(settings_t *settings);

/// @brief gets user input and returns it as a menu input if it's valid
/// *note: terrible function i hate it.
/// @return returns menu input if valid
MenuInput GetUserInput(void);

/// @brief Switch menu using input and hasgamestarted, sets some settings depending on menu
/// @param settings target setting to change
/// @param input user input
/// @param HasGameStarted has the game started yet (flag for starting game)
void SwitchMenu(settings_t *settings, MenuInput input, bool *HasGameStarted);

/// @brief Prints setting menu using values for settings
/// @param settings target
void ShowSettingMenu(settings_t *settings);

/// @brief prints out main menu
void ShowMainMenu(void);

/// @brief exits game, destroying all remaining allocations
/// @param settings to free
/// @param game to free
void ExitGame(settings_t *settings, game_t *game);

/// @brief adjusts a setting, cannot be above maxvalue
/// @param maxValue value to set it to
/// @return return the user input if it's under or equal to maxvalue
int AdjustSetting(int maxValue);

/// @brief Show screen to adjust difficulty, and changes it in target settings
/// @param settings target
void AdjustDifficulty(settings_t *settings);

/// @brief Sets the text color based off of COLOR ENUM
void SetTextColor();

/// @brief show game UI
/// @param game target game to print out
void ShowGameScreen(game_t *game);

/// @brief Prints out current grid, and cursor
/// @param game  target game
/// @param cursor curser x,y
/// @param Debugflag debugflag for testing
void PrintGrid(game_t *game,int cursor[2], bool *Debugflag);

/// @brief Prints out current State of tile
/// @param tile target state
/// @param cursor cursor x,y
/// @param gamestate current state of game, if GAMELOST then show location of all mines
/// @param DebugFlag debugflag for testing
void PrintTile(tile_t *tile,bool cursor, GameState gamestate, bool *DebugFlag);

/// @brief prints out UI during game, adjusting values and location of cursor every action
/// @param game target game
/// @param cursor cursor x,y
/// @param DebugFlag debugflag for testing
void GameUIHandler(game_t *game,int cursor[2], bool *DebugFlag);

/// @brief Handler for raw input during game, moving cursor, flagging, revealing
/// @param game target game
/// @param cursor cursor x,y
/// @param DebugFlag debugflag for testing
void GameInputHandler(game_t *game,int cursor[2], bool *DebugFlag);


/// @brief Clears terminal (only functions properly if it's bigger then all text)
void ClearScreen();

/// @brief Prints the Title in ascii
void PrintTitle();

/// @brief enables raw input mode 
/// based on https://stackoverflow.com/questions/50394654/receive-the-keys-as-soon-as-they-are-pressed-on-unix-console
void EnableRawInput();

/// @brief Disables raw input mode 
/// based on https://stackoverflow.com/questions/50394654/receive-the-keys-as-soon-as-they-are-pressed-on-unix-console
void DisableRawInput();

/// @brief Prints out UI for game LOST
/// @param game target
/// @param cursor cursor (unused but needed for printgrid)
void GameUIGameLOST(game_t *game,int cursor[2]);

/// @brief prints out UI for game WON
/// @param game target
void GameUIGameWON(game_t *game);


#endif //UI_H

