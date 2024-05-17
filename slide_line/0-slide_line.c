#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of size n integers
 * @size: size of the array
 * @direction: direction of the slide and merge
 * Return: 1 if success, 0 if it fails
 * Given an array of integers, we want to be able to slide & merge it to
 * the left or to the right. Identical numbers, if they are contiguous
 * or separated by zeros, should be merged (See example)
*/
int slide_line(int *line, size_t size, int direction)
{
	int start = (direction == SLIDE_LEFT) ? 0 : size - 1;
	int end = (direction == SLIDE_LEFT) ?  size - 1 : 0;
	int first = start, second = start;

	if (!line || !size ||
	    ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT)))
		return (0);
	while (first != end + direction)
	{
		if (line[first] == 0)
		{
			first += direction;
			second = first;
			continue;
		}
		second += direction;
		while (second != end + direction)
		{
			if (line[second] != 0)
			{
				line[start] = line[first];
				if (line[second] == line[first])
				{
					line[start] += line[second];
					line[second] = 0;
				}
				line[first] = (first != start) ? 0 : line[first];
				first = second;
				start += direction;
				break;
			}
			second += direction;
		}
		if (second == end + direction)
		{
			line[start] = line[first];
			line[first] = (first != start) ? 0 : line[first];
		}
	}
	return (1);
}
