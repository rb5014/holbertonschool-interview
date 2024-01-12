#include "lists.h"
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else if ((*head)->n >= number)
    {
		new->next = *head;
		*head = new;
	}
	else
	{
        while (current->next != NULL)
		{
			if (current->next->n >= number)
			{
        		new->next = current->next;
				current->next = new;
				break;
			}
			current = current->next;
		}
		if (current->next == NULL)
		{
			free(new);
			add_nodeint_end(head, number);
		}
    }

    return (new);
}