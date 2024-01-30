#include "binary_trees.h"

void add_level(level_t **levels, int *nb_levels)
{
	*levels = realloc(levels, sizeof(level_t) * (*nb_levels));
	
}

level_t *gen_level_repr(heap_t *root, int *nb_levels)
{
	level_t *levels = NULL;
	level_t current_level;

	if (!root)
		return (NULL);

	*nb_levels++;
	levels = malloc(sizeof(level_t) * (*nb_levels));
	levels[*nb_levels - 1].nodes[0] = root;
	levels[*nb_levels - 1].nb_nodes = 1;

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
	int nb_levels;
	static level_t *levels;

	if (!levels)
		levels = gen_level_repr(*root, &nb_levels);

}
