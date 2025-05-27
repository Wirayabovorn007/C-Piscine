/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:32:44 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/27 15:12:52 by wiboonpr         ###   ########.fr       */
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
		j = i; 
		while (++j < b)
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (b);
}

void print(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;

	b = check_base(base);
	if (!b)
		return ;
	if (nbr < 0)
	{
		print('-');
		nbr *= -1;
	}
	if (nbr >= b)
		ft_putnbr_base(nbr / b, base);
	print(base[nbr % b]);
}


// int main() {
//     ft_putnbr_base(6, "01");
//     write(1, "\n", 1);
//     ft_putnbr_base(255, "0123456789ABCDEF");
//     write(1, "\n", 1);
//     ft_putnbr_base(83, "poneyvif");
//     write(1, "\n", 1);
//     ft_putnbr_base(123, "0123456789");
//     write(1, "\n", 1);
//     ft_putnbr_base(123, "+0123456789");
//     write(1, "\n", 1);
//     return 0;
// }
