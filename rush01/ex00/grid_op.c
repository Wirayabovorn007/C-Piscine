int	count_visible_col(int **grid, int col, int direction, int SIZE);
int	count_visible_row(int *row, int direction, int SIZE);
int	is_valid(int **grid, int row, int col, int val, int SIZE);
int	check_all_clues(int **grid, int *clues, int SIZE);


// Check partial row/column if filled
int	check_partial_clues(int **grid, int *clues, int row, int col, int SIZE)
{
	int	i;
	int	visible;

	// Check row if last column
	if (col == SIZE - 1)
	{
		if (count_visible_row(grid[row], 0, SIZE) != clues[2 * SIZE + row])
			return (0);
		if (count_visible_row(grid[row], 1, SIZE) != clues[3 * SIZE + row])
			return (0);
	}
	// Check column if last row
	if (row == SIZE - 1)
	{
		visible = count_visible_col(grid, col, 0, SIZE);
		if (visible != clues[col])
			return (0);
		visible = count_visible_col(grid, col, 1, SIZE);
		if (visible != clues[SIZE + col])
			return (0);
	}
	return (1);
}

// Recursive backtracking solver
int	solve_t(int **grid, int *clues, int row, int col, int SIZE)
{
	int	val;

	if (row == SIZE)
		return (check_all_clues(grid, clues, SIZE));
	if (col == SIZE)
		return (solve_t(grid, clues, row + 1, 0, SIZE));
	val = 1;
	while (val <= SIZE)
	{
		if (is_valid(grid, row, col, val, SIZE))
		{
			grid[row][col] = val;
			if (check_partial_clues(grid, clues, row, col, SIZE))
			{
				if (solve_t(grid, clues, row, col + 1, SIZE))
					return (1);
			}
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int SIZE = 4;
	int clues[] = {
		2, 2, 1, 3,  // top
		2, 2, 3, 1,  // bottom
		1, 2, 2, 3,  // left
		3, 2, 1, 2   // right
	};
	int **grid = malloc(SIZE * sizeof(int *));
	int i = 0;
	while (i < SIZE)
	{
		grid[i] = malloc(SIZE * sizeof(int));
		int j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}

	if (solve_t(grid, clues, 0, 0, SIZE))
	{
		i = 0;
		while (i < SIZE)
		{
			int j = 0;
			while (j < SIZE)
			{
				printf("%d ", grid[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	else
		printf("No solution\n");

	i = 0;
	while (i < SIZE)
		free(grid[i++]);
	free(grid);
	return (0);
}
