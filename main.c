#include "data-structures.h"
#include <time.h>
#include "stack.h"
#include "deque.h"
#include "linked-list-using-array.h"

int main(void)
{

	KENPHF_list *list = create_KENPHF(10);
	int i;

	i = KENPHF_insert(list, 1, 89);
	i = KENPHF_insert(list, 0, 89);
	print_KENPHF_list_virtual(list);
	print_KENPHF_list(list);

	return (0);


}
