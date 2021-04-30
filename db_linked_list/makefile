CC=gcc
CFLAGS=-Wextra -Wall -g
OBJ=db_linked_list.o test_db_linked_list.o
EXEC=test_db_linked_list

all: $(EXEC)

$(EXEC): $(OBJ)

db_linked_list.o: db_linked_list.h db_linked_list.c
test_db_linked_list.o: db_linked_list.h test_db_linked_list.c

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)