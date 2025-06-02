/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:27:37 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/01 23:11:46 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	len(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

int	count_num(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	if (count % 4 != 0)
		return (0);
	return (count);
}

int	digit_range(char c, char *str)
{
	int	s;

	s = count_num(str) / 4;
	if (c >= '1' && c <= ('0' + s))
		return (1);
	return (0);
}

int	not_only_num(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9') && c[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char *c)
{
	int	i;

	i = 0;
	if (count_num(c) < 16 || count_num(c) > 36 || not_only_num(c) == 0)
		return (0);
	while (c[i])
	{
		if (c[i] == ' ' && i == 0)
			return (0);
		if (!(digit_range(c[i], c) == 1 || c[i] == ' '))
			return (0);
		if (i > 0)
		{
			if (c[i] == ' ' && !c[i + 1])
				return (0);
			if (digit_range(c[i], c) == 1 && digit_range(c[i - 1], c) == 1)
				return (0);
			if (c[i] == ' ' && c[i - 1] == ' ')
				return (0);
		}
		i++;
	}
	return (1);
}
