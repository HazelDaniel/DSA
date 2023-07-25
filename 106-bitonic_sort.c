#include "sort.h"
#include <stdio.h>

/**
 * swap - a sub-routine that changes two values in
 * ascending or descending order
 * @arr: array
 * @ind1: index a
 * @ind2: index b
 * @order: 1: ascending order, 0 descending order
 * Return: void
 **/
void swap(int *arr, int ind1, int ind2, int order)
{
	int temp, cond = arr[ind1] > arr[ind2];

	if (order == cond)
	{
		temp = arr[ind1], arr[ind1] = arr[ind2];
		arr[ind2] = temp;
	}
}
/**
 * resolve_order - a procedure that recursively preserves
 * the properies of sub-sequences of a bitonic sequence
 * in both orders
 * @arr: array
 * @low: first element
 * @el_num: elements number
 * @order: 1: ascending order, 0 descending order
 * Return: void
 **/
void resolve_order(int *arr, int low, int el_num, int order)
{
	int mid, i;

	if (el_num > 1)
	{
		mid = el_num / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		resolve_order(arr, low, mid, order);
		resolve_order(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @el_num: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array length
 * Return: void
 **/
void bitonicsort(int *arr, int low, int el_num, int order, int size)
{
	int mid;

	if (el_num > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", el_num, size);
			print_array(arr + low, el_num);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", el_num, size);
			print_array(arr + low, el_num);
		}
		mid = el_num / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		resolve_order(arr, low, el_num, order);
		if (order < 1)
		{
			printf("Result [%i/%i] (DOWN):\n", el_num, size);
			print_array(arr + low, el_num);
		}
		else
		{
			printf("Result [%i/%i] (UP):\n", el_num, size);
			print_array(arr + low, el_num);
		}
	}
}
/**
 * bitonic_sort - sets up the instance of the problem
 * for the bitonic sort algorithm
 * @array: array
 * @size: array length - N
 * Return: void
 **/
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
