/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:22:58 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/28 11:40:43 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// #include <stdio.h>

// int	main()
// {
// 	char s1[] = "abc";
// 	char s2[] = "cba";
// 	int cmp = ft_strcmp(s1, s2);
// 	if (cmp > 0) {
// 		printf("%s is greater than %s\n", s1, s2);
// 	  } else if (cmp < 0) {
// 		printf("%s is greater than %s\n", s2, s1);
// 	  } else {
// 		printf("%s is equal to %s\n", s1, s2);
// 	  }
// }