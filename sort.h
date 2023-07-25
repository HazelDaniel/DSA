#ifndef ___SORT_
#define ___SORT_
#include <stdlib.h>
#include <stdio.h>
/* TYPEDEFS AND STRUCTURES */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
/**
 * struct bin_list - a bin that holds different cards
 * each with digits representable in base(k + 1)
 *
 * @next: the pointer to the first card in the bin
 * @value: node value
 **/
typedef struct bin_list
{
	struct bin_list *next;
	int value;
} bin_list_t;
/**
 * struct radix_bin - a structure that holds
 * the 'bins' in a radix sort
 * which contains an array that holds the range [0..k]
 * where each item in the original array holds digits with
 * values in the interval [0,k+1)
 *
 * @bins: the dynamic list of 'bins' that holds bins
 * positioned side-by-side in the range [0..k]
 * @size: k + 1
 **/
typedef struct radix_bin
{
	bin_list_t **bins;
	int size;
} rad_bin_t;


/* CORE ALGORITHMS */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void insertion_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);


/* SUB-ROUTINES/PROCEDURES FOR CORE ALGORITHMS */

void quick_sort_lomuto(int *array, int low, int high);
void sort_hoare(int *array, int low, int high);
void quick_sort_hoare(int *array, size_t size);
void max_heapify(int *array, int i, size_t *heap_size, size_t size);
void build_max_heap(int *array, size_t *heap_size, size_t size);
int parent(int i);
int left_child(int i);
int right_child(int i);
rad_bin_t *create_rad_bin(int size);
void reset_rad_bin(rad_bin_t *r_bin);
void free_rad_bin(rad_bin_t **r_bin);
void insert_to_rbin(rad_bin_t *r_bin, int index, int value);
int *extract_rad_bin(rad_bin_t *r_bin);
void merge(int *array, int low, int mid, int high);


/* UTILS */

unsigned int power(unsigned int x, unsigned int y);
int find_max(int *array, size_t size);
int num_digits(unsigned int x);
#endif/*___SORT_*/
