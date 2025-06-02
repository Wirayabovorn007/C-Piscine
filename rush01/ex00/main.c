/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:25:01 by chutterm          #+#    #+#             */
/*   Updated: 2025/06/01 23:12:01 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_grid(int **grid, int size);
int		solve(int **grid, int *clues, int rowcol[], int size);
int		input(int *clues, int argc, char *argv[]);
int		count_num(char *str);
int		print_error(void);

// Allocate and initialize grid
int	**create_grid(int size)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		grid[i] = (int *)malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

// Free memory
void	free_grid(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_all(int **grid, int size, int *clues)
{
	free_grid(grid, size);
	free(clues);
	grid = NULL;
	clues = NULL;
	if (grid != NULL || clues != NULL)
		write(2, "Unable to de-allocated memory\n", 31);
}

int	check_allocated(int	*clues, int **grid)
{
	if (clues == NULL || grid == NULL)
	{
		write(2, "Error: Cannot allocated memory\n", 32);
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;
	int	c;
	int	size;
	int	rowcol[2];

	if (argc != 2)
		return (print_error());
	c = (count_num(argv[1]));
	if (c == 0)
		return (print_error());
	size = c / 4;
	clues = malloc(sizeof(int) * c);
	grid = create_grid(c);
	if (check_allocated(clues, grid) == 0 || input(clues, argc, argv) == 0)
		return (0);
	rowcol[0] = 0;
	rowcol[1] = 0;
	if (solve(grid, clues, rowcol, size))
		print_grid(grid, size);
	else
		write(2, "Error\n", 7);
	free_all(grid, size, clues);
	return (1);
}
