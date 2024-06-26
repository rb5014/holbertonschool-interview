#include "binary_trees.h"

/**
 * parent - find parent index of a given node in prio queue
 * @i: index of the node
 * Return: the parent's index
*/
size_t parent(size_t i)
{
	return ((i - 1) / 2);
}

/**
 * swap_nodes_data - Swaps the data between two binary tree nodes
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes_data(binary_tree_t *node1, binary_tree_t *node2)
{
	int tmp_data;

	/* Swap the data between the two nodes */
	tmp_data = node1->n;
	node1->n = node2->n;
	node2->n = tmp_data;
}

/**
 * heapify_up - Maintains the MAX heap property by
 * moving a node upwards in the heap
 * @node: Pointer to the node from which the heapification starts
 *
 * Description:
 * This function moves the given node upwards in the heap, swapping it with its
 * parent if necessary to maintain the heap property. It continues this process
 * until either the node becomes the root of the heap or it satisfies the heap
 * property.
 * Return: Pointer to the new node containing the data inserted
 */
binary_tree_t *heapify_up(binary_tree_t *node)
{
	/* Continue as long as the node has a parent and violates the heap property */
	while (node->parent && (node->n > node->parent->n))
	{
		/* Swap the data of the current node with its parent */
		swap_nodes_data(node, node->parent);

		node = node->parent; /* Move to the parent node for further heapification */
	}
	return (node);
}

/**
 * find_parent_for_insertion - Find the parent node for inserting a new node
 * @root: Pointer to the root node of the binary tree
 *
 * Return: Pointer to the parent node where the new node should be inserted
 */
binary_tree_t *find_parent_for_insertion(binary_tree_t *root)
{
	binary_tree_t *queue[100];
	int front = -1, rear = 0;

	/* If the tree is empty, return NULL */
	if (root == NULL)
		return (NULL);

	queue[rear] = root;

	while ((front != rear) && (rear < 99))
	{
		if (queue[++front] == NULL)
			return (queue[parent(front)]);
		queue[++rear] = queue[front]->left;
		queue[++rear] = queue[front]->right;
	}

	return (NULL);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * If the address stored in root is NULL,
 * the created node must become the root node.
 * Have to respect a Max Heap ordering.
 * Allowed to have up to 6 functions in file.
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: return a pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new_node, *parent;

	if (!root)
		return (NULL);

	/* Create the new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If the heap is empty, set the new node as the root */
	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}
	/* Find the parent node where the new node should be inserted */
	parent = find_parent_for_insertion(*root);
	if (!parent)
		return (free(new_node), NULL);
	/* Insert the new node as a child of the found parent */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;

	/* Restore the heap property by percolating up */
	new_node = heapify_up(new_node);

	return (new_node);

}
