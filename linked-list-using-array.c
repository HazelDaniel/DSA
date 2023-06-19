#include "data-structures.h"


void free_obj(obj_impl_t **head, int x)
{
	obj_impl_t *current = *head;

	if (!current || x == OOB)
		return;
	current->storage->next[x] = current->free;
	current->free = x;
}

void print_list(obj_impl_t **head)
{
	obj_impl_t *current = *head;
	int index = -1;

	if (!current || !current->storage)
		puts("(nil)");

	index = current->head;
	if (index == OOB)
		puts("(nil)");
	while (index > OOB)
	{
		printf("%d\n", current->storage->key[index]);
		index = current->storage->next[index];
	}

}

int list_insert(obj_impl_t **head, int index, int value)
{
	obj_impl_t *current = *head;
	
	if (!current || !current->storage || index == OOB)
		return (OOB);

	current->storage->prev[index] = OOB;
	current->storage->next[index] = current->head;
	if (current->head != OOB)
		current->storage->prev[current->head] = index;
	current->head = index;
	current->storage->key[index] = value;
	return (index);
}

int allocate_obj(obj_impl_t **head)
{
	obj_impl_t *current = *head;
	int index = OOB;

	if (!current  || !current->storage || current->free == OOB)
	{
		if (!current)
			puts("no current");
		if (!current->storage)
			puts("no storage");
		if (current->free == OOB)
			puts("invalid allocation");
		return (index);
	}

	index = current->free;
	current->free = current->storage->next[index];
	return (index);
}

obj_impl_t *init_list(unsigned int size)
{
	obj_impl_t *new_list = (obj_impl_t *)malloc(sizeof(obj_impl_t));
	
	if (!new_list)
		return (0);
	new_list->storage = (list_impl_t *)malloc(sizeof(list_impl_t));
	if (!new_list->storage)
		return (0);
	new_list->storage->next = (int *)malloc(sizeof(int) * (size + 1));
	if (!new_list->storage->next)
		return (0);
	memset(new_list->storage->next, -1, (size + 1));
	new_list->storage->prev = (int *)malloc(sizeof(int) * (size + 1));
	if (!new_list->storage->prev)
		return (0);
	memset(new_list->storage->prev, -1, (size + 1));
	new_list->storage->key = (int *)malloc(sizeof(int) * (size + 1));
	if (!new_list->storage->key)
		return (0);
	memset(new_list->storage->key, -1, (size + 1));

	new_list->free = 0;
	new_list->head = -1;

	return (new_list);
}

void free_list(obj_impl_t **head)
{
	obj_impl_t *current = *head;
	int *prev_tmp, *next_tmp, *key_tmp;

	if (!current)
		return;

	if (current->storage)
	{
		free(current->storage->prev);
		free(current->storage->next);
		free(current->storage->key);
	}
	free(current->storage);
	*head = NULL;
}
