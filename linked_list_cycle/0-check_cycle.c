#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: linked list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 * Requirements:
 * Only these functions are allowed: write, printf, putchar, puts, malloc, free
*/
int check_cycle(listint_t *list)
{
	listint_t *tmp_0 = list, *tmp_1;

	if (!list)
		return (0);

	while (tmp_0->next)
	{
		tmp_1 = list;
		while (tmp_1 != tmp_0)
		{
			if (tmp_0->next == tmp_1)
				return (1);
			tmp_1 = tmp_1->next;
		}
		tmp_0 = tmp_0->next;
	}
	return (0);
}
