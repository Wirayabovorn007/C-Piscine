/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:18:02 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/05 12:16:00 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	to_base_ten(char *nb, char *base);
int	check_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	num = to_base_ten(nbr, base_from);
}
