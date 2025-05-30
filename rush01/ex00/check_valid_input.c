/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:27:37 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/30 22:00:51 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

int	digit_range(char c, char *str)
{
	int	l;

	l = len(str);
	if (c >= '1')
	{
		if (c <= '4' && l == 31)
			return (1);
		if (c <= '5' && l == 49)
			return (1);
		if (c <= '6' && l == 71)
			return (1);
		if (c <= '7' && l == 97)
			return (1);
		if (c <= '8' && l == 127)
			return (1);
		if (c <= '9' && l == 161)
			return (1);
	}
	return (-1);
}

int	check_input(char *c)
{
	int	i;

	i = 0;
	if (len(c) < 31 || len(c) > 161)
		return (-1);
	while (c[i])
	{
		if (!(digit_range(c[i], c) == 1 || c[i] == ' '))
			return (-1);
		if (i > 0)
		{
			if (digit_range(c[i], c) == 1 && digit_range(c[i - 1], c) == 1)
				return (-1);
			if (c[i] == ' ' && c[i - 1] == ' ')
				return (-1);
		}
		i++;
	}
	return (1);
}

// Check if it's not number between 1 to highest value possible in table
// and It's also not a white space
// Check for adjacent digit and space (44 or 4  2)
// Check input length(include white space) if it less than 31(4x4)
// or more than 161(9x9)