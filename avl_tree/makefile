CC=gcc
CFLAGS=-Wextra -Wall -g
OBJ=avl.o test_avl.o
EXEC=test_avl

all: $(EXEC) 

$(EXEC): $(OBJ)

avl.o: avl.h avl.c
test_avl.o: avl.h test_avl.c

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)