#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "array-list.h"

#define LIST_SIZE 8

typedef struct {
	unsigned int dead: 1;
	unsigned int hp: 4;
} enemy_t;

void print_enemies(arraylist_t *list)
{
	for (int i = 0; i < list->list_top; i++)
	{
		enemy_t *e = &((enemy_t *)list->items)[i];
		printf("%d: dead %d, hp %d\n", i, e->dead, e->hp);
 	}
}

int main()
{
	enemy_t a = {
		.dead = 1,
		.hp = 8
	};

	arraylist_t *list = arraylist_alloc(sizeof(enemy_t), 4);
	arraylist_push(list, &a);

	a.dead = 0;
	a.hp = 6;
	arraylist_push(list, &a);

	print_enemies(list);

	arraylist_remove(list, 0);

	print_enemies(list);

	arraylist_free(list);

	return 0;
}
