#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * is_palindrome - check if linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if not palindrome, 1 if palindrome
 * An empty list is considered a palindrome
 */

int is_palindrome(listint_t **head)
{
	int *values = NULL, nb_values = 0;
	listint_t *current = *head;


	if (*head == NULL)
		return (0);

	while (current != NULL)
	{
		nb_values++;
		values = realloc(values, nb_values);
		values[nb_values - 1] = current->n;
		current = current->next;
		if (current->n == values[nb_values - 1])
		{
			while ((current != NULL) && (nb_values > 0))
			{
				if (current->n != values[nb_values - 1])
					return (0);
				nb_values--;
				current = current->next;
			}
			return (1);
		}
	}
	return (0);
}
