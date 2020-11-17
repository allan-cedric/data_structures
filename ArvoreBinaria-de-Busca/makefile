CC=gcc
CFLAGS=-ansi -Wall
OBJ=bst.o teste_bst.o
EXEC=teste_bst

all: teste_bst clean

teste_bst: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

bst.o: bst.h bst.c
	$(CC) -c bst.c $(CFLAGS)

teste_bst.o: bst.h bst.c
	$(CC) -c teste_bst.c $(CFLAGS)

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)