/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:04 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/10 12:44:02 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	int	*arr;
// 	int	size;
// 	int min = 0;
// 	int max = 23;
// 	int	i = -1;
// 	size = ft_ultimate_range(&arr, min, max);
// 	printf("Range (%d to %d): ", min, max);
// 	while (++i < size)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// 	free(arr);
// }