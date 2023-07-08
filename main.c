#include "data-structures.h"
#include <time.h>
#include "stack.h"
#include "deque.h"
#include "linked-list-using-array.h"

/*
 * */
int main(void)
{

	KENPHF_list *list = create_KENPHF(10);
	int i;

	puts("===============>");
	i = KENPHF_insert(&list, 1, 101);
	i = KENPHF_insert(&list, 0, 111);
	i = KENPHF_insert(&list, 10, 102);
	i = KENPHF_insert(&list, 100, 2);
	i = KENPHF_insert(&list, 10, 7);
	i = KENPHF_insert(&list, 10, 33);
	i = KENPHF_insert(&list, 5, 13);
	i = KENPHF_insert(&list, 5, 13);
	i = KENPHF_insert(&list, -5, 13);
	i = KENPHF_insert(&list, 10, 130);
	i = KENPHF_delete(&list, 1);
	i = KENPHF_insert(&list, 1, 404);
	i = KENPHF_insert(&list, 10, 130);
	i = KENPHF_insert(&list, 1, 194);
	i = KENPHF_insert(&list, 0, 777);
	i = KENPHF_insert(&list, 0, 660);
	i = KENPHF_insert(&list, 0, 668);
	i = KENPHF_insert(&list, 0, 222);
	i = KENPHF_insert(&list, 0, 225);
	i = KENPHF_insert(&list, 0, 707);
	puts("==============>");
	print_KENPHF_list(list);
	printf("the size is :%d\n", KENPHF_size(list));
	free_KENPHF_list(&list);

	return (0);
}
