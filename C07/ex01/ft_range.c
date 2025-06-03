/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:37:12 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/03 14:40:04 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc((max - min + 1) * sizeof(int));
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int main()
// {
// 	int max = 100;
// 	int min = 0;
// 	int *num = ft_range(min, max);
// 	int i =0;
// 	while (i < max - min)
// 	{
// 		printf("%d ", num[i]);
// 		i++;
// 	}
// 	free(num);
// }