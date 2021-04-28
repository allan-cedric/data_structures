CC=gcc
CFLAGS=--std=c99 -Wextra -Wall -g
OBJ=linked_list.o test_linked_list.o
EXEC=test_linked_list

all: $(EXEC)

$(EXEC): $(OBJ)

linked_list.o: linked_list.h linked_list.c
test_linked_list.o: linked_list.h test_linked_list.c

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)
