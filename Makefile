CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/funcoes.c
OUT = build/programa

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)