/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andanjir <andanjir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:25:01 by chutterm          #+#    #+#             */
/*   Updated: 2025/05/31 16:52:58 by andanjir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_grid(int **grid, int SIZE);
int		solve(int **grid, int *clues, int row, int col, int SIZE);
int		input(int *clues, int argc, char *argv[]);
int		len(char *l);

// Allocate and initialize grid
int	**create_grid(int SIZE)
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
void	free_grid(int **grid, int SIZE)
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

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;

	int c = (len(argv[1]) + 1) / 2;
	int SIZE = c / 4;
	printf("%d", SIZE);
	printf("%d\n", c);
	clues = malloc(sizeof(int) * c);
	input(clues, argc, argv);
	grid = create_grid(c);
	if (solve(grid, clues, 0, 0, SIZE))
		print_grid(grid, SIZE);
	else
		write(1, "No solution\n", 12);
	free_grid(grid, SIZE);
	free(clues);
	return (0);
}
