/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:50:23 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/28 15:26:29 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_substr(char *str, char *to_find, int *ind)
{
	int	i;
	int	k;

	i = 0;
	k = ind;
	while (to_find[i] != '\0')
	{
		if (str[k] != to_find[i])
			return (0);
		k++;
		i++;
	}
	return (1);
}

char	len(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	change_val(char *str, int *ind)
{
	int		i;
	int		*k;
	char	*temp;

	i = 0;
	k = ind;
	temp = str;
	while (temp[k] != '\0')
	{
		str[i] = temp[k];
		i++;
		k++;
	}
	while (i < len(temp) - 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
			j = check_substr(str, to_find, &i);
		if (j)
			return (change_val(str, &i));
		i++;
	}
	return (str);
}
