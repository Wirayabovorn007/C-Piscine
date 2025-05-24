/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:41:16 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/24 17:11:03 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
			if (row == 0 && (col == 0 || col == x - 1))
				ft_putchar('A');
			else if (((row > 0 && row < y - 1) && (col == 0 || col == x - 1)))
				ft_putchar('B');
			else if (((col > 0 && col < x - 1) && (row == 0 || row == y -1)))
				ft_putchar('B');
			else if ((col > 0 && col < x - 1) && (row > 0 && row < y - 1))
				ft_putchar(' ');
			else if ((row == y - 1) && (col == 0 || col == x - 1))
				ft_putchar('C');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

// int	main(void)
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
