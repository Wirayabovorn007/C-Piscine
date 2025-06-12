#include <stdlib.h>

int is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int count_words(char *str, char *sep)
{
	int i =0;
	int in_word = 0;
	while (*str)
	{
		if (is_sep(*str, sep))
			in_word = 0;
		else
		{
			if (!in_word)
			{
				in_word = 1;
				i++;
			}
		}
		str++;
	}
	return (i);
}

char *word_dup(char *str, int len)
{
	char *dup = malloc(sizeof(char) * (len+1));
	if (!dup)
		return (NULL);
	int i =0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *sep)
{
	int i = 0;
	int words = count_words(str, sep);

	char **res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (i < words)
	{
		if (is_sep(*str, sep))
			str++;
		else
		{
			int len = 0;
			char *start = str;
			while (*str && !is_sep(*str, sep))
			{
				str++;
				len++;
			}
			res[i++] = word_dup(start, len);
		}
	}
	res[i] = NULL;
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	char str[] = "Ba-na-na";
// 	char *sep = "-";
// 	char **res = ft_split(str, sep);
// 	int i =0;
// 	while (res[i])
// 	{
// 		printf("[%d]: %s\n", i,res[i]);
// 		i++;
// 	}
// }