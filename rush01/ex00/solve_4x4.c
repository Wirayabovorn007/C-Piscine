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

int	count_visible_row(int *row, int direction, int size);
int	count_visible_col(int **grid, int col, int direction, int size);
int	solve(int **grid, int *clues, int rowcol[], int size);

// Check if value is unique in row/col
int	is_valid(int **grid, int rowcol[], int val, int size)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = rowcol[0];
	col = rowcol[1];
	while (i < size)
	{
		if (grid[row][i] == val || grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

// Check all side clues
int	check_all_clues(int **grid, int *clues, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (count_visible_col(grid, i, 0, size) != clues[i])
			return (0);
		if (count_visible_col(grid, i, 1, size) != clues[size + i])
			return (0);
		if (count_visible_row(grid[i], 0, size) != clues[2 * size + i])
			return (0);
		if (count_visible_row(grid[i], 1, size) != clues[3 * size + i])
			return (0);
		i++;
	}
	return (1);
}

int	check_partial_clues(int **grid, int *clues, int rowcol[], int size)
{
	int	visible;
	int	row;
	int	col;

	row = rowcol[0];
	col = rowcol[1];
	if (col == size - 1)
	{
		if (count_visible_row(grid[row], 0, size) != clues[2 * size + row])
			return (0);
		if (count_visible_row(grid[row], 1, size) != clues[3 * size + row])
			return (0);
	}
	if (row == size - 1)
	{
		visible = count_visible_col(grid, col, 0, size);
		if (visible != clues[col])
			return (0);
		visible = count_visible_col(grid, col, 1, size);
		if (visible != clues[size + col])
			return (0);
	}
	return (1);
}

int	try(int **grid, int *clues, int rowcol[], int size)
{
	int	val;
	int	row;
	int	col;
	int	newrc[2];

	row = rowcol[0];
	col = rowcol[1];
	val = 1;
	while (val <= size)
	{
		if (is_valid(grid, rowcol, val, size))
		{
			grid[row][col] = val;
			if (check_partial_clues(grid, clues, rowcol, size))
			{
				newrc[0] = row;
				newrc[1] = col + 1;
				if (solve(grid, clues, newrc, size))
					return (1);
			}
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}

// Recursive backtracking solver
int	solve(int **grid, int *clues, int rowcol[], int size)
{
	int	row;
	int	col;
	int	newrc[2];

	row = rowcol[0];
	col = rowcol[1];
	if (row == size)
		return (check_all_clues(grid, clues, size));
	if (col == size)
	{
		newrc[0] = row + 1;
		newrc[1] = 0;
		return (solve(grid, clues, newrc, size));
	}
	return (try(grid, clues, rowcol, size));
}
