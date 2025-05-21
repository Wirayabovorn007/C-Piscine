/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:35 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/21 14:02:23 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <string.h>

void ft_putchar(char n){
    write(1, &n, 1);
}

void ft_print_comb(void){
    int i;
    int j;
    int k;
    for (i='0'; i <= '7'; i++){
        for (j='0'; j<='8'; j++){
            for (k='0'; k<='9'; k++){
                if(i < j && j<k){
                    ft_putchar(i);
                    ft_putchar(j);
                    ft_putchar(k);
                    if(!(i=='7' && j=='8' && k =='9')){
                        ft_putchar(',');
                        ft_putchar(' ');
                    }
                }
            }
        }
    }

}
