#include "stack.h"

stack_t *create_stack(unsigned int size)
{
	stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t));

	if (!new_stack)
		return (0);

	new_stack->stack = malloc((size) * sizeof(int));
	if (!new_stack->stack)
	{
		free(new_stack);
		return (0);
	}
	new_stack->top = -1;
	new_stack->size = size;

	return (new_stack);
}

int stack_full(stack_t *s)
{
	if (!s)
		return (1);
	if (s->top == s->size - 1)
		return (1);
	return (0);
}

int stack_empty(stack_t *s)
{
	if (!s)
		return (1);
	if (s->top == -1)
		return (1);
	return (0);
}

void push(stack_t *s, int x)
{
	if (!stack_full(s))
		s->stack[++(s->top)] = x;
	else
		/*
		 we call it stack underflow
		 */
		;
}

int pop(stack_t *s)
{
	int x;

	if (!stack_empty(s))
	{
		x = s->stack[s->top--];
		return (x);
	}
	/*
	 else we call it stack underflow
	*/

	return (INT_MIN);
}

void free_stack(stack_t *s)
{
	if (s)
		free(s->stack);
	free(s);
	s = NULL;
}

void print_stack(stack_t *s)
{
	stack_t *copy = stack_cpy(s);
	int x = INT_MIN;

	if (stack_empty(s))
	{
		puts("(nil)");
		return;
	}
	for (x = pop(copy); x != INT_MIN; x = pop(copy))
		printf("=>%d\n", x);
	free_stack(copy);
}

stack_t *stack_cpy(stack_t *s)
{
	stack_t *cpy_stack = (stack_t *)malloc(sizeof(stack_t));
	int i;

	if (!cpy_stack || !s)
	{
		free(cpy_stack);
		return (0);
	}

	cpy_stack->stack = malloc((s->size) * sizeof(int));
	if (!cpy_stack->stack)
	{
		free(cpy_stack);
		return (0);
	}
	for (i = 0; i < s->size; i++)
	{
		cpy_stack->stack[i] = s->stack[i];
	}
	cpy_stack->top = s->top;
	cpy_stack->size = s->size;

	return (cpy_stack);
}
