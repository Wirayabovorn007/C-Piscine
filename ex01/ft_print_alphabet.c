/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:03 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/21 12:43:15 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void ft_print_alphabet(void){
    char letter;
    letter = 'a';
    while (letter <= 'z'){
        write(1, &letter, 1);
        letter++;
    }
}
