#include "data-structures.h"
#include <time.h>
#include "stack.h"

int main(void)
{
	// obj_impl_t *d_list = init_list(20);
	int valid_index, random;
	stack_t *stack = create_stack(10);


	// valid_index = allocate_obj(&d_list);
	// printf("valid index is :%d\n", valid_index);
	// list_insert(&d_list, valid_index, 9);
	// valid_index = allocate_obj(&d_list);
	// printf("valid index is :%d\n", valid_index);
	// list_insert(&d_list, valid_index, 12);
	// print_list(&d_list);

	// srand(time(0));
	// random = rand() % 20;
	printf("%d\n", ((rand() % 10) + 10) % 10);
	printf("%d\n", ((rand() % 10) + 10) % 10);
	printf("%d\n", ((rand() % 10) + 10) % 10);
	printf("%d\n", ((rand() % 10) + 10) % 10);
	// random = rand() % 20;
	// printf("%d\n", random);
	// random = rand() % 20;
	// printf("%d\n", random);

	return (0);
}
