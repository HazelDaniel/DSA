#ifndef __DSA_H_
#define __DSA_H_
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define OOB (-1)


typedef struct {
	int *next;
	int *key;
	int *prev;
} list_impl_t;

typedef struct {
	int free;
	int head;
	list_impl_t *storage;
} obj_impl_t;


obj_impl_t *init_list(unsigned int size);
obj_impl_t *create_list(unsigned int size);
void free_obj(obj_impl_t **head, int x);
void print_list(obj_impl_t **head);
int list_insert(obj_impl_t **head, int index, int value);
int allocate_obj(obj_impl_t **head);
obj_impl_t *init_list(unsigned int size);
void free_list(obj_impl_t **head);
#endif/*__DSA_H_*/
