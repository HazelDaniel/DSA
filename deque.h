#ifndef ___DEQUE_
#define ___DEQUE_
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

#define OOB (-1)

typedef struct {
	int top;
	int tail;
	int head;
	int *deque;
	int size;
} deque_t;

deque_t *create_deque(unsigned int size);
int deque_full(deque_t *d);
int deque_empty(deque_t *d);
deque_t *relocate_deque(deque_t **old_deque_ptr, unsigned int size);
void free_deque(deque_t **d);
void print_deque(deque_t *d);
int dequeue_head(deque_t *d);
void enqueue_head(deque_t **d, int x);
int dequeue_tail(deque_t *d);
void enqueue_tail(deque_t **d, int x);
int deque_len(deque_t *d);
#endif/*___DEQUE_*/
