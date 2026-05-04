CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/main.c src/graph.c src/io.c src/pagerank.c
OUT = projet8.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)