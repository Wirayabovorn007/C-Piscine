#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	size;
	int	*res;

	i = 0;
	size = end - start + 1;
	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	//printf("Memory allocated!");
		while (start < end)
		res[i++] = start++;
	res[i] = end;
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	int *num = ft_range(0, 100);
// 	int i =0;
// 	while (i <= 100)
// 	{
// 		printf("%d ", num[i]);
// 		i++;
// 	}
// }