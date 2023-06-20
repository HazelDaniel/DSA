#ifndef ___STACK_
#define ___STACK_
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct {
	int top;
	int *stack;
	int size;
} stack_t;

stack_t *create_stack(unsigned int size);
int stack_full(stack_t *s);
int stack_empty(stack_t *s);
void push(stack_t *s, int x);
int pop(stack_t *s);
void free_stack(stack_t *s);
void print_stack(stack_t *s);
stack_t *stack_cpy(stack_t *s);

#endif/*___STACK_*/
