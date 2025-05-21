/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:21 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/21 12:43:38 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void ft_print_numbers(void){
    char num = '0';
    while (num <='9'){
        write(1, &num, 1);
        num++;
    }
}

// int main(){
//     ft_print_numbers();
// }