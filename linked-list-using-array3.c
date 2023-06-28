#include "linked-list-using-array.h"

int alloc_KENPHF(KENPHF_list *list, int index)
{
	int i = OOB;

	i = push_KENPHF_list(list, index);
	return (i);
}

int free_KENPHF(KENPHF_list *list, int index)
{
	int i;

	i = push_KENPHF_heap(list, index);
	return (i);
}

int KENPHF_insert(KENPHF_list **list_ptr, int index, int value)
{
	int i = OOB;
	KENPHF_list *list = *list_ptr;

	if (KENPHF_full(list))
		extend_KENPHF(list_ptr, EXT_SIZE);

	list = *list_ptr;
	i = alloc_KENPHF(list, index);
	if (i != OOB)
		list->key[i] = value;

	return (i);
}

int KENPHF_delete(KENPHF_list **list_ptr, int index)
{
	int i = OOB;
	KENPHF_list *list = *list_ptr;

	if (KENPHF_empty(list))
		return (OOB);

	i = free_KENPHF(list, index);
	if (i != OOB)
		list->key[i] = OOB;

	return (i);
}

void print_KENPHF_list(KENPHF_list *list)
{
	int i = 0;

	if (!list || KENPHF_empty(list))
	{
		puts("(nil)");
		return;
	}

	for (i = list->head; i != OOB && list->key[i] != OOB; )
	{
		printf("=>%d\n", list->key[i]);
		i = list->next[i];
	}
}

void print_KENPHF_list_virtual(KENPHF_list *list)
{
	int i;
	char end = 0;

	if (!list || KENPHF_empty(list))
	{
		puts("(nil)");
		return;
	}

	printf("next:\t");
	for (i = 0; i < list->size; i++)
	{
		if (i == list->size - 1)
			end = '\n';
		else
			end = '\t';
		printf("%d%c", list->next[i], end);
	}
	printf("key:\t");
	for (i = 0; i < list->size; i++)
	{
		if (i == list->size - 1)
			end = '\n';
		else
			end = '\t';
		printf("%d%c", list->key[i], end);
	}
	printf("prev:\t");
	for (i = 0; i < list->size; i++)
	{
		if (i == list->size - 1)
			end = '\n';
		else
			end = '\t';
		printf("%d%c", list->prev[i], end);
	}
}

void free_KENPHF_list(KENPHF_list **list_ptr)
{
	KENPHF_list *current = *list_ptr;

	free(current->key), free(current->next);
	free(current->prev), free(current);
	*list_ptr = NULL;
}
