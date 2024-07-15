#include "list.h"

/**
 * insert_at_root - insert node at root
 * @list: Double pointer to the list to modify
 * @new: node to insert at root
 * Return: pointer to newly inserted node (e.g. the root)
*/
List *insert_at_root(List **list, List *new)
{
	*list = new;
	new->prev = new;
	new->next = new;

	return (new);
}

/**
 * create_node - create a new node with string data
 * @str: string to add to new node
 * Return: pointer to new node
*/
List *create_node(char *str)
{
	List *new;

	if (!str)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: Double pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *root, *last, *new;

	if (!list || !str)
		return (NULL);

	new = create_node(str);
	if (!new)
		return (NULL);

	root = *list;

	if (!root)
		return (insert_at_root(list, new));

	last = root->prev;

	last->next = new;
	new->prev = last;
	new->next = root;
	root->prev = new;

	return (new);

}

/**
 * add_node_begin - Add a new node to the beginning of
 * a double circular linked list
 * @list: Double pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *root, *last, *new;

	if (!list || !str)
		return (NULL);

	new = create_node(str);
	if (!new)
		return (NULL);

	root = *list;

	if (!root)
		return (insert_at_root(list, new));

	last = root->prev;

	last->next = new;
	new->prev = last;
	new->next = root;
	new->next->prev = new;
	*list = new;

	return (new);
}
