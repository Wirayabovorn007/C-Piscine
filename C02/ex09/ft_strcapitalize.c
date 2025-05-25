/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:58:08 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/25 16:12:06 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alpha(char str)
{
	if (!((str <= 'z' && str >= 'a')
			|| (str <= 'Z' && str >= 'A')))
	{
		return (0);
	}
	return (1);
}

int	is_numeric(char str)
{
	if (!(str <= '9' && str >= '0'))
	{
		return (0);
	}
	return (1);
}

int	is_lowercase(char str)
{
	if (!(str <= 'z' && str >= 'a'))
	{
		return (0);
	}
	return (1);
}

int	is_uppercase(char str)
{
	if (!(str <= 'Z' && str >= 'A'))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_uppercase(str[i]) == 1 && i != 0)
		{
			str[i] = str[i] + 32;
		}
		if (is_lowercase(str[i]) == 1
			&& (i == 0 || !(is_alpha(str[i - 1])
					|| is_numeric(str[i - 1]) == 1)))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

// int	main()
// {
// 	char str[] = "hi, how are you? 42words forty-two; fifty+and+one";
// 	ft_strcapitalize(str);
// 	printf("%s", str);
// }
