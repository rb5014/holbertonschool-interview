#include "binary_trees.h"

/**
 * swap_nodes_data - Swaps the data between two binary tree nodes
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes_data(heap_t *node1, heap_t *node2)
{
	int tmp_n;

	/* Swap the data between the two nodes */
	tmp_n = node1->n;
	node1->n = node2->n;
	node2->n = tmp_n;
}

/**
 * get_last_node - return last node
 * @root: pointer to the root of the heap
 * Return: pointer to the data of the last node, or NULL on failure
 */
void *get_last_node(heap_t *root)
{
	heap_t *queue[100];
	int front = -1, rear = 0;

	/* If the tree is empty, return NULL */
	if (root == NULL)
		return (NULL);

	queue[rear] = root;

	while (front != rear)
	{
		front++;
		if (queue[front]->left)
			queue[++rear] = queue[front]->left;
		if (queue[front]->right)
			queue[++rear] = queue[front]->right;
	}

	return (queue[rear]);
}

/**
 * get_max_child - get the maximum child of a node
 * @node: pointer to the node from which we check the children
 * Return: pointer to the maximum child of the parent node,
 * or the only child (if one of them is NULL),
 * or NULL if both children are NULL
 */
heap_t *get_max_child(heap_t *node)
{
	heap_t *max_child;

	if (node->left && node->right)
	{
		if (node->left->n >= node->right->n)
			max_child = node->left;
		else
			max_child = node->right;
	}
	else if (node->left)
		max_child = node->left;
	else if (node->right)
		max_child = node->right;
	else
		max_child = NULL;
	return (max_child);
}

/**
 * heapify_down - Maintains the heap property by
 * moving a node downwards in the heap
 * @node: Pointer to the node
 * Description:
 * This function moves the given node downwards in the heap,
 * swapping it with its
 * parent if necessary to maintain the heap property. It continues this process
 * recursively until either the node becomes a leaf of the heap or
 * it satisfies the heap property.
 */
void heapify_down(heap_t *node)
{
	heap_t *max_child = get_max_child(node);

	if (max_child && (max_child->n > node->n))
	{
		swap_nodes_data(max_child, node);
		heapify_down(max_child);
	}
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @root: double pointer to the root of the heap
 * Return: value that was extracted or 0 if it fails
 * Once the data is extracted the root node must be
 * replaced by the last node of the heap.
 * Then the heap must be rebuilt if necessary
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *parent;
	int root_data;

	if (!root || !*root)
		return (0);

	root_data = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (root_data);
	}

	last_node = get_last_node(*root);

	(*root)->n = last_node->n;

	parent = last_node->parent;
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(last_node);
	heapify_down(*root);
	return (root_data);
}
