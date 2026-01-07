@echo off

:: get filepath from cmd, convert to wsl filepath, use bash to run the command "cd \filepath\" then run "./minesweeper"
wsl bash -lc "cd \"$(wslpath '%~dp0')\" && ./minesweeper"
