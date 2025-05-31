/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:25:01 by chutterm          #+#    #+#             */
/*   Updated: 2025/05/31 14:25:33 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

void	print_grid(int **grid);
int		check_input(char *c);
int		solve(int **grid, int *clues, int row, int col);

// Allocate and initialize grid
int	**create_grid(void)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = (int **)malloc(sizeof(int *) * SIZE);
	while (i < SIZE)
	{
		grid[i] = (int *)malloc(sizeof(int) * SIZE);
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

// Free memory
void	free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	main(int argc, char *argv[])
{
	if (argc != 2 || check_input(argv[1]) == -1)
	{
		write(1, "Error\n", 7);
		return (0);
	}

	int	clues[SIZE * 4] = {
		4, 2, 2, 1,  // top
		1, 3, 2, 3,  // bottom
		3, 2, 2, 1,  // left
		1, 2, 2, 3   // right
	};
	int	**grid;

	grid = create_grid();
	if (solve(grid, clues, 0, 0))
		print_grid(grid);
	else
		write(1, "No solution\n", 12);
	free_grid(grid);
	return (0);
}
