#include "sort.h"
#include "utils.c"
#include "utils/utils-radix_sort.c"

/**
 * insert_to_rbin - a function that inserts a card
 * into an array of radix bins
 * @r_bin: the array of bins
 * @index: the spot to insert to
 * @value: the value of the card
 * Return: void
 **/
void insert_to_rbin(rad_bin_t *r_bin, int index, int value)
{
	bin_list_t *new_card, *current;

	new_card = (bin_list_t *)malloc(sizeof(bin_list_t));
	if (!new_card || !r_bin)
		return;
	new_card->value = value;
	new_card->next = NULL;

	if (r_bin->bins[index])
	{
		current = r_bin->bins[index];
		while (current && current->next)
			current = current->next;
		current->next = new_card;
	}
	else
	{
		r_bin->bins[index] = new_card;
	}
}


/**
 * extract_rad_bin - a function that extracts values
 * from an array of radix bins and creates an array of values
 * from it
 * @r_bin: the array of radix bins
 * Return: int *
 **/
int *extract_rad_bin(rad_bin_t *r_bin)
{
	int *res = NULL, i = 0, j = 0;
	bin_list_t *current;

	j = 0;
	if (!r_bin)
		return (res);
	res = malloc(r_bin->size * sizeof(int));
	if (!res)
		return (res);
	for (; i < r_bin->size; i++)
	{
		if (r_bin->bins[i])
		{
			current = r_bin->bins[i];
			while (current)
			{
				res[j++] = current->value;
				current = current->next;
			}
		}
	}
	return (res);
}

/**
 * radix_sort - a function that sorts an input array based
 * on radix sort algorithm which relies on a stable sort
 * to provide correct output
 * @array: the input array/ instance of a problem
 * @size: the size of the array - N
 * Return: void
 **/
void radix_sort(int *array, size_t size)
{
	int highest = find_max(array, size), dig_len,
	dig_cut = 1, i, j, base = 10, *tmp_arr;
	rad_bin_t *bins;

	if (size <= 1 || highest == INT_MIN)
		return;
	dig_len = num_digits(highest);
	while (dig_len)
	{
		bins = create_rad_bin(size);
		for (i = 0; (size_t)i < size; i++)
			insert_to_rbin(bins, (array[i] / dig_cut) % base, array[i]);
		if (bins)
			tmp_arr = extract_rad_bin(bins);
		else
			break;
		for (j = 0; (size_t)j < size; j++)
			array[j] = tmp_arr[j];
		print_array(array, size);
		dig_cut *= base, dig_len--;
		free(tmp_arr), free_rad_bin(&bins);
	}
}
