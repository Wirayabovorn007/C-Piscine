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

int	is_sep(char *s, char *c, int i)
{
	int	j;

	j = 0;
	while (c[j])
	{
		if (!s[i + j] || s[i + j] != c[j])
			return (0);
		j++;
	}
	return (1);
}

int	count_word(char *str, char *ch)
{
	int	count;
	int	in_word;
	
}

int	len_word(char *str,char *ch ,int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (!is_sep(str, ch, i))
		{
			count++;
			i++;
		}
		else
			break ;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		c;
	int		i;
	int		w;
	int		word_len;
	char	**result;

	if (!str || !charset)
		return (NULL);
	i = 0;
	c = count_word(str, charset);
	result = malloc(sizeof(char *) * (c + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		if (is_sep(str, charset, 0))
		{
			str += len(charset);
			continue ;
		}
		word_len = len_word(str, charset, 0);
		if (word_len > 0)
		{
			result[i] = malloc(word_len + 1);
			if (!result[i])
				return (NULL);
			w = -1;
			while (++w < word_len)
				result[i][w] = str[w];
			result[i][w] = '\0';
			str += word_len;
			i++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
