CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)
OUT = build/programa

all:
	-taskkill /F /IM programa.exe 2>nul
	if not exist build mkdir build
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	$(OUT).exe

clean:
	-taskkill /F /IM programa.exe 2>nul
	rm -f $(OUT).exe