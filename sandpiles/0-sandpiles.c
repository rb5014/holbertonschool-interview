#include "sandpiles.h"
#include <stdio.h>

/**
 * print_unstable_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_unstable_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stabilize_grid - Stabilize grid
 * @grid: Poiter to 3x3 grid
*/
void stabilize_grid(int grid[3][3])
{
	int i, j, unstable = 1, tmp_grid[3][3];

	while (unstable != 0)
	{
		print_unstable_grid(grid);
		unstable = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				tmp_grid[i][j] = grid[i][j];

				if (grid[i][j] > 3)
					tmp_grid[i][j] = grid[i][j] - 4;

				if (((i - 1) >= 0) && (grid[i - 1][j] > 3))
					tmp_grid[i][j] += 1;

				if (((j - 1) >= 0) && (grid[i][j - 1] > 3))
					tmp_grid[i][j] += 1;

				if (((i + 1) < 3) && (grid[i + 1][j] > 3))
					tmp_grid[i][j] += 1;

				if (((j + 1) < 3) && (grid[i][j + 1] > 3))
					tmp_grid[i][j] += 1;
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid[i][j] = tmp_grid[i][j];
				if (grid[i][j] > 3)
					unstable = 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 * @grid1: Sandpile 1.
 * @grid2: Sandpile 2.
 * Both grid1 and grid2 are individually stable.
 * When function is done, grid1 must be stable.
 * grid1 must be printed before each toppling round, only if it is unstable.
 * Not allowed to allocate memory dynamically.
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				unstable = 1;
		}
	}
	if (unstable)
		stabilize_grid(grid1);
}
