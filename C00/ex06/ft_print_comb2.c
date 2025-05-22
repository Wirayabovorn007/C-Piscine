/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:39 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/22 12:32:18 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <unistd.h>
#include <stdio.h>

void	put_num(int n)
{
	char	digit[2];

	digit[0] = '0' + n / 10;
	digit[1] = '0' + n % 10;
	write(1, &digit, 2);
}

void	put_char(char n)
{
	write(1, &n, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			put_num(i);
			put_char(' ');
			put_num(j);
			if (i != 98)
			{
				put_char(',');
				put_char(' ');
			}
			j++;
		}
		i++;
	}
}
