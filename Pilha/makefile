CC=gcc
CFLAGS=-ansi -Wall
OBJ=pilha.o teste_pilha.o
EXEC=teste_pilha

all: teste_pilha clean

teste_pilha: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

pilha.o: pilha.h pilha.c
	$(CC) -c pilha.c $(CFLAGS)

teste_pilha.o: pilha.h pilha.c
	$(CC) -c teste_pilha.c $(CFLAGS)

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)