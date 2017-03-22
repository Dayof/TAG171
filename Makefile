BIN = bin/

all: friends.o
	gcc friends.o -o $(BIN)friends

friends.o: friends.c
	gcc -c friends.c
