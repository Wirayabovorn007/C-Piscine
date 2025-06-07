/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:12:49 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/07 15:29:08 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	check(char *s, char *c, int i)
{
	int	j;

	j = 0;
	while (c[j])
	{
		if (s[i + j] != c[j])
			return (0);
		j++;
	}
	return (1);
}

int	count_word(char *str, char *ch)
{
	int		i;
	int		count;
	char	lastc;

	i = 0;
	count = 0;
	if (!*str || !*ch)
		return (0);
	if (len(str) > 0)
		lastc = str[0];
	while (i < len(str))
	{
		if ((check(str, ch, i) || str[i] == '\0') && lastc != )
		{
			count++;
			i += len(ch);
		}
		else
			i++;
		lastc = str[i];
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		c;
	int		i;
	char	*temp;
	char	**result;

	i = 0;
	c = count_word(str, charset);
	result = malloc(sizeof(int *) * (c + 1));
	if (!result)
		return (NULL);
	result[c + 1] = '\0';
	while (i < c)
	{
		
	}
}
