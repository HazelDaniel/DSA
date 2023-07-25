#include "sort.h"
#include "utils/utils-heap_sort.c"


/**
 * max_heapify - a procedure that uses the "sift-down"
 * algotihm to 'sink' a node in a max-heap to it's
 * rightful position
 * @array: input array of size  N
 * @i: the array index of the current item in the heap
 * @heap_size: the modifiable size of the portion of the array
 * representing the heap
 * @size: the size of the original array
 * Return: void
 **/
void max_heapify(int *array, int i, size_t *heap_size, size_t size)
{
	int largest, l, r, tmp;

	l = left_child(i), r = right_child(i);

	if ((size_t)l < (*heap_size) && array[l] > array[i])
		largest = l;
	else
		largest = i;
	if ((size_t)r < (*heap_size) && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, size);
		max_heapify(array, largest, heap_size, size);
	}
}

/**
 * build_max_heap - a function that 'enforces'
 * an array to keep the structural integrity of a heap
 * @array: the input array of size N
 * @heap_size: the size of the portion of the array
 * representing the heap
 * @size: the size of the original array
 * Return: void
 **/
void build_max_heap(int *array, size_t *heap_size, size_t size)
{
	int j = 0, leaf_start;

	leaf_start = *heap_size % 2 ? (*heap_size / 2) + 1 : *heap_size / 2;
	for (j = leaf_start; j >= 0; j--)
		max_heapify(array, j, heap_size, size);
}

/**
 * heap_sort - a routine that uses the heap sorts an input array
 * based on the heap sort algorithm
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void heap_sort(int *array, size_t size)
{
	int i, tmp;
	size_t heap_size = size, *heap_size_addr = &heap_size;

	if (size <= 1)
		return;
	build_max_heap(array, heap_size_addr, size);
	for (i = size - 1; i > 0; i--)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		(*heap_size_addr)--;
		print_array(array, size);
		max_heapify(array, 0, heap_size_addr, size);
	}
}
