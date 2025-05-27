/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:48:39 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/27 10:33:23 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sign(char str, int *sign)
{
	if (str == '-')
		*sign *= -1;
	if (str == ' ' || (!(str >= '0' && str <= '9')
			|| !((str >= 'a' && str <= 'z')
				|| (str >= 'A' && str <= 'Z'))))
	{
		return (1);
	}
	return (0);
}

int	is_other(char str)
{
	if ((str != '-' && str != '+') && !(str >= '0' && str <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	int	digit_found;

	i = 0;
	sign = 1;
	result = 0;
	digit_found = 0;
	while (str[i] != '\0')
	{
		if (is_sign(str[i], &sign) == 1)
			i++;
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			digit_found = 1;
			result = result * 10 + (str[i] - '0');
		}
		if (is_other(str[i]) == 0 && digit_found == 1)
			break ;
	}
	return (result * sign);
}

// #include <stdio.h>

// int	main()
// {
//     char s[] = " ---+++---+12-34ab567";
// 	printf("%d", ft_atoi(s));

//     return 0;
// }
