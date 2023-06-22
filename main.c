#include "data-structures.h"
#include <time.h>
#include "stack.h"
#include "deque.h"

int main(void)
{
	// obj_impl_t *d_list = init_list(20);
	int valid_index, random;
	stack_t *stack = create_stack(10);
	deque_t *deque = create_deque(10);


	// valid_index = allocate_obj(&d_list);
	// printf("valid index is :%d\n", valid_index);
	// list_insert(&d_list, valid_index, 9);
	// valid_index = allocate_obj(&d_list);
	// printf("valid index is :%d\n", valid_index);
	// list_insert(&d_list, valid_index, 12);
	// print_list(&d_list);

	// srand(time(0));
	// random = rand() % 20;
	// printf("%d\n", random);
	// random = rand() % 20;
	// printf("%d\n", random);
	// random = rand() % 20;
	// printf("%d\n", random);
	//
	// push(&stack, 2); push(&stack, 4);
	// push(&stack, 8); push(&stack, 8);
	// push(&stack, 0); push(&stack, 3);
	// push(&stack, 5); push(&stack, 7);
	// push(&stack, 20); push(&stack, 200);
	// push(&stack, 200); push(&stack, 40);
	// push(&stack, 42); push(&stack, 3);
	// push(&stack, 5); push(&stack, 7);
	// push(&stack, 20); push(&stack, 200);
	// push(&stack, 200); push(&stack, 40);
	// push(&stack, 42); print_stack(stack);
	
	enqueue_head(&deque, 12);
	enqueue_head(&deque, 80);
	// enqueue_head(&deque, 15);
	// enqueue_tail(&deque, 4);
	// enqueue_tail(&deque, 0);
	// enqueue_tail(&deque, 3);
	// enqueue_tail(&deque, 2);
	// enqueue_tail(&deque, 11);
	// enqueue_tail(&deque, 1024);
	// enqueue_tail(&deque, 0);
	// enqueue_tail(&deque, 3);
	// enqueue_tail(&deque, 2);
	// enqueue_tail(&deque, 11);
	// enqueue_tail(&deque, 1024);
	// enqueue_tail(&deque, 11);
	// enqueue_tail(&deque, 1024);
	// enqueue_tail(&deque, 2);
	// enqueue_head(&deque, 100);
	random = dequeue_head(deque);
	random = dequeue_head(deque);
	printf("random is :%d\n", random);

	print_deque(deque);
	
	free_stack(stack);
	free_deque(&deque);

	return (0);
}
