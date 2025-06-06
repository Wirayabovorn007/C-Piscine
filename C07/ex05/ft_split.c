#include <stdlib.h>

int	len(char *c)
{
	int	i;
	
	i = 0;
	while(c[i])
		i++;
	return (i);
}

int	check(char *str, char *ch, int i)
{
	int d;

	d = 0;
	while (ch[d])
		if (str[i++] != ch[d++])
			return (0);
	return (1);
}

int	count_word(char *str, char *ch)
{
	int c;
	int	i;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (check(str, ch, i))
		{
			c += 1;
			i += len(ch);
			continue ;
		}
		i++;
	}
	return (c);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		c;
	int		i;
	int		j;
	int		l;
	char	*temp;
	char	**result;

	i = 0;
	l = 0;
	c = count_word(str, charset);
	result = malloc(sizeof(char *) * (c + 1));
	if (!result)
		return (NULL);
	temp = malloc(sizeof(char) * (c + 1));
	while (i < c - 1)
	{
		j = i;
		while (!check(str, charset, j++))
		{
			temp = realloc(temp, len(str[j]));
			temp[l++] = str[j];
		}
		result[i] = malloc(sizeof(char) * len(temp));
		ft_strcpy(result[i], temp);
		i++;
	}
	return (result);
}