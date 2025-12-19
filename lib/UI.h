#ifndef UI_H
#define UI_H
#include "game.h"
#include "settings.h"

typedef enum{
    S, //Start
    C, //Config Settings
    Q, //quit
} MenuInput;

//user input
GameMode ShowGameModeSelectionScreen(void);
MenuInput GetUserInput(void);

#endif //UI_H