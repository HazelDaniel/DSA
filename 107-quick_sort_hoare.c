#include "sort.h"
#include "utils/utils-quick-sort.c"

/**
 * part_hoare - a function that partitions an array
 * based on the hoare partition scheme
 * @array: the input array
 * @low: the starting index
 * @high: the last index
 * Return: int
 **/
int part_hoare(int *array, int low, int high)
{
	int i = low, j = high + 1, pivot_index = low,
	tmp;
	static int count, size;

	if (!count)
		size = high + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < array[pivot_index]);

		do {
			j--;
		} while (array[j] > array[pivot_index]);

		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		else
		{
			tmp = array[pivot_index];
			array[pivot_index] = array[j];
			array[j] = tmp;
			print_array(array, size);
			break;
		}
	}
	count++;
	return (j);
}

/**
 * hoare_sort - a function that sorts an input array
 * using quick sort and hoare sort partitioning scheme
 * @array: the input array
 * @low: the lowest index
 * @high: the last index
 * Return: void
 **/
void hoare_sort(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = part_hoare(array, low, high);
		hoare_sort(array, low, pivot_index);
		hoare_sort(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort_hoare - a function that sorts
 * an input array using quick sort algorithm
 * and a hoare partitioning scheme
 * @array: an input array
 * @size: the size of the array - N
 * Return: void
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		hoare_sort(array, 0, size - 1);
}
