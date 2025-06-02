/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:32:09 by chutterm          #+#    #+#             */
/*   Updated: 2025/06/01 16:13:14 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_index(int direction, int size)
{
	if (direction)
	{
		return (size - 1);
	}
	else
	{
		return (0);
	}
}

int	check_step(int direction)
{
	if (direction)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

// Count visible skyscrapers in row (left or right)
int	count_visible_row(int *row, int direction, int size)
{
	int	i;
	int	step;
	int	max;
	int	count;

	i = check_index(direction, size);
	step = check_step(direction);
	max = 0;
	count = 0;
	while (i >= 0 && i < size)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i += step;
	}
	return (count);
}

// Count visible skyscrapers in column (top or bottom)
int	count_visible_col(int **grid, int col, int direction, int size)
{
	int	i;
	int	step;
	int	max;
	int	count;

	i = check_index(direction, size);
	step = check_step(direction);
	max = 0;
	count = 0;
	while (i >= 0 && i < size)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i += step;
	}
	return (count);
}
