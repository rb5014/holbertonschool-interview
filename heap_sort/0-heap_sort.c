#include "sort.h"
#define index_left_child(i) (2 * i + 1)

/**
 * swap - swap 2 values
 * @value_1: pointer to 1st value
 * @value_2: pointer to 2nd value
*/
void swap(int *value_1, int *value_2)
{
	int tmp = *value_1;
	*value_1 = *value_2;
	*value_2 = tmp;
}

/**
 * heap_sort - sorts an array of integers in
 * ascending order using the Heap sort algorithm
 * @array: array of integers of size size
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	size_t start, end, root, child;

	if (!array || !size)
		return;

	start = size / 2;
	end = size;

	while (end > 1)
	{
		if (start > 0) /* Heap construction */
			start--;
		else /* Heap extraction */
		{
			end--;
			swap(&(array[end]), &(array[0]));
			print_array(array, size);
		}

		/* Sift down part starts here */
		root = start;
		while (index_left_child(root) < end)
		{
			child = index_left_child(root);
			/* If there is a right child and that child is greater */
			if (((child + 1) < end) && (array[child] < array[child + 1]))
				child++;
			if (array[root] < array[child])
			{
				swap(&(array[root]), &(array[child]));
				print_array(array, size);
				root = child; /* repeat to continue sifting down the child now */
			}
			else
				break; /* return to outer loop */
		}
	}
}
