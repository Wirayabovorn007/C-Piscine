/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:51:58 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/24 16:24:00 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int col, int row, int x, int y)
{
	if (((col == 0 || col == x - 1) && (row == 0 || row == y - 1)))
	{
		ft_putchar('o');
	}
	else if ((row == 0 || row == y - 1))
	{
		ft_putchar('-');
	}
	else if ((row > 0 && row < y - 1) && (col == 0 || col == x - 1))
	{
		ft_putchar('|');
	}
	else if ((row > 0 && row < y - 1) && (col > 0 || col < x - 1))
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			check (col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

// For check testcases
// int main()
// {
// 	rush(5, 3);
// 	ft_putchar(1, "\n", 1);
// 	rush(5, 1);
// 	ft_putchar(1, "\n", 1);
// 	rush(1, 1);
// 	ft_putchar(1, "\n", 1);
// 	rush(1, 5);
// 	ft_putchar(1, "\n", 1);
// 	rush(4, 4);
// 	ft_putchar(1, "\n", 1);
// }
