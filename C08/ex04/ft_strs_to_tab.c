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

char	*dup(char *src)
{
	int		i = 0;
	char	*copy;

	copy = malloc(len(src) + 1);
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*arr;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = len(av[i]);
		arr[i].str = av[i];
		arr[i].copy = dup(av[i]);
		if (!arr[i].copy)
			return (NULL);
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
// 	str[1] = "Banana";
// 	str[2] = malloc(sizeof(char) * 10);
// 	str[2] = "qwe-ert-tyu";
// 	t_stock_str *res = ft_strs_to_tab(size, str);
// 	int i = 0;
// 	while (i < size)
// 	{
// 		printf("\nelement: %d\nsize: %d\nstr: %s\ncopy: %s\n",i ,
// res[i].size, res[i].str, res[i].copy);
// 		printf("--------------------------------\n");
// 		i++;
// 	}
// 	free(res);
// 	free(str);
// }