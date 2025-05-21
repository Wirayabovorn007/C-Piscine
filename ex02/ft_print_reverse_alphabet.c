/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:12 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/21 12:43:27 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_print_reverse_alphabet(void){
    char letter = 'z';
    while(letter != 'a'-1){
        write(1, &letter, 1);
        letter--;
    }
}

// int main(){
//     ft_print_reverse_alphabet();
// }