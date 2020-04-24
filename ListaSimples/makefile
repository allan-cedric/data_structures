CC=gcc
CFLAGS=-ansi -Wall
OBJ=lista.o teste_lista.o
EXEC=teste_lista

all: $(EXEC) clean

teste_lista: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

lista.o: lista.h lista.c
	$(CC) -c lista.c $(CFLAGS)

teste_lista.o: lista.h lista.c
	$(CC) -c teste_lista.c $(CFLAGS)

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)
