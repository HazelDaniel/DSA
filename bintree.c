#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *new_node(int data)
{
	struct Node *temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right =NULL;
	return temp;
}

struct Node *insert_node(struct Node *pNode, int data)
{
	if (pNode == NULL)
	{
		return new_node(data);
	}
	else if (pNode->data > data)
	{
		pNode->left = insert_node(pNode->left, data);
	}
	else
	{
		pNode->right = insert_node(pNode->right, data);
	}
	return pNode;
}

struct Node *search_tree (struct Node *pRoot, int data)
{
	if (pRoot == NULL || pRoot->data == data)
	{
		return pRoot;
	}
	else if (pRoot-> data > data)
	{
		return search_tree(pRoot->left, data);
	}
	else
	{
		return search_tree(pRoot->right, data);
	}
}

void in_order_traversal (struct Node *pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	in_order_traversal(pRoot->left);
	printf("%d\n",pRoot->data);
	in_order_traversal(pRoot->right);
}

int main() {
    struct Node* root = NULL,*found;
    root = new_node(50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("In-order traversal of the binary search tree:\n");
    in_order_traversal(root);
    printf("\n");
    found = search_tree(root, 40);
    if (found != NULL) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}
