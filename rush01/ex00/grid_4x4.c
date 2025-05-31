/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_4x4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:59:03 by chutterm          #+#    #+#             */
/*   Updated: 2025/05/31 12:59:03 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	count_visible_col(int **grid, int col, int direction, int SIZE);
int	count_visible_row(int *row, int direction, int SIZE);

// Check if value is unique in row/col
int	is_valid(int **grid, int row, int col, int val, int SIZE)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == val || grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

// Check all side clues
int	check_all_clues(int **grid, int *clues, int SIZE)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (count_visible_col(grid, i, 0, SIZE) != clues[i])
			return (0);
		if (count_visible_col(grid, i, 1, SIZE) != clues[SIZE + i])
			return (0);
		if (count_visible_row(grid[i], 0, SIZE) != clues[2 * SIZE + i])
			return (0);
		if (count_visible_row(grid[i], 1, SIZE) != clues[3 * SIZE + i])
			return (0);
		i++;
	}
	return (1);
}

// Recursive backtracking solver
int	solve(int **grid, int *clues, int row, int col, int SIZE)
{
	int	val;

	if (row == SIZE)
		return (check_all_clues(grid, clues, SIZE));
	if (col == SIZE)
		return (solve(grid, clues, row + 1, 0, SIZE));
	val = 1;
	while (val <= SIZE)
	{
		if (is_valid(grid, row, col, val, SIZE))
		{
			grid[row][col] = val;
			if (solve(grid, clues, row, col + 1, SIZE))
				return (1);
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}
