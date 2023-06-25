#include "../data-structures.h"

/**
 * _memset - a function that sets
 * contigious memory blocks to a value
 * @ptr: the address of the first element in the
 * memory block
 * @val: the value
 * @len: the length of the assignment
 * Return: void
 * description: checked
 **/
void _memset(void *ptr, int val, size_t len)
{
	size_t i;
	char *ptr_mut = (char *)ptr;

	for (i = 0; i < len; i++)
		ptr_mut[i] = val;
}
