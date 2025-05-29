/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:48:39 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/29 14:30:07 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

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

int	is_alpha(char s)
{
	if ((s <= 'z' && s >= 'a') || (s <= 'Z' && s >= 'A'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;
	int		digit_found;

	i = -1;
	sign = 1;
	result = 0;
	digit_found = 0;
	while (str[++i] != '\0')
	{
		if (is_alpha(str[i]) || (str[i] == ' ' && digit_found))
			break ;
		if (is_sign_or_space(str[i], &sign))
			continue ;
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit_found = 1;
			result = result * 10 + (str[i] - '0');
		}
	}
	return (result * sign);
}

// #include <stdio.h>

// int	main()
// {
// 	char numstr[] = "+       +--+-1    2   3    4    5";
// 	printf("%d", ft_atoi(numstr));
// }