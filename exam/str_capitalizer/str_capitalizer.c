#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 1;
	char c;
	char p;

	if (argc < 2)
		return (1);
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
			{
				write(1, &c, 1);
				j++;
				continue ;
			}
			if ((c >= 'a' && c <= 'z') && j == 0)
				c -= 32;
			if (j > 0)
			{
				p = argv[i][j - 1];
				if (p == ' ' && (c >= 'a' && c <= 'z'))
					c -= 32;
				if (p != ' ' && (c >= 'A' && c <= 'Z'))
					c += 32;
			}
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}