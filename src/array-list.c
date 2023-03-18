#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "array-list.h"

arraylist_t *arraylist_alloc(uint8_t item_size, uint8_t list_length)
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
