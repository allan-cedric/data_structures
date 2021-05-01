CC=gcc
CFLAGS=-Wextra -Wall -g
OBJ=bst.o test_bst.o
EXEC=test_bst

all: $(EXEC) 

$(EXEC): $(OBJ)

bst.o: bst.h bst.c
test_bst.o: bst.h test_bst.c

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)