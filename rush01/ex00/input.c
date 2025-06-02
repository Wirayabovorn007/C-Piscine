/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andanjir <andanjir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:58:13 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/01 23:36:54 by andanjir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_input(char *c);
int	len(char *l);

int	input(int *clues, int argc, char *argv[])
{
	int	i;
	int	j;

	if ((argc != 2) || check_input(argv[1]) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ')
		{
			clues[j] = argv[1][i] - '0';
			j++;
		}
		i++;
	}
	return (1);
}

	//2 = first argument in argc
	// Actual first argument in argv[] start with index 1
	// printf("%d\n", argc);
	// printf("%s\n", argv[0]);
	// printf("%s\n", argv[1]);

	//table size = 31 (4x4)
	//table size = 49 (5x5)
	//table size = 71 (6x6)
	//table size = 97 (7x7)
	//table size = 127 (8x8)
	//table size = 161 (9x9)
