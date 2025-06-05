/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:54:04 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/05 10:07:54 by wiboonpr         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_size(char **arr, char *sep, int size)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (arr[i])
		total += len(arr[i++]);
	total += len(sep) * (size - 1);
	return (total);
}

char	*return_size_zero(void)
{
	char	*result;

	result = malloc(1);
	result[0] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ptr;
	char	*result;

	if (size == 0)
		return (return_size_zero());
	result = malloc((total_size(strs, sep, size) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ptr = result;
	i = 0;
	while (i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += len(strs[i]);
		if (i < size -1)
		{
			ft_strcpy(ptr, sep);
			ptr += len(sep);
		}
		i++;
	}
	*ptr = '\0';
	return (result);
}

// #include <stdio.h>
// int	main(int argc, char * argv[])
// {
// 	char *sep = " | ";
// 	char *joined = ft_strjoin(argc - 1, argv + 1, sep);
// 	if (joined)
// 	{
// 		printf("%s", joined);
// 		free(joined);
// 	}
// }