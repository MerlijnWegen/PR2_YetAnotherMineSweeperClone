# Source; Programming2 -> Tutorial MakeFile
# i don't know how this works exactly, so i copied it and modified to work for our project
# - Merlijn

CC = gcc
CCFLAGS = -g -O0 -Wall -Wextra -fsanitize=address

SRC = $(wildcard lib/*.c)

build: main.c $(SRC)
	@echo "Building program"
	$(CC) $(CCFLAGS) -o minesweeper main.c $(SRC)
	@echo "Build complete. Run with ./minesweeper"

clean:
	@echo "Cleaning up..."
	rm -f minesweeper
	@echo "Cleanup complete."

# .PHONY tells make that "clean" is not a file that needs to be created
.PHONY: build clean