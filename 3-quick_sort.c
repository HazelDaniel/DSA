#include "sort.h"

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
 * divide - a function that partitions an array
 * based on the lomuto partition scheme
 * @array: the input array to be sorted
 * @idx: begin
 * @size: end
 * @end: the size of the input array
 * Return: partition index
 **/
int divide(int **array, int idx, int size, int end)
{
	int left = idx - 1, right, *a = *array, pivot = a[size];

	for (right = idx; right < size; right++)
	{
		if (a[right] <= pivot)
		{
			left++;
			swap(&a[left], &a[right]);
			if (left != right)
				print_array(*array, end);
		}

	}
	swap(&a[left + 1], &a[size]);
	if (left + 1 != size)
		print_array(*array, end);
	return (left + 1);
}

/**
 * lomuto - a function that partitions an array
 * based on the lomuto partition scheme
 * @array: the input array to be sorted
 * @idx: begin
 * @size: end
 * @end: the size of the input array
 **/
void lomuto(int **array, int idx, int size, int end)
{
	int q;

	if (idx < size)
	{
		q = divide(array, idx, size, end);
		lomuto(array, idx, q - 1, end);
		lomuto(array, q + 1, size, end);
	}
}

/**
 * quick_sort - a function that sorts an array
 * based on the quick sort algorithm
 * @array: the input array to be sorted
 * @size: the size of the input array
 * Return: void
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto(&array, 0, (int)size - 1, (int)size);
}
