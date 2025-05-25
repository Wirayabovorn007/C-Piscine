/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduangpl <cduangpl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:11:28 by cduangpl          #+#    #+#             */
/*   Updated: 2025/05/24 13:40:50 by cduangpl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	column;
	int	row;

	column = 0;
	row = 0;
	while (column < y)
	{
		row = 0;
		while (row < x)
		{
			if (column >= 1 && column <= y - 2 && row >= 1 && row <= x - 2)
				ft_putchar(' ');
			else if (row == 0 && (column == 0 || column == y - 1))
				ft_putchar('A');
			else if (row == x - 1 && (column == 0 || column == y - 1))
				ft_putchar('C');
			else
				ft_putchar('B');
			row++;
		}
		write(1, "\n", 1);
		column++;
	}
}

// int	main(void)
// {
// 	rush(5, 3);
// 	write(1, "\n", 1);
// 	rush(5, 1);
// 	write(1, "\n", 1);
// 	rush(1, 1);
// 	write(1, "\n", 1);
// 	rush(1, 5);
// 	write(1, "\n", 1);
// 	rush(4, 4);
// 	return (0);
// }
