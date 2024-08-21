CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD=../build/

all: Quest_1 Quest_2 Quest_3 Quest_4 Quest_5

Quest_1: main_module_entry_point.o print_module.o
	$(CC) $(CFLAGS) -o $(BUILD)Quest_1 main_module_entry_point.o print_module.o

Quest_2: $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD)Quest_2 main_module_entry_point.o documentation_module.o

Quest_3: bst_create_test.o bst.o
	$(CC) $(CFLAGS) -o $(BUILD)Quest_3 bst_create_test.o bst.o

Quest_4: bst_insert_test.o bst.o
	$(CC) $(CFLAGS) -o $(BUILD)Quest_4 bst_insert_test.o bst.o

Quest_5: bst_traverse_test.o bst.o
	$(CC) $(CFLAGS) -o $(BUILD)Quest_5 bst_traverse_test.o bst.o

main_module_entry_point.o: main_module_entry_point.c print_module.h documentation_module.h
	$(CC) $(CFLAGS) -c main_module_entry_point.c

print_module.o: print_module.c print_module.h
	$(CC) $(CFLAGS) -c print_module.c

documentation_module.o: documentation_module.c documentation_module.h
	$(CC) $(CFLAGS) -c documentation_module.c

bst_create_test.o: bst_create_test.c bst.h
	$(CC) $(CFLAGS) -c bst_create_test.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

bst_insert_test.o: bst_insert_test.c bst.h
	$(CC) $(CFLAGS) -c bst_insert_test.c

bst_traverse_test.o: bst_traverse_test.c bst.h
	$(CC) $(CFLAGS) -c bst_traverse_test.c

clean:
	rm -f main_module_entry_point.o print_module.o $(BUILD)Quest_1
	rm -f main_module_entry_point.o documentation_module.o $(BUILD)Quest_2
	rm -f bst_create_test.o bst.o $(BUILD)Quest_3
	rm -f bst_insert_test.o bst.o $(BUILD)Quest_4
	rm -f bst_traverse_test.o bst.o $(BUILD)Quest_5