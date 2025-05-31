/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andanjir <andanjir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:32:09 by chutterm          #+#    #+#             */
/*   Updated: 2025/05/31 16:47:50 by andanjir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_index(int direction, int SIZE)
{
	if (direction)
	{
		return (SIZE - 1);
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
int	count_visible_row(int *row, int direction, int SIZE)
{
	int	i;
	int	step;
	int	max;
	int	count;

	i = check_index(direction, SIZE);
	step = check_step(direction);
	max = 0;
	count = 0;
	while (i >= 0 && i < SIZE)
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
int	count_visible_col(int **grid, int col, int direction, int SIZE)
{
	int	i;
	int	step;
	int	max;
	int	count;

	i = check_index(direction, SIZE);
	step = check_step(direction);
	max = 0;
	count = 0;
	while (i >= 0 && i < SIZE)
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
