/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:32:44 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/29 15:05:07 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len(char *b)
{
	int	i;

	i = 0;
	while (b[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	b;

	b = len(base);
	i = -1;
	if (b < 2)
		return (0);
	while (++i < b)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < b)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (b);
}

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	long	n;

	n = nbr;
	b = check_base(base);
	if (!b)
		return ;
	if (n < 0)
	{
		print('-');
		n *= -1;
	}
	if (n >= b)
		ft_putnbr_base(n / b, base);
	print(base[n % b]);
}

// int main() {
//     ft_putnbr_base(6, "01");
//     write(1, "\n", 1);
//     ft_putnbr_base(1453, "0123456789ABCDEF");
//     write(1, "\n", 1);
//     ft_putnbr_base(83, "poneyvif");
//     write(1, "\n", 1);
//     ft_putnbr_base(103, "0123456789");
//     write(1, "\n", 1);
//     ft_putnbr_base(123, "+0123456789");
//     return 0;
// }