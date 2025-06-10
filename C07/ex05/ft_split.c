/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:52:23 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/10 15:12:01 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int	is_sep(char *sep, char *str, int ind)
{
	int	i;

	i = -1;
	while (sep[++i])
		if (str[ind + i] != sep[i])
			return (-1);
	return (1);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_sep(sep, str, i))
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
			i++;
		}
		else
		{
			in_word = 0;
			i += len(sep);
		}
	}
	return (count);
}

char	*find_word(char *str, char *sep, int *ind)
{
	int		i;
	int		start;
	int		sep_len;
	int		length;
	char	*word;

	length = 0;
	sep_len = len(sep);
	while (str[*ind] && is_sep(sep, str, *ind))
		*ind += sep_len;
	start = *ind;
	while (str[*ind] && !is_sep(sep, str, *ind))
	{
		(*ind)++;
		length++;
	}
	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < length)
		word[i] = str[start + i];
	word[length] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		ind;
	int		words;
	char	**res;

	words = count_words(str, charset);
	res = malloc(sizeof(char *) * words + 1);
	if (!res)
		return (NULL);
	i = 0;
	ind = 0;
	while (i < words)
	{
		res[i] = find_word(str, charset, &ind);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

// #include <stdio.h>
// void free_split(char **arr)
// {
// 	if (!arr)
// 		return;
// 	for (int i = 0; arr[i]; i++)
// 		free(arr[i]);
// 	free(arr);
// }
// int main(void)
// {
// 	char *input = "hello<br>world<br>123<br>goodbye";
// 	char *sep = "<br>";
// 	char **result = ft_split(input, sep);	
// 	if (!result)
// 	{
// 		printf("Split failed.\n");
// 		return 1;
// 	}	
// 	printf("Split result:\n");
// 	for (int i = 0; result[i]; i++)
// 	{
// 		printf("  [%d]: \"%s\"\n", i, result[i]);
// 	}
// 	free_split(result);	
// 	return 0;
// }