#include <unistd.h>

int ft_atoi(char *s)
{
	long r;
	int sign;
	while (*s == 32 || (*s >= 9 && *s <=13))
		s++;
	sign = (*s == '-')? -1 : 1;
	(*s == '-' || *s == '+')? s++ : s;
	r = 0;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return ((int)r * sign);
}

void print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}