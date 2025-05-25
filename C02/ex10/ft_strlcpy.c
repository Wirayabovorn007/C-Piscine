/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:14:25 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/25 20:56:40 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len(src));
}
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char string[] = "Hello, World!";
//     char buffer[19];
//     int r;
// 	int q;

//     r = ft_strlcpy(buffer,string, 19);
//     printf("Copied '%s' into '%s', length %d",
//             string,
//             buffer,
//             r
//           );
// }