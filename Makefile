CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/main.c src/graph.c
OUT = projet8

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) *.exe