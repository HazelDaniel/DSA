#include "data-structures.h"
#include "linked-list-using-array.h"

int KENPHF_full(KENPHF_list *list)
{
	if (!list)
		return (1);
	if (list->free == OOB)
		return (1);
	return (0);
}

int KENPHF_empty(KENPHF_list *list)
{
	if (!list)
		return (1);
	if (list->head == OOB)
		return (1);
	return (0);
}

int pop_KENPHF_list(KENPHF_list *list, int index)
{
	int prev = OOB, count = 0, i = 0;

	if (KENPHF_empty(list))
		return (OOB);

	if (count >= index)
	{
		index = count;
		goto popping_list;
	}

	for (i = list->head; list->next[i] != OOB; )
	{
		if (count == index)
			break;
		prev = i;
		i = list->next[i];
		count++;
	}
popping_list:
	if (count == index)
	{
		if (prev != OOB && i != OOB)
		{
			list->next[prev] = list->next[i];
			if (list->next[i] != OOB)
				list->prev[list->next[i]] = prev;
		}
	}
	else
	{
		if (list->prev[i] != OOB)
			list->next[list->prev[i]] = OOB;
	}

	return (i);
}

int pop_KENPHF_heap(KENPHF_list *list, int index)
{
	int prev = OOB, count = 0, i = 0, j = OOB;

	if (KENPHF_full(list))
		return (OOB);

	if (count >= index)
		index = count;

	for (i = list->free; list->next[i] != OOB; )
	{
		if (count == index)
			break;
		prev = i;
		i = list->next[i];
		count++;
	}
	if (list->next[i] == OOB)
	{
		if (i == list->free)
		{
			list->free = OOB;
		}
		if (list->prev[i] != OOB)
			list->next[list->prev[i]] = OOB;
		list->prev[i] = OOB;
		index = i;
	}
	else
	{
		if (i == list->free)
		{
			printf("free was :%d\n", list->free);
			list->free = list->next[list->free];
			list->prev[i] = OOB, list->next[i] = OOB;
			printf("free is :%d\n", list->free);
			printf("list->next[i] = %d\n", list->next[i]);
			// list->next[list->free] = OOB, list->prev[list->free] = OOB;
			// list->key[list->free] = OOB, list->free = OOB;

			return (i);
		}
		if (list->prev[i] != OOB)
			list->next[list->prev[i]] = list->next[i];
		if (list->next[i] != OOB)
			list->prev[list->next[i]] = list->prev[i];
		list->next[i] = OOB;
		list->prev[i] = OOB;
	}
	// printf("i is :%d\n", i);
	printf("index will be :%d\n",index);
	return (index);

	// if (count == index)
	// {
	// 	if (prev == OOB)
	// 	{
	// 		j = list->free;
	// 		list->free = list->next[list->free];
	// 		list->prev[list->free] = OOB;
	// 		return (j);
	// 	}
	// 	if (prev != OOB && i != OOB)
	// 	{
	// 		list->next[prev] = list->next[i];
	// 	}
	// 	if (list->next[i] != OOB)
	// 	{
	// 		list->prev[list->next[i]] = prev;
	// 	}
	// }
	// else
	// {
	// 	if (list->prev[i] != OOB)
	// 		list->next[list->prev[i]] = OOB;
	// }

	// return (i);
}

int push_KENPHF_heap(KENPHF_list *list, int index)
{
	int prev = OOB, count = 0, i = 0, push_index = 0;

	if (count >= index)
		index = count;

	push_index = pop_KENPHF_list(list, index);
	if (push_index == OOB)
		return (OOB);
	if (index == count)
		goto pushing_heap;

	for (i = list->free; list->next[i] != OOB; )
	{
		if (count == index - 1)
			break;
		prev = i;
		i = list->next[i];
		count++;
	}
pushing_heap:
	if (count == 0)
		list->next[push_index] = OOB;
	else
		list->next[push_index] = list->next[i];
	list->free = push_index;
	if (list->next[i] != OOB)
		list->prev[list->next[i]] = push_index;
	return (push_index);
}

int push_KENPHF_list(KENPHF_list *list, int index)
{
	int prev = OOB, count = 0, i = 0, push_index = 0;

	if (count >= index)
		index = count;

	// printf("the size of the list is :%d\n", KENPHF_size(list));
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
	// printf("next index position is :%d\n", i);
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
			// printf("head was at index :%d\n", list->head);
			// printf("push index is :%d\n", push_index);
			// printf("i is :%d\n",i);
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
		list->next[push_index] = list->next[prev];
		if (list->next[prev] != OOB)
			list->prev[list->next[prev]] = push_index;
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
	new_list->next = malloc(size * sizeof(int));
	new_list->prev = malloc(size * sizeof(int));
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
	KENPHF_list *current = *list_ptr, *new;
	int old_size = 0, i, j;

	if (!current)
	{
		current = create_KENPHF(size);
		*list_ptr = current;
		return;
	}
	old_size = KENPHF_size(current);
	new = create_KENPHF(size + old_size);
	if (!new)
	{
		free_KENPHF_list(&current);
		return;
	}
	new->key = current->key, new->head = current->head;
	new->free = current->free;
	for (i = 0; i < old_size; i++)
	{
		if (new->next[i] == OOB)
			j = i;
		new->key[i] = current->key[i], new->next[i] = current->next[i];
		new->prev[i] = current->prev[i];
	}
	new->next[j] = old_size;
	new->prev[old_size] = j;
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
			// puts("list");
			i = list->next[i];
			used++;
		}
	}
	if (!KENPHF_full(list))
	{
		for (j = list->free; j != OOB; )
		{
			// puts("free");
			j = list->next[j];
			unused++;
		}
	}
	printf("used is :%d\n", used);
	printf("unused is :%d\n", unused);

	return (used + unused);
}

int alloc_KENPHF(KENPHF_list *list, int index)
{
	int i;

	i = push_KENPHF_list(list, index);
	return (i);
}

int free_KENPHF(KENPHF_list *list, int index)
{
	int i;

	i = push_KENPHF_heap(list, index);
	return (i);
}

int KENPHF_insert(KENPHF_list *list, int index, int value)
{
	int i;

	if (KENPHF_full(list))
		extend_KENPHF(&list, 100);

	i = alloc_KENPHF(list, index);
	if (i != OOB)
		list->key[i] = value;
	else
		return (i);

	return (i);
}

int KENPHF_delete(KENPHF_list *list, int index)
{
	int i;

	if (KENPHF_full(list))
		extend_KENPHF(&list, 100);

	i = free_KENPHF(list, index);
	if (i != OOB)
		list->key[i] = OOB;
	else
		return (i);

	return (1);
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
	printf("last index is :%d\n", i);
}

void print_KENPHF_list_virtual(KENPHF_list *list)
{
	int i;
	char end = 0;

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
	free(current->prev);
	*list_ptr = NULL;
}
