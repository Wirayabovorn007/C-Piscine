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

#include <stdio.h>

int check_substr(char *str, char *to_find, int *ind)
{
	int i = 0;
	int k = *ind;
	while (to_find[i] != '\0')
	{
		if (str[k] != to_find[i])
			return (0);
		k++;
		i++;
	}
	return (1);
}

char *ft_strstr(char *str, char *to_find)
{
	int i = 0;

	if (to_find[0] == '\0')
		return (str);

	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (check_substr(str, to_find, &i))
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char myStr[] = "The rain in Spain falls mainly on the plains";
// 	char *myPtr = ft_strstr(myStr, "nly");
// 	if (myPtr != NULL) {
// 	printf("%s", myPtr);
// 	}
// }