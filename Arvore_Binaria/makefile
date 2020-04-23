CC=gcc
CFLAGS=-ansi -Wall
OBJ=arvore_binaria.o teste_arvore.o
EXEC=teste_arvore

all: teste_arvore clean

teste_arvore: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

arvore_binaria.o: arvore_binaria.h arvore_binaria.c
	$(CC) -c arvore_binaria.c $(CFLAGS)

teste_arvore.o: arvore_binaria.h arvore_binaria.c
	$(CC) -c teste_arvore.c $(CFLAGS)

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)