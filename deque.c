#include "deque.h"

/**
 * create_deque - a function that creates
 * and initializes a deque
 * @size: the initial size provided
 * Return: deque_t *
 **/
deque_t *create_deque(unsigned int size)
{
	deque_t *new_deque = (deque_t *)malloc(sizeof(deque_t));

	if (!new_deque)
		return (0);

	new_deque->deque = malloc((size) * sizeof(int));
	new_deque->top = new_deque->tail = new_deque->head = 0;
	if (!new_deque->deque)
	{
		free(new_deque);
		return (0);
	}
	new_deque->size = size;

	return (new_deque);
}

/**
 * deque_full - a function that checks if a deque is full
 * @d: parameter of type deque_t *
 * Return: int
 **/
int deque_full(deque_t *d)
{
	if (!d)
		return (1);
	if ((d->tail % d->size) + 1 == (d->head % d->size))
		return (1);
	return (0);
}

/**
 * deque_empty - a function that checks if a deque is empty
 * @d: parameter of type deque_t *
 * Return: int
 **/
int deque_empty(deque_t *d)
{
	if (!d)
		return (1);
	if ((d->head % d->size) == (d->tail % d->size))
		return (1);
	return (0);
}

/**
 * relocate_deque - a function that re-allocates a deque
 * to an identical deque but with a larger size
 * @old_deque_ptr: parameter of type deque_t **
 * @size: the size difference
 * Return: deque_t *
 **/
deque_t *relocate_deque(deque_t **old_deque_ptr, unsigned int size)
{
	deque_t *new_deque = (deque_t *)malloc(sizeof(deque_t)),
	*old_deque = *old_deque_ptr;
	int i = 0, j = 0;

	if (!old_deque || !new_deque)
		return (NULL);

	if (!size || size < 0)
		return (old_deque);

	new_deque->deque = malloc((old_deque->size + size) * sizeof(int));
	new_deque->size = old_deque->size + size, new_deque->head = 0;

	if (!new_deque->deque)
	{
		free(new_deque);
		free_deque(old_deque_ptr);
		return (NULL);
	}
	for (j = 0, i = old_deque->head; i != old_deque->tail
	; i = (i + 1) % old_deque->size)
	{
		new_deque->deque[j++] = old_deque->deque[i];
	}
	new_deque->top = new_deque->tail = j;
	free_deque(old_deque_ptr);

	return (new_deque);
}

/**
 * free_deque - a function that frees up a deque
 * @d: parameter of type deque_t *
 * Return: void
 **/
void free_deque(deque_t **d)
{
	if (*d)
		free((*d)->deque);
	free(*d);
	*d = NULL;
}

/**
 * print_deque - a function that prints the contents of a
 * deque
 * @d: parameter of type deque_t *
 * Return: void
 **/
void print_deque(deque_t *d)
{
	int i, x;

	if (deque_empty(d))
		return;
	x = d->tail;
	x = (((x - 1) % d->size) + d->size) % d->size;
	for (i = x; i != d->head; i = (((i - 1) % d->size) + d->size) % d->size)
	{
		printf("%d\n", d->deque[i]);
	}
	printf("%d\n", d->deque[d->head]);
}

/**
 * dequeue_head - a function that dequeues
 * a deque from the head position
 * @d: parameter of type deque_t *
 * Return: int
 **/
int dequeue_head(deque_t *d)
{
	int x;

	if (deque_empty(d))
	{
		puts("deque underflow");
		exit(EXIT_FAILURE);
	}
	x = d->deque[d->head % d->size];
	d->head = (d->head + 1) % d->size;

	return (x);
}

/**
 * enqueue_head - a function that enqueues
 * a deque from the head position
 * @d: parameter of type deque_t *
 * @x: the value to be enqueued
 * Return: void
 **/
void enqueue_head(deque_t **d, int x)
{
	deque_t *dq = *d;

	if (deque_full(dq))
		dq = *d = relocate_deque(d, 100);

	if (!dq)
	{
		puts("malloc failed");
		exit(99);
	}

	if (deque_empty(dq))
	{
		dq->deque[dq->head] = x, dq->tail = (dq->tail + 1) % dq->size;
	}
	else
	{
		dq->head = (((dq->head - 1) % dq->size) + dq->size) % dq->size;
		dq->deque[dq->head] = x;
	}
}

/**
 * dequeue_tail - a function that dequeues
 * a deque from the tail position
 * @d: parameter of type deque_t *
 * Return: int
 **/
int dequeue_tail(deque_t *d)
{

	if (deque_empty(d))
	{
		puts("deque underflow");
		exit(EXIT_FAILURE);
	}
	d->tail--;
	d->tail = (((d->tail % d->size) + d->size) % d->size);

	return (d->deque[d->tail]);
}


/**
 * enqueue_tail - a function that enqueues
 * a deque from the tail position
 * @d: parameter of type deque_t *
 * @x: the value to be enqueued
 * Return: void
 **/
void enqueue_tail(deque_t **d, int x)
{
	deque_t *dq = *d;
	int i;

	if (deque_full(dq))
		dq = *d = relocate_deque(d, 100);

	if (!dq)
	{
		puts("malloc failed");
		exit(99);
	}

	i = dq->tail;
	dq->tail = (dq->tail + 1) % dq->size;
	dq->deque[i] = x;
}

/**
 * deque_len - a function that computes the
 * active length of a deque
 * @d: parameter of type deque_t *
 * Return: int
 **/
int deque_len(deque_t *d)
{
	int x, i, count = 0;

	if (deque_empty(d))
		return (count);
	x = d->tail;
	x = (((x - 1) % d->size) + d->size) % d->size;
	for (i = x; i != d->head; i = (((i - 1) % d->size) + d->size) % d->size)
		count++;
	count++;

	return (count);
}
