#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
	void *items;
	uint8_t item_size;
	uint8_t list_top;
	uint8_t list_length;
} arraylist_t;

arraylist_t *arraylist_alloc(uint8_t item_size, uint8_t list_length);
void arraylist_free(arraylist_t *list);
void arraylist_push(arraylist_t *list, void *item);
void arraylist_remove(arraylist_t *list, unsigned int index);

#endif