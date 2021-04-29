CC=gcc
CFLAGS=-Wextra -Wall -g
OBJ=stack.o test_stack.o
EXEC=test_stack

all: $(EXEC)

$(EXEC): $(OBJ)

stack.o: stack.h stack.c
test_stack.o: stack.h test_stack.c

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)