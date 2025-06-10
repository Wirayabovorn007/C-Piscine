

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;
	int	digit_found;

	i = 0;
	res = 0;
	sign = 1;
	digit_found = 0;
	while (str[i])
	{
		if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) && digit_found)
			break ;
		if (str[i] == '-')
		sign *= -1;
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			digit_found = 1;
			res = res * 10 + (str[i] - '0');
		}
		i++;
	}
	return (res * sign);
}


// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_atoi("---42"));
// }