#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_SIZE 8

typedef struct {
	void *items;
	unsigned item_size;
	unsigned int list_top;
	unsigned int list_length;
} arraylist_t;

typedef struct {
	unsigned int dead: 1;
	unsigned int hp: 4;
} enemy_t;

arraylist_t *arraylist_alloc(unsigned int item_size, unsigned int list_length)
{
	arraylist_t *list = malloc(sizeof(arraylist_t));
	list->items = malloc(item_size * list_length);
	list->item_size = item_size;
	list->list_top = 0;
	list->list_length = list_length;
	return list;
}

void arraylist_free(arraylist_t *list)
{
	free(list->items);
	free(list);
}

void arraylist_push(arraylist_t *list, void *item)
{
	unsigned int current_top = list->list_top++;
	void *dest = list->items + (current_top * list->item_size);
	memcpy(dest, item, list->item_size);
}

void arraylist_remove(arraylist_t *list, unsigned int index)
{
	if (list->list_top <= 0 || index >= list->list_top)
	{
		return;
	}

	if (--list->list_top == index)
	{
		return;
	}

	void *src = list->items + (list->list_top * list->item_size);
	void *dest = list->items + (index * list->item_size);

	memcpy(dest, src, list->item_size);
}

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
