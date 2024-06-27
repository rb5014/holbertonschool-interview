#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast_ptr = head, *slow_ptr = head;

	/*
	 * Use two pointers moving at different speeds (slow_ptr moves 1 step,
	 * fast_ptr moves 2 steps) to detect a cycle in the linked list.
	 */
	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;		 /* Move slow_ptr one step forward */
		fast_ptr = fast_ptr->next->next; /* Move fast_ptr two steps forward */

		/*
		 * If slow_ptr and fast_ptr meet, there is a cycle in the list.
		 * Both pointers are now somewhere inside the cycle.
		 */
		if (slow_ptr == fast_ptr)
		{
			/*
			 * Move slow_ptr back to the head of the list.
			 * Keep fast_ptr at the meeting point.
			 * Both pointers now move one step at a time.
			 * The point where they meet again is the start of the loop.
			 */
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next; /* Move slow_ptr one step forward */
				fast_ptr = fast_ptr->next; /* Move fast_ptr one step forward */
			}
			/* Return the start of the loop */
			return (slow_ptr);
		}
	}

	/* If no loop is found, return NULL */
	return (NULL);
}
