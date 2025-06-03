/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:54:25 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/03 13:43:26 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	char	*str_offset;

	str = malloc(len(src) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str_offset = str;
	while (*src)
	{
		*str_offset = *src;
		str_offset++;
		src++;
	}
	*str_offset = '\0';
	return (str);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
//     char *dulplicate = ft_strdup(argv[1]); 

//     printf("%s", dulplicate);
//     return 0;
// }