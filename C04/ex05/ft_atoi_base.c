/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:07:19 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/29 15:47:10 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	j;
	int	i;

	i = -1;
	if (len(base) < 2)
		return (0);
	while (++i < len(base))
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < len(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (len(base));
}

int	power(int num, int expo)
{
	int	i;
	int	j;

	i = 1;
	j = num;
	if (expo == 0)
		return (1);
	while (i < expo)
	{
		j *= num;
		i++;
	}
	return (j);
}
int	convert_char_base_to_nbr(char str, int base)
{
	int	res;

	if (len(base) == 16 && )
}

int	convert_to_decimal(char *str, char *base)
{
	int	i;
	int	t;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		t = str[i];
		if (!(t <= '9' && t >= '0'))
		{
			t = convert_char_base_to_nbr(t, len(base));
			sum += t * power(len(base), i);
		}
		else
			sum += (t - '0') * power(len(base), i);
		i++;
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b;
	int	result;

	b = check_base(base);
	if (!b)
		return (0);
	result = convert_to_decimal(str, base);
}
