#include "sort.h"
#include "utils/utils-mem_utils.c"


/**
 * print_sequence - a function that prints
 * and array as a sequence
 * @array: the input array
 * @size: the size of the array
 * Return: void
 **/
void print_sequence(int *array, int size)
{
	int i = 0;

	for (; i < size; i++)
	{
		if (i == 0)
			printf("%d", array[i]);
		else
			printf(", %d", array[i]);
	}
}

/**
 * merge - a sub-routine for the merge sort algorithm
 * responsible for the 'combine' part of
 * the divide and conquer
 * @array: the output array to be merged into
 * @low: the starting index
 * @mid: the middle index
 * @high: the last index
 * Return: int *
 **/
void merge(int *array, int low, int mid, int high)
{
	int *left, *right, i, j, k,

	n1 = mid - low + 1, n2 = high - mid;
	left = _calloc(n1, sizeof(int)), right = _calloc(n2, sizeof(int));
	for (i = 0; i < n1; i++)
		left[i] = array[low + i];
	puts("Merging..."), printf("[left]: "), print_sequence(left, n1);
	printf("\n");
	for (j = 0; j < n2; j++)
		right[j] = array[mid + j + 1];
	printf("[right]: "), print_sequence(right, n2);
	printf("\n");
	i = 0, j = 0, k = low;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < n1)
		array[k++] = left[i++];
	while (j < n2)
		array[k++] = right[j++];
	printf("[done]: "), print_sequence(array + low, k - low);
	printf("\n");
	_fr_ptr((void **)&right), _fr_ptr((void **)&left);
}

/**
 * m_sort - a function that uses the merge sort
 * algorithm to sort an input array
 * @array: the input array
 * @low: the starting index
 * @high: the last index
 * Return: int *
 **/
void m_sort(int *array, int low, int high)
{
	int mid, n1, n2;

	if (low < high)
	{
		mid = ((high + low) >> 1);
		n1 = mid - low + 1, n2 = high - mid;
		if (n1 > n2)
		{
			if (mid != low)
				mid = mid - 1;
			n1 = mid - low + 1, n2 = high - mid;
		}
		m_sort(array, low, mid);
		m_sort(array, mid + 1, high);
		merge(array, low, mid, high);
	}

}

/**
 * merge_sort - a function that uses the merge sort
 * algorithm to sort an input array - wrapper around
 * m_sort
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void merge_sort(int *array, size_t size)
{
	m_sort(array, 0, size - 1);
}
