#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located, or -1
 * Array is printed everytime it is splitted in two
 * Recursion must be used, and only one loop can be used
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, pivot;
	int ret = 0;

	if (!array | !size)
		return (-1);

	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(",");
		printf(" %i", array[i]);
	}
	printf("\n");

	pivot = (size - 1) / 2;

	if ((pivot == 0) && (value == array[pivot]))
		return (0);

	if (value > array[pivot])
	{
		ret = advanced_binary(&(array[pivot + 1]), size - pivot - 1, value);
		if (ret != -1)
			ret += pivot + 1;

	}
	else if (value <= array[pivot])
	{
		ret = advanced_binary(array, pivot + 1, value);
	}
	return (ret);
}
