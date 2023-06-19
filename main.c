#include "data-structures.h"

int main(void)
{
	obj_impl_t *d_list = init_list(20);
	int valid_index;

	valid_index = allocate_obj(&d_list);
	printf("valid index is :%d\n", valid_index);
	list_insert(&d_list, valid_index, 9);
	valid_index = allocate_obj(&d_list);
	printf("valid index is :%d\n", valid_index);
	list_insert(&d_list, valid_index, 12);
	print_list(&d_list);

	return (0);
}
