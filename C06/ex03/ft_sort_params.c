/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:23:03 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/03 10:05:04 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	selection_sort(char *arr[], int n)
{
	int		i;
	int		j;
	int		min_ind;
	char	*temp;

	i = 1;
	while (i < n)
	{
		min_ind = i;
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(arr[j], arr[min_ind]) < 0)
				min_ind = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min_ind];
		arr[min_ind] = temp;
		i++;
	}
}

void	print_arr(char *arr[], int c)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (arr[i][j])
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	selection_sort(argv, argc);
	print_arr(argv, argc);
}
