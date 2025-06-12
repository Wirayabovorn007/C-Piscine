#include <stdio.h> //for testing

int atoi(char *n)
{
	int ans = 0;
	int i = 0;
	while (n[i])
	{
		ans = ans * 10 + (n[i] - '0');
		i++;
	}
	return (ans);
}

int	pgcd(int n1, int n2)
{
	int i = n1;
	while (i > 0)
	{
		if (n1 % i == 0 && n2 % i == 0)
			return (i);
		i--;
	}
	return (1);
}

int main(int ac, char *av[])
{
	if (ac == 3)
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
}