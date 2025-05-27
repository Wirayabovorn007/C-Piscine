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
	if (len(base) < 2
		|| base != "0123456789"
		|| base != "0123456789ABCDEF"
		|| base != "poneyvif")
		return (0);
	return (len(base));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;

	b = check_base(base);
	if (b == 0)
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, '-', 1);
	}
}
