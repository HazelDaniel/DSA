#include <stdio.h>
#include "sort.h"
#include <stdlib.h>


/**
 * swap - a function that swaps the contents of
 * the addresses of two objects
 * @a: the first object
 * @b: the second object
 * Return: void
 **/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * array_min - a function that finds the minimum
 * in an array
 * @array: the input array
 * @curr: the current index in the array
 * @size: the size of the array
 * Return: int
 **/
int array_min(int *array, int curr, int size)
{
	int i, pos = curr, min = array[curr];

	for (i = curr; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			pos = i;
		}
	}
	return (pos);
}

/**
 * selection_sort - a function that sorts an array
 * based on the selection sort algorithm
 * @array: the input array to be sorted
 * @size: the size of the input array
 * Return: void
 **/
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	int min_pos = 0;

	if (!array || size == 1)
		return;
	for (i = 0; i < size; i++)
	{
		min_pos = array_min(array, (int)i, (int)size);
		if (min_pos != (int)i)
		{
			swap(&(array[i]), &(array[min_pos]));
			print_array(array, size);
		}
	}

}
