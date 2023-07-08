#ifndef ___AVL_TREES_
#define ___AVL_TREES_
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#define INORDER (0)
#define PREORDER (1)
#define POSTORDER (2)

typedef struct Avl_node {
	unsigned int height;
	struct Avl_node *left;
	struct Avl_node *right;
	unsigned long int data; // not yet augmented for hash maps for duplicates
} avl_node_t;

avl_node_t *create_avl_node(unsigned long int data);
unsigned int get_avl_height(avl_node_t *root);
unsigned int balance_factor(avl_node_t *root);
avl_node_t *rotate_left(avl_node_t **root);
avl_node_t *rotate_right(avl_node_t **root);
void insert_avl_node(avl_node_t **root, unsigned long int data);
avl_node_t *delete_avl_node(avl_node_t **root, unsigned long int data);
void print_avl_tree(avl_node_t *root, int mode);
#endif/*___AVL_TREES_*/
