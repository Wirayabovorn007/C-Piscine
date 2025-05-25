/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduangpl <cduangpl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:47:35 by cduangpl          #+#    #+#             */
/*   Updated: 2025/05/25 09:52:10 by cduangpl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int col, int row, int x, int y)
{
	if ((col == 0 && row == 0))
		ft_putchar('/');
	else if ((col == x - 1) && (row == 0))
		ft_putchar('\\');
	else if ((row == y - 1) && (col == 0))
		ft_putchar('\\');
	else if ((col == x - 1) && (row == y - 1))
		ft_putchar('/');
	else if ((row == 0 || row == y - 1))
		ft_putchar('*');
	else if ((row > 0 && row < y - 1) && (col == 0 || col == x - 1))
		ft_putchar('*');
	else if ((row > 0 && row < y - 1) && (col > 0 || col < x - 1))
		ft_putchar(' ');
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

// int main()
// {
// 	rush(5, 3);
// 	ft_putchar('\n');
// 	rush(5, 1);
// 	ft_putchar('\n');
// 	rush(1, 1);
// 	ft_putchar('\n');
// 	rush(1, 5);
// 	ft_putchar('\n');
// 	rush(4, 4);
// 	ft_putchar('\n');
// }