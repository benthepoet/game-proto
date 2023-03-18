array-list-debug: src/array-list.c
	gcc -Wall -g -o bin/array-list src/array-list.c
	gdb bin/array-list
