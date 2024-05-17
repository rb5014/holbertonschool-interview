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

	while (second != end + direction)
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
				if (line[second] == line[first])
				{
					line[start] = line[second] * 2;
					if (first != start)
						line[first] = 0;
					first = second + direction;
				}
				line[second] = 0;
				start += direction;
				break;
			}
			second += direction;
		}
		line[start] = line[first];
		if (first != start)
			line[first] = 0;
	}
	return (1);
}
