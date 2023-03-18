array-list-test: src/array-list.c src/array-list-test.c
	gcc -Wall -g -lcurses -o bin/array-list-test src/array-list.c src/array-list-test.c
	gdb bin/array-list-test
