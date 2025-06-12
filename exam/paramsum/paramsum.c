#include <unistd.h>

void put_nbr(int num)
{
	long 	n;
	char	number;

	n = num;
	if (num >= 10)
	{
		put_nbr(num / 10);
		put_nbr(num % 10);
	}
	else
	{
		number = num + '0';
		write(1, &number, sizeof(number));
	}
}

int len_arr(char **arr)
{
	int i =0;
	while (arr[i])
		i++;
	return (i);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "0", 1);
		return (0);
	}
	put_nbr(len_arr(argv) - 1);
	write(1, "\n", 1);
}