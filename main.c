#include <stdlib.h>
#include "lib/game.h"
#include "lib/settings.h"
#include "lib/UI.h"


int main(void){
    settings_t *settings = CreateSettings();
    game_t *game = CreateGame(settings);
    
    while(isGameRunning(game)){
        ShowMainMenu();
        MenuInput input = GetUserInput();
        SwitchMenu(input);
    }
    ExitGame(settings, game);
    return 0;
}