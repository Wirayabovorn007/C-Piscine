/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:03:00 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/06/09 13:19:02 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN(nbr) ((nbr) % 2 == 0)
# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."

typedef int	t_bool;

#endif