/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:54:00 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/09 15:42:49 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	cpy(char *src, char *dup1, char *dup2)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dup1[i] = src[i];
		dup2[i] = src[i];
		i++;
	}
	dup1[i] = 0;
	dup2[i] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	int				strlen;
	unsigned long	size;
	t_stock_str		*arr;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		strlen = len(av[i]);
		size = sizeof(char) * (strlen + 1);
		arr[i].size = size;
		arr[i].str = malloc(sizeof(char) * size);
		if (!arr[i].str)
			return (NULL);
		arr[i].copy = malloc(sizeof(char) * size);
		if (!arr[i].copy)
			return (NULL);
		cpy(av[i], arr[i].str, arr[i].copy);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

// #include <stdio.h>
// int	main()
// {
// 	char **str;
// 	int size = 3;
// 	str = malloc(sizeof(char *) * size);
// 	str[0] = malloc(sizeof(char) * 4);
// 	str[0] = "ABC";
// 	str[1] = malloc(sizeof(char) * 7);
// 	str[1] = "asdfhj";
// 	str[2] = malloc(sizeof(char) * 10);
// 	str[2] = "qwe-ert-tyu";
// 	t_stock_str *res = ft_strs_to_tab(size, str);
// 	int i = 0;
// 	while (i < size)
// 	{
// 		printf("element: %d\nsize: %d\nstr: %s\ncopy: %s\n",i ,
// res[i].size, res[i].str, res[i].copy);
// 		printf("--------------------------------\n");
// 		i++;
// 	}
// 	free(res);
// 	free(str);
// }