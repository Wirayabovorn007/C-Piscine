/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:03:26 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/10 12:46:29 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (len(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] <= 32 || base[i] == 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_ind(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (get_ind(*str, base) != -1)
	{
		result = result * len(base) + get_ind(*str, base);
		str++;
	}
	return (result * sign);
}
