#include <unistd.h>

int	didnot_print(char *s1, int ind, char c)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		if (s1[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	solve(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i] && didnot_print(s1, i, s1[i]))
			{
				write(1, &s1[i], 1);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		solve(argv[1], argv[2]);
	write(1, "\n", 1);
}
