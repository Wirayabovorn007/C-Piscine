#include <stdlib.h>

int	get_nbrlen(int n)
{
	int len = (n <= 0)? 1:0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char *rev_str(char *str, int len)
{
	char temp;
	int i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len -1 -i];
		str[len -1 -i] = temp;
		i++;
	}
	return (str);
}

char *convert(long n, int len)
{
	char *str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	int is_negative = (n < 0)? 1:0;
	if (is_negative)
		n = -n;
	int i = 0;
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	return (rev_str(str, i));
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int nbr_l = get_nbrlen(n);
	if (n == 0)
		return ("0");
	if (n == 2147483647)
		return ("2147483647");
	if (n == -2147483648)
		return ("-2147483648");
	return (convert(n, nbr_l));
}

// #include <stdio.h>
// int main(int argc, char* argv[])
// {
// 	printf("%s\n", ft_itoa(1240108));
// }