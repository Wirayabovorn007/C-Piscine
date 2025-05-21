/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:39:39 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/21 18:25:36 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <unistd.h>
#include <stdio.h>

void put_char(char n){
    char nbuf[20];
    const int len = snprintf(nbuf, sizeof(nbuf), "%d", n);
    write(1, &nbuf, len);
}

void put_char2(char n)
{
    write(1, &n, 1);
}


void ft_print_comb2(void){
    int i;
    int j;
    i=0;
    while( i <= 99){
        j = i;
        if(i<10)
        {
            put_char(0);
        }
        put_char(i);
        put_char2(' ');
        put_char(j);
        
        i++;
    }
    
}

int main(){
    ft_print_comb2();
}