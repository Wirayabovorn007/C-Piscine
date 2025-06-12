/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:04:44 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/12 11:06:42 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	count_word(char *str, char *sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_sep(*str, sep))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*word_dup(char *start, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	*next_word(char **str, char *charset, int *len)
{
	char	*start;

	while (**str && is_sep(**str, charset))
		(*str)++;
	start = *str;
	*len = 0;
	while (**str && !is_sep(**str, charset))
	{
		(*str)++;
		(*len)++;
	}
	return (start);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len;
	int		words;
	char	*start;
	char	**res;

	i = 0;
	len = 0;
	words = count_word(str, charset);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < words)
	{
		start = next_word(&str, charset, &len);
		res[i++] = word_dup(start, len);
	}
	res[i] = NULL;
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	char str[] = "Banana";
// 	char *sep = "a";
// 	char **res = ft_split(str, sep);
// 	int i =0;
// 	while (res[i])
// 	{
// 		printf("[%d]: %s\n", i,res[i]);
// 		i++;
// 	}
// }