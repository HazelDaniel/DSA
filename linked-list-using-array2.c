#include "linked-list-using-array.h"

int push_KENPHF_heap(KENPHF_list *list, int index)
{
	int prev = OOB, count = 0, i = 0, push_index = 0;

	if (count >= index)
		index = count;

	push_index = pop_KENPHF_list(list, index);
	if (push_index == OOB)
		return (OOB);

	for (i = list->free; list->next[i] != OOB; )
	{
		if (count == index)
			break;
		prev = i;
		i = list->next[i];
		count++;
	}
pushing_heap:
	if (KENPHF_full(list))
	{
		list->free = push_index;
		list->prev[list->free] = OOB, list->next[list->free] = OOB;
		return (push_index);
	}
	if (i == list->free)
	{
		if (index > 0)
		{
			list->next[list->free] = push_index;
			list->prev[push_index] = list->free;
		}
		else
		{
			list->next[push_index] = list->free;
			list->prev[list->free] = push_index;
			list->free = push_index;
		}
	}
	else
	{
		if (count < index)
		{
			if (i != OOB)
				list->next[i] = push_index;
			list->next[push_index] = OOB;
			list->prev[push_index] = i;
			return (push_index);
		}
		list->next[push_index] = list->next[prev];
		if (i != OOB)
			list->prev[i] = push_index;
		if (prev != OOB)
			list->next[prev] = push_index;
		list->prev[push_index] = prev;
	}
	return (push_index);
}

int push_KENPHF_list(KENPHF_list *list, int index)
{
	int prev = OOB, count = 0, i = 0, push_index = 0;

	if (count >= index)
		index = count;

	push_index = pop_KENPHF_heap(list, index);
	if (push_index == OOB)
		return (OOB);

	for (i = list->head; list->next[i] != OOB; )
	{
		if (count == index)
			break;
		prev = i;
		i = list->next[i];
		count++;
	}
pushing_list:
	if (KENPHF_empty(list))
	{
		list->head = push_index;
		list->prev[list->head] = OOB, list->next[list->head] = OOB;
		return (push_index);
	}
	if (i == list->head)
	{
		if (index > 0)
		{
			list->next[push_index] = list->next[list->head];
			if (list->next[list->head] != OOB)
				list->prev[list->next[list->head]] = push_index;
			list->next[list->head] = push_index;
			list->prev[push_index] = list->head;
		}
		else
		{
			list->next[push_index] = list->head;
			list->prev[list->head] = push_index;
			list->head = push_index;
		}
	}
	else
	{
		if (count < index)
		{
			if (i != OOB)
				list->next[i] = push_index;
			list->next[push_index] = OOB;
			list->prev[push_index] = i;
			return (push_index);
		}
		list->next[push_index] = list->next[prev];
		if (i != OOB)
			list->prev[i] = push_index;
		if (prev != OOB)
			list->next[prev] = push_index;
		list->prev[push_index] = prev;
	}
	return (push_index);
}

KENPHF_list *create_KENPHF(unsigned int size)
{
	KENPHF_list *new_list = (KENPHF_list *)malloc(sizeof(KENPHF_list));
	int i;
	
	if (!new_list)
		return (NULL);

	new_list->key = malloc(size * sizeof(int));
	new_list->next = malloc(size * sizeof(unsigned int));
	new_list->prev = malloc(size * sizeof(unsigned int));
	new_list->size = size;
	if (!new_list->next || !new_list->key || !new_list->next ||
		!new_list->prev)
	{
		free(new_list), free(new_list->key);
		free(new_list->next), free(new_list->prev);
		return (NULL);
	}
	_memset(new_list->key, OOB, size), _memset(new_list->next, OOB, size);
	_memset(new_list->prev, OOB, size);
	new_list->free = 0, new_list->head = OOB;
	for (i = new_list->free; i < size; i++)
	{
		new_list->key[i] = OOB, new_list->prev[i] = i - 1;
		new_list->next[i] = i != size - 1 ? i + 1 : OOB;
	}

	return (new_list);
}

void extend_KENPHF(KENPHF_list **list_ptr, unsigned int size)
{
	KENPHF_list  *new, *list = *list_ptr;
	int old_size = 0, i = 0, j = 0;

	if (!list)
	{
		*list_ptr = create_KENPHF(size);
		return;
	}

	old_size = KENPHF_size(list);
	new = create_KENPHF(size + old_size);
	if (!new)
	{
		free_KENPHF_list(list_ptr);
		return;
	}
	new->head = list->head;
	new->free = list->free;
	for (i = 0; i < old_size; i++)
	{
		new->key[i] = list->key[i], new->next[i] = list->next[i];
		new->prev[i] = list->prev[i];
	}
	new->free = i;
	new->prev[new->free] = OOB;
	free_KENPHF_list(list_ptr);
	*list_ptr = new;
}

unsigned int KENPHF_size(KENPHF_list *list)
{
	int i = OOB, j = OOB, used = 0, unused = 0;

	if (!list)
		return (0);
	if (!KENPHF_empty(list))
	{
		for (i = list->head; i != OOB; )
		{
			i = list->next[i];
			used++;
		}
	}
	if (!KENPHF_full(list))
	{
		for (j = list->free; j != OOB; )
		{
			j = list->next[j];
			unused++;
		}
	}
	printf("used is :%d\n", used);
	printf("unused is :%d\n", unused);

	return (used + unused);
}
