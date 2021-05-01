CC=gcc
CFLAGS=-Wextra -Wall -g
OBJ=rb.o test_rb.o
EXEC=test_rb

all: $(EXEC) 

$(EXEC): $(OBJ)

rb.o: rb.h rb.c
test_rb.o: rb.h test_rb.c

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)