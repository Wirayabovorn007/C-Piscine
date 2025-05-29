/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:07:19 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/29 15:47:10 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	j;
	int	i;

	i = -1;
	if (len(base) < 2 || len(base) > 16)
		return (0);
	while (++i < len(base))
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < len(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (len(base));
}

int	power(int num, int expo)
{
	int	i;
	int	j;

	i = 1;
	j = num;
	if (expo == 0)
		return (1);
	while (i < expo)
	{
		j *= num;
		i++;
	}
	return (j);
}
int	convert_char_base_to_nbr(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	convert_to_decimal(char *str, char *base)
{
	int	i;
	int	sum;
	int	num;
	int	sign;
	int	baselen;

	i = -1;
	sum = 0;
	num = 0;
	sign = 1;
	baselen = len(base);
	while (++i < len(str))
	{
		if (str[i] == '-')
		{
			sign *= -1;
			continue ;
		}
		num = convert_char_base_to_nbr(str[i], base);
		if (num == -1)
			return (0);
		sum += num * power(baselen, len(str) - i - 1);
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b;

	b = check_base(base);
	if (b == 0)
		return (0);
	return (convert_to_decimal(str, base));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("1A", "0123456789ABCDEF"));
// 	printf("%d\n", ft_atoi_base("10101", "01"));
// 	printf("%d\n", ft_atoi_base("-123", "0123456789"));
// }