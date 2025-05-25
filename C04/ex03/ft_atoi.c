/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:48:39 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/26 00:57:20 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_if_it_a_sign(int i, char *str, int *j)
{
	if (str[i] == '-')
		*j *= -1;
	if (str[i] == ' ' || (!(str[i] >= '0' && str[i] <= '9')
			|| !((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z'))))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if (check_if_it_a_sign(i, str, j) == 1)
			i++;
		if (str[i] >= '0' && str[i] <= '9')
	}
}