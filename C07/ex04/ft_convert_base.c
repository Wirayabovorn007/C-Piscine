/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:18:02 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/07 12:05:28 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *c);
int	check_base(char *base);
int	ft_atoi_base(char *nb, char *base);

int	get_nbr_len(long n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*put_nbr_base(int nb, char *base)
{
	char	*res;
	int		len_nb;
	long	n;

	n = nb;
	len_nb = get_nbr_len(n, len(base));
	res = malloc(sizeof(char) * (len_nb + 1));
	if (!res)
		return (NULL);
	res[len_nb] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
		res[0] = base[0];
	while (n > 0)
	{
		res[--len_nb] = base[n % len(base)];
		n /= len(base);
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	decimal;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	decimal = ft_atoi_base(nbr, base_from);
	return (put_nbr_base(decimal, base_to));
}

// #include <stdio.h>

// int	main()
// {
// 	char decimal[] = "0123456789";
// 	char binary[] = "01";
// 	char hexadecimal[] = "0123456789ABCDEF";
// 	char octal[] = "poneyvif";
// 	printf("%s", ft_convert_base("-1111000", binary, decimal)); //-120
// }