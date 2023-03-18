#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#include "array-list.h"

#define LIST_SIZE 8

typedef struct {
	unsigned int x: 8;
	unsigned int y: 8;
} enemy_t;

void draw_enemies(arraylist_t *list)
{
        clear();
	for (int i = 0; i < list->list_top; i++)
	{
		enemy_t *e = &((enemy_t *)list->items)[i];
		mvprintw(e->y, e->x, "E");
 	}
 	refresh();
}

int main()
{
        // Setup curses
        initscr();
        cbreak();
        noecho();       
        
	enemy_t a = {
		.x = 0,
		.y = 0
	};

	arraylist_t *list = arraylist_alloc(sizeof(enemy_t), LIST_SIZE);
	arraylist_push(list, &a);

	a.x = 20;
	a.y = 15;
	arraylist_push(list, &a);

	draw_enemies(list);
	getch();

	arraylist_remove(list, 0);

	draw_enemies(list);
	getch();

	arraylist_free(list);
	endwin();
	exit(0);
}
