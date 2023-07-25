#include "deck.h"
#include "utils/utils-1000-sort_deck.c"


/**
 * convert_card - a function that converts
 * a card string into its integer representation
 * @name: the string name of the card
 * Return: int
 **/
int convert_card(char *name)
{
	int value;

	if (!is_letter(name[0]) && !is_letter(name[1]))
	{
		if ((is_digit(name[0]) && is_digit(name[1])) ||
			(is_digit(name[0]) && !name[1]))
		{
			if (!name[1])
				return (name[0] - 48);
			return (((name[0] - 48) * 10) + name[1] - 48);
		}
		return (-1);
	}

	value =  name[0] + name[1];

	switch (value)
	{
	case 164:
		return (1);
	case 171:
		return (11);
	case 198:
		return (12);
	case 180:
		return (13);
	}

	return (-1);
}

/**
 * insertion_sort_deck_by_types - a function that sorts a doubly-linked
 * list using insertion sort
 * @list: the address of the doubly-linked list
 * Return: void
 **/
void insertion_sort_deck_by_types(deck_node_t **list)
{
	deck_node_t *prev, *curr, *curr_tmp, *prev_tmp, *pos_head,
	*tmp;

	if (!(*list) || !(*list)->next)
		return;

	for (curr = (*list)->next; curr; curr = curr->next)
	{
		prev = curr->prev;

		while (prev && prev->card && prev->card->kind > curr->card->kind)
		{
			prev_tmp = prev, curr_tmp = prev->next;
			prev_tmp->next = curr_tmp->next;
			curr_tmp->next = prev_tmp;
			if (prev_tmp->prev)
				prev_tmp->prev->next = curr_tmp;
			if (prev_tmp->next)
				prev_tmp->next->prev = prev_tmp;
			curr_tmp->prev = prev_tmp->prev;
			prev = prev_tmp->prev;
			prev_tmp->prev = curr_tmp;
			pos_head = prev_tmp;
			while (pos_head)
				tmp = pos_head, pos_head = pos_head->prev;
		}
	}
	*list = tmp;
}


/**
 * insertion_sort_deck_by_cards - a function that sorts a doubly-linked
 * list using insertion sort
 * @list: the address of the doubly-linked list
 * Return: void
 **/
void insertion_sort_deck_by_cards(deck_node_t **list)
{
	deck_node_t *prev, *curr, *curr_tmp, *prev_tmp, *pos_head,
	*tmp;

	if (!(*list) || !(*list)->next)
		return;

	for (curr = (*list)->next; curr; curr = curr->next)
	{
		prev = curr->prev;

		while (prev && prev->card && curr->card &&
			convert_card((char *)prev->card->value) >
			convert_card((char *)curr->card->value))
		{
			prev_tmp = prev, curr_tmp = prev->next;
			prev_tmp->next = curr_tmp->next;
			curr_tmp->next = prev_tmp;
			if (prev_tmp->prev)
				prev_tmp->prev->next = curr_tmp;
			if (prev_tmp->next)
				prev_tmp->next->prev = prev_tmp;
			curr_tmp->prev = prev_tmp->prev;
			prev = prev_tmp->prev;
			prev_tmp->prev = curr_tmp;
			pos_head = prev_tmp;
			while (pos_head)
				tmp = pos_head, pos_head = pos_head->prev;
		}
	}
	*list = tmp;
}

/**
 * sort_deck - a function that sorts a deck of cards
 * @deck: the deck of cards
 * Return: void
 * Description - i know it's not effecient
 * there are better ways to further improve the running time
 **/
void sort_deck(deck_node_t **deck)
{
	/*
	 * qsort(ace, king, nmamb, 0);
	 **/
	insertion_sort_deck_by_cards(deck);
	insertion_sort_deck_by_types(deck);
}
