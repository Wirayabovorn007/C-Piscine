/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:35 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/22 12:49:29 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putchar(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
}

void	space(char c, char sp)
{
	write(1, &c, 1);
	write(1, &sp, 1);
}

void	check(int i, int j, int k)
{
	if (i < j && j < k)
	{
		ft_putchar(i, j, k);
		if (!(i == '7' && j == '8' && k == '9'))
		{
			space(',', ' ');
		}
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '7')
	{
		j = '0';
		while (j <= '8')
		{
			k = '0';
			while (k <= '9')
			{
				check(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
