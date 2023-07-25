#include "sort.h"

/**
 * bubble_sort - a function that sorts
 * an array using the bubble sort algorithm
 * @array: the input array
 * @size: the size of the input array
 * Return: void
 **/
void bubble_sort(int *array, size_t size)
{
	int i = 0, j = 0, tmp, swapped = 0;

	if (size <= 1)
		return;
	for (i = 0; (size_t)i < size; i++)
	{
		for (j = 0; (size_t)j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped) /* this is used to augment the best-case time complexity */
			break;
	}
}
