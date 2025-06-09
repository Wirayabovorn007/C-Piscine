/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:29:04 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/09 15:47:35 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	put_nbr(int nbr)
{
	char	t;
	long	n;

	n = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
	if (n < 10)
	{
		t = n + '0';
		write(1, &t, 1);
	}
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		put_str(par[i].str);
		write(1, "\n", 1);
		put_nbr(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
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
// 	ft_show_tab(res);
// 	free(res);
// 	free(str);
// }