/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:12:09 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/24 18:22:02 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int col, int row, int x, int y)
{
	if (((row > 0 && row < y - 1) && (col == 0 || col == x - 1)))
		ft_putchar('B');
	else if (((col > 0 && col < x - 1) && (row == 0 || row == y -1)))
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			if ((row == 0 && col == 0) || ((col == x - 1 && row == y - 1))
				&& y != 1 && x != 1)
				ft_putchar('A');
			else if ((col > 0 && col < x - 1) && (row > 0 && row < y - 1))
				ft_putchar(' ');
			else if ((row == y - 1 || row == 0) && (col == 0 || col == x - 1))
				ft_putchar('C');
			check(col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
