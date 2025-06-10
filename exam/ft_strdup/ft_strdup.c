
#include <stdlib.h>

int	len(char *c)
{
	int i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*dup;

	dup = malloc(sizeof(char) * (len(src) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dup);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
//     char *dulplicate = ft_strdup(argv[1]); 
//     printf("%s\n", dulplicate);
//     return 0;
// }