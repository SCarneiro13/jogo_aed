CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/fila.c src/usuario.c
OUT = build/programa

all:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)