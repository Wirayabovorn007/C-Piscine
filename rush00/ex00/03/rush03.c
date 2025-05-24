/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 09:32:14 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/24 16:42:33 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < y)
	{
		row = 0;
		while (row < x)
		{
			if (col >= 1 && col <= y -2 && row >= 1 && row <= x -2)
				write(1, " ", 1);
			else if (row == 0 && (col == 0 || col == y -1 ))
				write(1, "A", 1);
			else if (row == x - 1 && (col == 0 || col == y -1))
				write(1, "C", 1);
			else
				write(1, "B", 1);
			row++;
		}
		write(1, "\n", 1);
		col++;
	}
}


int	main()
{
	rush(4, 4);
}
