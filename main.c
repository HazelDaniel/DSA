#include "data-structures.h"
#include <time.h>
#include "stack.h"
#include "deque.h"
#include "linked-list-using-array.h"

/*
 * edge case: when delete is called, the
 * next pointer of the released index isn't
 * freed
 * edge case: getting seg fault in extend_kenphf
 * index after i
 * */
int main(void)
{

	KENPHF_list *list = create_KENPHF(10);
	int i;

	puts("===============>");
	i = KENPHF_insert(list, 1, 101);
	i = KENPHF_insert(list, 0, 111);
	i = KENPHF_insert(list, 10, 102);
	i = KENPHF_insert(list, 100, 2);
	i = KENPHF_insert(list, 10, 7);
	i = KENPHF_insert(list, 10, 33);
	i = KENPHF_insert(list, 5, 13);
	i = KENPHF_insert(list, 5, 13);
	i = KENPHF_insert(list, -5, 13);
	i = KENPHF_insert(list, 10, 130);
	i = KENPHF_delete(list, 1);
	// i = KENPHF_insert(list, i, 404);
	print_KENPHF_list_virtual(list);
	printf("the size is :%d\n", KENPHF_size(list));

	return (0);
}
