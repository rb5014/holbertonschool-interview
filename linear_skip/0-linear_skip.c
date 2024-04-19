#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * A node of the express lane is placed every index which is a multiple
 * of the square root of the size of the list
 * That list will be sorted in ascending order
 * Your function must return a pointer on the first node where value is located
 * Every time we compare a value in the list to the value we are searching,
 * print this value
 * Return: pointer on the first node where value is located, or
 * if value is not present in list or if head is NULL, return NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp, *old_tmp;

	if (!list)
		return (NULL);

	value = value;
	tmp = list->express;
	old_tmp = list;
	while (tmp)
	{
		printf("Value checked at index [%lu] = [%i]\n", tmp->index, tmp->n);
		if (tmp->n >= value)
			break;
		old_tmp = tmp;
		tmp = tmp->express;
	}
	if (!tmp)
	{
		tmp = old_tmp;
		while (tmp->next)
			tmp = tmp->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			old_tmp->index, tmp->index);
	while (old_tmp)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				old_tmp->index, old_tmp->n);
		if (old_tmp->n == value)
			return (old_tmp);
		old_tmp = old_tmp->next;
	}
	return (NULL);
}
