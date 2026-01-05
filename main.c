#include <stdlib.h>
#include <stdio.h>
#include "lib/game.h"
#include "lib/settings.h"
#include "lib/UI.h"


int main(void){
    srand((unsigned int)time(NULL)); //for use in grid generation.
    settings_t *settings = CreateSettings(NORMAL);
    game_t *game;
    
    bool HasGameStarted = false;

    while(true){
        
        while(!HasGameStarted){
            ClearScreen();
            ShowMainMenu();

            //menus 
            MenuInput input = GetUserInput();
            SwitchMenu(settings,input,&HasGameStarted);
        }
        // GameMode difficulty = ShowGameModeSelectionScreen();
        // if(GetGameMode(settings) != difficulty){
        //     SetGameMode(settings,difficulty);
        // }


        game = CreateGame(settings);
        StartGame(game);
        ClearScreen();
        while(IsGameRunning(game)){
            ClearScreen();
            PrintTitle();
            RevealAllTiles(GetGrid(game));
            ShowGameScreen(game);
            
            GetUserInput();
        }
        DestroyGame(game);
    }
    //won't reach here, look at SwitchMenu instead.
    return 0;
}