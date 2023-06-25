#include "data-structures.h"
#include <time.h>
#include "stack.h"
#include "deque.h"
#include "linked-list-using-array.h"

int main(void)
{

	KENPHF_list *list = create_KENPHF(10);
	int i;

	// printf("the size of the kenphf list is :%d\n", KENPHF_size(list));
	i = KENPHF_insert(list, 0, 2);
	// printf("the status is :%d\n", i);
	i = KENPHF_insert(list, 1, 4);
	// printf("the status is :%d\n", i);
	i = KENPHF_insert(list, -1, 99);
	// printf("the status is :%d\n", i);
	// i = KENPHF_insert(list, 3, 100);
	// printf("the status is :%d\n", i);
	// print_KENPHF_list(list);
	print_KENPHF_list_virtual(list);

	return (0);
}
