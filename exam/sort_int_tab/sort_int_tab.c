

void	sort_int_tab(int *tab, unsigned int size)
{
	int i =0;
	int j;
	int temp;
	int min_ind;
	while (i < size)
	{
		min_ind = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_ind])
				min_ind = j;
			j++;
		}
		temp = tab[i];
		tab[i]= tab[min_ind];
		tab[min_ind] = temp;
		i++;
	}
}

// #include <stdio.h>
// int	main()
// {
// 	int arr[] = {3, 4, 5, 99, 2, 0, -9};
// 	sort_int_tab(arr, 7);
// 	int i = -1;
// 	while (++i < 7)
// 		printf("[%d]: %d\n", i, arr[i]);
// }