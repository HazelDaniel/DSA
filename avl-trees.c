#include "avl-trees.h"


/**
 * create_avl_node - a function that creates a new avl node
 * @data: the value of the new node
 * Return: avl_node_t *
 **/
avl_node_t *create_avl_node(unsigned long int data)
{
	avl_node_t * new_node;

	new_node = (avl_node_t *)malloc(sizeof(avl_node_t));
	if (!new_node)
		return (NULL);
	new_node->left = NULL, new_node->right = NULL;
	new_node->height = 0, new_node->data = data;

	return (new_node);
}

/**
 * get_avl_height - a function that returns the height
 * of an avl node
 * @root: the root node of the current sub-tree
 * Return: unsigned int
 **/
unsigned int get_avl_height(avl_node_t *root)
{
	unsigned int lh, rh;

	if (!root)
		return (0);

	if (!root->right)
		rh = 0;
	else
		rh = 1 + root->right->height;

	if (!root->left)
		lh = 0;
	else
		lh = 1 + root->left->height;

	if (rh > lh)
		return (rh);

	return (lh);
}

/**
 * balance_factor - a function that returns the balance
 * factor of an avl node
 * @root: the root node of the current sub-tree
 * Return: unsigned int
 **/
unsigned int balance_factor(avl_node_t *root)
{
	unsigned int lh, rh;

	if (!root)
		return (0);

	if (!root->right)
		rh = 0;
	else
		rh = 1 + root->right->height;

	if (!root->left)
		lh = 0;
	else
		lh = 1 + root->left->height;

	return (lh - rh);
}

/**
 * rotate_left - a function that performs
 * a LL - rotation on an avl sub-tree
 * root: the root node of the current sub-tree
 * Return: the new root node after the rotation
 * 					has been performed
 **/
avl_node_t *rotate_left(avl_node_t **root)
{
	avl_node_t *right_child = (*root)->right;

	(*root)->left = right_child->left;
	right_child->left = (*root);

	(*root)->height = get_avl_height(*root);
	right_child->height = get_avl_height(right_child);

	return (right_child);
}

/**
 * rotate_right - a function that performs
 * a RR - rotation on an avl sub-tree
 * root: the root node of the current sub-tree
 * Return: the new root node after the rotation
 * 					has been performed
 **/
avl_node_t *rotate_right(avl_node_t **root)
{
	avl_node_t *left_child = (*root)->left;

	(*root)->right = left_child->right;
	left_child->right = (*root);

	(*root)->height = get_avl_height(*root);
	left_child->height = get_avl_height(left_child);

	return (left_child);
}

/**
 * avl_min - a function that finds the minimum node
 * in a sub-tree
 * @root: the root node of the sub-tree
 * Return: avl_node_t *
 **/
avl_node_t *avl_min(avl_node_t *root)
{
	avl_node_t *curr;

	if (!root || !root->left)
		return (root);

	while (root && root->left)
		root = root->left;

	return (root->left);
}

/**
 * insert_avl_node - a function that inserts a node into
 * an avl tree
 * @root: the root of the avl tree
 * @data: the value of the node to be inserted
 * Return: void
 **/
void insert_avl_node(avl_node_t **root, unsigned long data)
{
	avl_node_t *new_node;

	if (!*root)
	{
		new_node = create_avl_node(data);
		*root = new_node;
		return;
	}

	if (data > (*root)->data)
	{
		insert_avl_node(&(*root)->right, data);
		if (balance_factor(*root) < -1)
		{
			if ((*root)->right->data > data)
			{
				((*root)->right) = rotate_right(&(*root)->right);
				(*root) = rotate_left(root);
			}
			else if ((*root)->right->data < data)
			{
				(*root) = rotate_left(root);
			}
		}
	}
	else if (data < (*root)->data)
	{
		insert_avl_node(&(*root)->left, data);
		if (balance_factor(*root) > 1)
		{
			if ((*root)->left->data < data)
			{
				((*root)->left) = rotate_left(&(*root)->left);
				(*root) = rotate_right(root);
			}
			else if ((*root)->left->data > data)
			{
				(*root) = rotate_right(root);
			}
		}
	}
	(*root)->height = get_avl_height(*root);
	return;
}
