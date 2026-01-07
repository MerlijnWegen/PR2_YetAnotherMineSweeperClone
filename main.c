#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include "lib/game.h"
#include "lib/settings.h"
#include "lib/UI.h"




int main(int argc, char*argv[]){
    bool Debugflag = false;
    if(argc == 2 && strcmp(argv[1],"-D") == 0){
        Debugflag = true;
    }
    srand((unsigned int)time(NULL)); //for use in grid generation
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


        game = CreateGame(settings);
        StartGame(game);
        int cursor[] = {0,0};
        EnableRawInput();
        while(IsGameRunning(game)){
            ClearScreen();
            GameUIHandler(game, cursor,&Debugflag);
            GameInputHandler(game,cursor,&Debugflag);
            CheckForGameWON(game);       
        }
        DisableRawInput();
        MenuInput inputGame;
        switch (GetGameState(game))
        {
            case GAMELOST:
                //show screen one last time with mines revealed.
                ClearScreen();
                GameUIGameLOST(game,cursor);
                inputGame = GetUserInput();
                while(!RestartMenu(inputGame, &HasGameStarted)){
                    inputGame = GetUserInput();
                }
                break;
            case GAMEWON:
                ClearScreen();
                GameUIGameWON(game);
                while(!RestartMenu(inputGame, &HasGameStarted)){
                    inputGame = GetUserInput();
                }
                break;
            default:
                printf("wrongGameState");
                exit(EXIT_FAILURE);
                break;
        }
        DestroyGame(game);
        

    }
    //won't reach here, look at SwitchMenu instead.
    return 0;
}