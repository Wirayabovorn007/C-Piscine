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
	while (*str)
	{
		if (is_sep(*str, charset))
			str++;
		else
		{
			start = str;
			while (*str && !is_sep(*str, charset))
			{
				str++;
				len++;
			}
			res[i++] = word_dup(start, len);
			len = 0;
		}
	}
	res[i] = NULL;
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	char str[] = "aaaa";
// 	char *sep = "";
// 	char **res = ft_split(str, sep);
// 	int i =0;
// 	while (res[i])
// 	{
// 		printf("[%d]: %s\n", i,res[i]);
// 		i++;
// 	}
// }