/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:24:42 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/28 11:40:37 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

// #include <stdio.h>

// int	main()
// {
// 	char s1[] = "abcpp";
// 	char s2[] = "abcde";
// 	unsigned int n = 3;
// 	int cmp = ft_strncmp(s1, s2, n);
// 	if (cmp > 0) {
// 		printf("%s is greater than %s\n", s1, s2);
// 	  } else if (cmp < 0) {
// 		printf("%s is greater than %s\n", s2, s1);
// 	  } else {
// 		printf("%s is equal to %s\n", s1, s2);
// 	  }
// }