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
	int prev = OOB, count = 0, i = 0, j = OOB;

	if (KENPHF_empty(list))
		return (OOB);

	if (count >= index)
		index = count;

	for (i = list->head; list->next[i] != OOB; )
	{
		if (count == index)
			break;
		prev = i;
		i = list->next[i];
		count++;
	}
	if (list->next[i] == OOB)
	{
		if (i == list->head)
			list->head = OOB;
		if (list->prev[i] != OOB)
			list->next[list->prev[i]] = OOB;
		list->prev[i] = OOB;
	}
	else
	{
		if (i == list->head)
		{
			list->head = list->next[list->head];
			list->prev[list->head] = OOB, list->next[i] = OOB;
			return (i);
		}
		if (prev != OOB)
			list->next[prev] = list->next[i];
		if (list->next[i] != OOB)
			list->prev[list->next[i]] = list->prev[i];
		list->next[i] = OOB;
		list->prev[i] = OOB;
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
			list->free = OOB;
		if (list->prev[i] != OOB)
			list->next[list->prev[i]] = OOB;
		list->prev[i] = OOB;
	}
	else
	{
		if (i == list->free)
		{
			list->free = list->next[list->free];
			list->prev[list->free] = OOB, list->next[i] = OOB;
			return (i);
		}
		if (prev != OOB)
			list->next[prev] = list->next[i];
		if (list->next[i] != OOB)
			list->prev[list->next[i]] = list->prev[i];
		list->next[i] = OOB;
		list->prev[i] = OOB;
	}
	return (i);
}
