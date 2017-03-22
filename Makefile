BIN = bin/
OBJ = obj/
CC = gcc

all: clean1 $(OBJ)friends.o
	$(CC) $(OBJ)friends.o -o $(BIN)friends

$(OBJ)friends.o: friends.c
	$(CC) -c -o $@ $<

clean1:
	rm -rf bin/*
