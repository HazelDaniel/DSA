#include "sort.h"
#include "utils.c"

/**
 * alloc_init - a function that does
 * the work of malloc and initializes all it's element to zero
 * @nmemb: the number of elements to fill
 * @size: the size of each element in memory
 * Return: void *
 **/
void *alloc_init(int nmemb, int size)
{
	int i;
	void *res;
	char *tmp_res;

	res = malloc(nmemb * size);
	if (!res)
		return (0);

	tmp_res = res;

	for (i = 0; i < size; i++)
		tmp_res[i] = 0;

	return (res);
}

/**
 * counting_sort - a function that sorts an input array
 * using a non-comparation sorting algotithm called
 * counting sort
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void counting_sort(int *array, size_t size)
{
	int i = 0, j = 0, high, *result = NULL, *counts = NULL;

	high = find_max(array, size);
	/*
	 * below is  to make sure that the property of counting sort
	 * algorithm holds true prior to the iteration
	 * - the INT_MIN is returned if a negative value is found
	 *   in the array
	 */
	if (high == INT_MIN || size <= 1)
		return;
	counts = alloc_init(high + 1, sizeof(int));
	result = malloc(size * sizeof(int));

	for (i = 0; (size_t)i < size; i++)
		counts[array[i]] += 1;

	for (j = 0; j <= high; j++)
	{
		if (j)
			counts[j] += counts[j - 1], printf(", %d", counts[j]);
		else
			printf("%d", counts[j]);
	}
	if (j)
		printf("\n");

	for (j = 0; (size_t)j < size; j++)
	{
		result[counts[array[j]] - 1] = array[j];
		counts[array[j]] -= 1;
	}

	for (i = 0; (size_t)i < size; i++)
		array[i] = result[i];
}
