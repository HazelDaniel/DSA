#include "sort.h"

/**
 * front_swap - swaps adjacent nodes in
 * forward direction
 * @prev: previous node
 * @curr: current node
 */
void front_swap(listint_t **prev, listint_t **curr)
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

	*curr = fptr;
	*prev = sptr;
}

/**
 * back_swap - swaps adjacent nodes in
 * forward direction
 * @prev: previous node
 * @curr: current node
 */
void back_swap(listint_t **prev, listint_t **curr)
{
	listint_t *fptr = *prev, *sptr = *curr, *btemp = NULL, *atemp = NULL;

	btemp = sptr->prev;
	if (btemp)
		btemp->next = fptr;
	fptr->prev = btemp;
	atemp = fptr->next;
	if (atemp)
		atemp->prev = sptr;
	sptr->next = atemp;

	fptr->next = sptr;
	sptr->prev = fptr;

	*curr = fptr;
	*prev = sptr;
}

/**
 * cocktail_sort_list - a function that sorts a doubly-linked
 * list using cocktail sort
 * @list: the address of the doubly-linked list
 * Return: void
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr, *aptr, *bptr, *cptr, *dptr;
	size_t swapped = 0;

	if (!list || !*list || !(*list)->next)
		return;
	for (ptr = *list; ptr; ptr = ptr->next)
	{
		aptr = *list, bptr = aptr->next;
		while (aptr->next)
		{
			if (aptr->n > bptr->n)
			{
				front_swap(&aptr, &bptr);
				if (!aptr->prev)
					*list = aptr;
				swapped = 1;
				print_list(*list);
			}
			aptr = aptr->next;
			bptr = bptr->next;
		}
		if (!swapped)
			break;
		swapped = 0, cptr = aptr, dptr = cptr->prev;
		while (dptr)
		{
			if (cptr->n < dptr->n)
			{
				back_swap(&cptr, &dptr);
				if (!dptr->prev)
					*list = dptr;
				swapped = 1;
				print_list(*list);
			}
			cptr = cptr->prev, dptr = dptr->prev;
		}
		if (!swapped)
			break;
	}
}
