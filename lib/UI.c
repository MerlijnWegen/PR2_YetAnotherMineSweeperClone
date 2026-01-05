#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_gridWidth 50
#define MAX_gridHeight 50
#define MAX_startingGrace 5


GameMode ShowGameModeSelectionScreen(void){
    ClearScreen();
    PrintTitle();

    return CUSTOM; //placeholder
}

MenuInput GetUserInput(void){
    char c;
    while(c != 'S' && c != 'C' && c != 'Q'){
        scanf(" %c", &c);
        c = toupper(c);
    }
    
    switch (c)
    {
        case 'S': return S; break;
        case 'C': return C; break;
        case 'Q': return Q; break;
        case 'B': return B; break;
    }
    
    return Q;
}


void SwitchMenu(settings_t *settings, MenuInput input, bool *HasGameStarted){
    switch (input)
    {
    case S:
        *HasGameStarted = true;
        break;
    case C:
        bool adjustingSettings = true;
        while(adjustingSettings){
            char input;
            ClearScreen();
            PrintTitle();
            ShowSettingMenu(settings);
            
            scanf(" %c",&input);
            input = toupper(input);
            if(input == 'B'){
                adjustingSettings = false;
                break;
            }
            ClearScreen();
            PrintTitle();
            switch (input)
            {
                case 'D': AdjustDifficulty(settings); break;
                case 'M': 
                    if(GetGameMode(settings) != CUSTOM){
                        SetGameMode(settings,CUSTOM);
                    }
                    SetMineTotal(settings,AdjustSetting(GetGridHeight(settings) * GetGridWidth(settings)));
                    break;
                case 'H': 
                    if(GetGameMode(settings) != CUSTOM){
                        SetGameMode(settings,CUSTOM);
                    }
                    SetGridHeight(settings,AdjustSetting(MAX_gridHeight));
                    break;
                case 'W': 
                    if(GetGameMode(settings) != CUSTOM){
                        SetGameMode(settings,CUSTOM);
                    }
                    SetGridWidth(settings,AdjustSetting(MAX_gridWidth));
                    break;
                case 'G': 
                    if(GetGameMode(settings) != CUSTOM){
                        SetGameMode(settings,CUSTOM);
                    }
                    SetGridGrace(settings,AdjustSetting(MAX_startingGrace));
                    break;
                
                default:
                    printf("invalid option, try again: ");
                    break;
            }

        }
        break;
        case Q:
            ClearScreen();
            DestroySettings(settings);
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
}
int AdjustSetting(int maxValue){
    printf("Select a Value between 0 - %d\n",maxValue);

    int input;
    while(scanf(" %d", &input) != 1 && (input < 0 || input > maxValue)){
        while (getchar() != '\n');
        printf("Invalid Value, give a number between 0 and %d ", maxValue);
    }
    return input;
}



void AdjustDifficulty(settings_t *settings){
    char input;
    bool SelectingDifficulty = true;

    while(SelectingDifficulty){
        printf("Select Difficulty or (B)ack.\n");
        printf("Options: (E)asy, (N)ormal, (H)ard, (C)ustom\n");

        scanf(" %c", &input);
        input = toupper(input);

        switch (input)
        {
            case 'B':
                SelectingDifficulty = false;
                break;
            case 'E':
                SetGameMode(settings, EASY);
                SelectingDifficulty = false;
                break;
            case 'N':
                SetGameMode(settings, NORMAL);
                SelectingDifficulty = false;
                break;
            case 'H':
                SetGameMode(settings, HARD);
                SelectingDifficulty = false;
                break;
            case 'C':
                SetGameMode(settings, CUSTOM);
                SelectingDifficulty = false;
                break;
                
            default:
                printf("invalid option, try again: ");
                break;
        }
    }
}


void ShowSettingMenu(settings_t *settings){
    const char *difficulties[] = {"EASY","NORMAL","HARD", "CUSTOM"};
    int cMineTotal = 40;
    int cGridWidth = 16;
    int cGridHeight = 16;
    int cGrace = 3;
    if(GetGameMode(settings) == CUSTOM){
        cMineTotal = GetMineTotal(settings);
        cGridWidth = GetGridWidth(settings);
        cGridHeight = GetGridHeight(settings);
        cGrace = GetGridGrace(settings);
    }
    SetTextColor(BLUE);
    printf("GAMEMODE (EASY,NORMAL,HARD,CUSTOM)\n");
    SetTextColor(DEFAULT);
    printf("(D)ifficulty: ");
        switch (GetGameMode(settings))
        {
            case EASY: SetTextColor(GREEN);  break;
            case NORMAL: SetTextColor(YELLOW);  break;
            case HARD: SetTextColor(RED);  break;
            case CUSTOM: SetTextColor(BLUE);  break;
        }
        printf("%s\n", difficulties[GetGameMode(settings)]);
    SetTextColor(BLUE);
    printf("\nCUSTOM DIFFICULTY SETTINGS\n");
    SetTextColor(DEFAULT);
    printf("(M)ines: %10d MAX(Width * Height, CURRENT MAX: %d)\n",cMineTotal,cGridWidth * cGridHeight);
    printf("Grid (W)idth: %5d MAX(%d)\n",cGridWidth, MAX_gridWidth);
    printf("Grid (H)eight: %4d MAX(%d)\n",cGridHeight, MAX_gridHeight);
    printf("Grid (G)race: %5d MAX(%d)\n\n",cGrace, MAX_startingGrace);

    printf("or (B)ack\n");
    printf("Selection: ");
    
}



void ShowMainMenu(void){
    PrintTitle();
    printf("(c)2025 Merlijn Wegen - MIT license\n\n");
    SetTextColor(BLUE);
    printf("Made for: ");
    SetTextColor(DEFAULT);  
        printf("Programming 2 - Capstone project\n");
    SetTextColor(BLUE);
    printf("By: ");
    SetTextColor(DEFAULT);
        printf("Merlijn Wegen.\n\n");

    SetTextColor(BLUE);
    printf("Options:\n");
    SetTextColor(DEFAULT);
    printf("(S)tart\n");
    printf("(C)onfig\n");
    printf("(Q)uit\n\n");
    printf("Selection: ");
}


void ShowGameScreen(game_t *game){
    PrintGrid(game);
}

void PrintGrid(game_t *game){
    grid_t *grid = GetGrid(game);
    for(int y = 0; y < GetGridHeight(GetGameSettings(game));y++){
        for(int x = 0; x < GetGridWidth(GetGameSettings(game));x++){
            PrintTile(GetTile(grid,x,y));
        }   
        printf("\n");
    }
}

// @ pointer
// # hidden
// (1-8) revealed, mines nearby 
// ' ' revealed, empty
// X mine
// F mine
void PrintTile(tile_t *tile){
    printf(" ");
    if(false/**/){ //cursor / pointer/ /TODO
        SetTextColor(BLUE);
        printf("@");
        SetTextColor(DEFAULT);
        return;
    }
    TileState tileState = GetTileState(tile);
    if(tileState == FLAGGED){
        SetTextColor(YELLOW);
        printf("F");
        SetTextColor(DEFAULT);
        return;
    }
    else if(tileState == REVEALED && GetTileType(tile) == EMPTY){
        int surroundingmines = GetSurroundingMineCount(tile);
        switch (surroundingmines)
        {
        case 1: SetTextColor(BLUE);break;
        case 2: SetTextColor(GREEN);break;
        case 3: SetTextColor(RED);break;
        case 4: SetTextColor(PURPLE);break;
        case 5: SetTextColor(BROWN);break;
        case 6: SetTextColor(CYAN);break;
        case 7: SetTextColor(WHITE);break;
        case 8: SetTextColor(DEFAULT);break;
        
        default:
            printf(" ");
            return;
        }

        printf("%d",surroundingmines);
        SetTextColor(DEFAULT);
        return;
    }
    else{
        printf("M");
    }
}



void ExitGame(settings_t *settings, game_t *game){
    DestroyGame(game);
    DestroySettings(settings);
}

void SetTextColor(Color Target){
    switch (Target) //set color to red using ANSI colors
    {
        case RED: printf("\e[1;31m"); break;
        case GREEN: printf("\e[1;32m"); break;
        case YELLOW: printf("\e[1;33m"); break;
        case BLUE: printf("\e[1;34m"); break;
        case PURPLE: printf("\e[1;35m"); break;
        case BROWN: printf("\e[1;33m"); break;
        case CYAN: printf("\e[1;36m"); break;
        case WHITE: printf("\e[1;37m"); break;
        case DEFAULT: printf("\e[0;0m"); break;
    }
}


void ClearScreen(){
    printf("\033[3J\033[2J\033[H");
    fflush(stdout);
}

void PrintTitle(){
    SetTextColor(RED);
    printf("YET ANOTHER:\n");
    printf(" __  __ _____ _   _ ______  _______          ________ ______ _____  ______ _____          \n");
    printf("|  \\/  |_   _| \\ | |  ____|/ ____\\ \\        / /  ____|  ____|  __ \\|  ____|  __ \\   \n");
    printf("| \\  / | | | |  \\| | |__  | (___  \\ \\  /\\  / /| |__  | |__  | |__) | |__  | |__) |   \n");
    printf("| |\\/| | | | | . ` |  __|  \\___ \\  \\ \\/  \\/ / |  __| |  __| |  ___/|  __| |  _  /   \n");
    printf("| |  | |_| |_| |\\  | |____ ____) |  \\  /\\  /  | |____| |____| |    | |____| | \\ \\    \n");
    printf("|_|  |_|_____|_| \\_|______|_____/    \\/  \\/   |______|______|_|    |______|_|  \\_\\     \n");
    printf("clone.\n\n");
    SetTextColor(DEFAULT);

}