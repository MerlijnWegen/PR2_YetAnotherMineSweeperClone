## Manual for
Yet another:
```
 __  __ _____ _   _ ______  _______          ________ ______ _____  ______ _____          
|  \/  |_   _| \ | |  ____|/ ____\ \        / /  ____|  ____|  __ \|  ____|  __ \   
| \  / | | | |  \| | |__  | (___  \ \  /\  / /| |__  | |__  | |__) | |__  | |__) |   
| |\/| | | | | . ` |  __|  \___ \  \ \/  \/ / |  __| |  __| |  ___/|  __| |  _  /   
| |  | |_| |_| |\  | |____ ____) |  \  /\  /  | |____| |____| |    | |____| | \ \    
|_|  |_|_____|_| \_|______|_____/    \/  \/   |______|______|_|    |______|_|  \_\     
```
clone.

## How to start the game
You can start the game by putting the minesweeper into any linux machine, having a terminal with "minesweeper" in the same folder and entering "./minesweeper".

Alternatively you can double click "MineSweeper.bat" and clicking on "Run" to start the game automatically
(if you have WSL installed with ubuntu linux)


## How to play
### Starting the game
You can start the game by entering "S" and press enter.

### Changing settings
Before you start you can alter the settings by entering "C" and pressing enter,
in this setting menu you can alter the provided settings by entering the letter between parenthesis, pressing enter and entering the values you want.

#### Example:
To change difficulty to easy, enter "C" from the main menu and press enter to go to (C)onfig, 
then enter "D" for (D)ifficulty pressing enter again, then "E" and enter to finish changing the difficulty, you can then enter "B" and then enter to head (B)ack to menu, where you can press "S" and enter to (S)tart.


### Quitting the game
You can close the game at any time by pressing the red cross on the top right of the terminal, or you can enter "Q" and press enter in the main menu.


## Playing the game
The aim of MineSweeper is to reveal all of the tiles NOT containing a Mine, each tile can contain one but you have to figure out which tiles do, you can use the numbers on the grid, these numbers represent the number of mines in the 8 tiles surrounding it, so incase of a '1' there is a single mine in the 8 surrounding grids, you can use several of these numbered tiles to figure out which tiles contain a mine.

If you succeed and reveal all the tiles NOT containing a mine you Win!
if at any time you reveal a tile containing a mine you lose

Either way, you can (r)estart by entering "R" and then pressing enter, or head back to the (M)ain menu, by entering "M" and then pressing enter


#### Controls
"Arrow keys" to move the curser (UP,DOWN,LEFT,RIGHT),
"Spacebar" to reveal a tile
"F" to flag a tile.

#### Flags
Flags can be used to keep track of where the mines are, and to mark them, so you cannot accidentally reveal them
a flag can be placed by pressing 'F' and be removed by moving the cursor ontop and pressing 'F" again.

#### Revealing
A tile starts out as hidden ("#") you can reveal a tile my pressing "Spacebar", if you reveal a tile containing a mine you lose. A tile cannot be hidden again.
