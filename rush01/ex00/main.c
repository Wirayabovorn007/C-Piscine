/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:58:13 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/30 22:28:13 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_input(char *c);
int	len(char *l);

int	main(int argc, char *argv[])
{
	int	table_size;

	if ((argc != 2) || check_input(argv[1]) == -1)
		write(2, "Error\n", 6);
	table_size = len(argv[1]);
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