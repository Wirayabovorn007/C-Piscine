/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:03:26 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/05 12:27:14 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	len(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	is_alpha(char s)
{
	if ((s <= 'z' && s >= 'a') || (s <= 'Z' && s >= 'A'))
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (len(base) < 2 || len(base) > 16)
		return (0);
	while (base[++i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| !(base[i] >= '0' && base[i] <= '9')
			|| !is_alpha(base[i]))
			return (0);
		while (j++ < len(base))
			if (base[i] == base[j])
				return (0);
	}
	return (len(base));
}

int	is_sign_or_space(char s, int *n)
{
	if (s == '-')
	{
		*n *= -1;
		return (1);
	}
	if (s == '+' || s == ' ')
		return (1);
	return (0);
}

int	power_recur(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * power_recur(nb, power - 1));
}

int	to_base_ten(char *nb, char *base)
{
	int	i;
	int	num;

	num = 0;
	i = -1;
	while (base[++i])
	{
		num += (base[i] * power_recur(len(base), i));
	}

}
