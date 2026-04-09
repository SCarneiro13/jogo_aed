CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)
OUT = build/programa

all:
	if not exist build mkdir build
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	$(OUT).exe

clean:
	rm -f $(OUT)