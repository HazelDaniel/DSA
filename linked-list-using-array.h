#ifndef ___LINKED_LIST_USING_ARRAY_
#define ___LINKED_LIST_USING_ARRAY_
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define OOB (-1)

typedef struct {
	int head;
	int free;
	int size;
	int *key;
	int *next;
	int *prev;
} KENPHF_list;

int KENPHF_full(KENPHF_list *list);
int KENPHF_empty(KENPHF_list *list);
int pop_KENPHF_list(KENPHF_list *list, int index);
int pop_KENPHF_heap(KENPHF_list *list, int index);
int push_KENPHF_heap(KENPHF_list *list, int index);
int push_KENPHF_list(KENPHF_list *list, int index);
KENPHF_list *create_KENPHF(unsigned int size);
KENPHF_list *extend_KENPHF(KENPHF_list *list, unsigned int size);
unsigned int KENPHF_size(KENPHF_list *list);
int free_KENPHF(KENPHF_list *list, int index);
int alloc_KENPHF(KENPHF_list *list, int index);
int KENPHF_insert(KENPHF_list **list, int index, int value);
int KENPHF_delete(KENPHF_list **list, int index);
void print_KENPHF_list(KENPHF_list *list);
void print_KENPHF_list_virtual(KENPHF_list *list);
void free_KENPHF_list(KENPHF_list **list_ptr);
#endif/*___LINKED_LIST_USING_ARRAY_*/
