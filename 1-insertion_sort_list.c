#include "sort.h"

/**
 * swap - a function that swaps the content
 * of the addresses of two objects
 * @prev: te address of the left object
 * @curr: the address of the right object
 * Return: void
 **/
void swap(listint_t **prev, listint_t **curr)
{
	listint_t *fptr = *prev, *sptr = *curr, *temp = NULL;

	temp = fptr->prev;
	if (temp)
		temp->next = sptr;
	sptr->prev = temp;

	fptr->next = sptr->next;
	if (sptr->next)
		sptr->next->prev = fptr;

	sptr->next = fptr;
	fptr->prev = sptr;

	*prev = sptr;
	*curr = fptr;
}

/**
 * insertion_sort_list - a function that sorts a doubly-linked
 * list using insertion sort
 * @list: the address of the doubly-linked list
 * Return: void
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node = NULL, *prev_node = NULL, *ptr = NULL;

	prev_node = list ? *list : NULL;

	if (!prev_node || !prev_node->next)
		return;

	curr_node = prev_node->next;
	while (curr_node)
	{
		ptr = curr_node;
		while (prev_node)
		{
			if (prev_node->n > curr_node->n)
			{
				swap(&prev_node, &curr_node);
				if (!prev_node->prev)
					*list = prev_node;
				print_list(*list);
			}
			else
				break;
			prev_node = prev_node->prev;
			curr_node = curr_node->prev;
		}
		prev_node = ptr;
		curr_node = prev_node->next;
	}
}
