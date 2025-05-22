/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:16:46 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/05/22 12:08:56 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void write_char(char i){
	write(1, &i, 1);
}


void	ft_putnbr(int nb)
{
	char result;
	int right_num;
	if(nb < 0){
		write_char('-');
		nb = nb * -1;
	}
	if(nb > 9){
		right_num = nb % 10;
		nb = nb / 10;
		ft_putnbr(nb);
		ft_putnbr(right_num);
	}else{
		result = nb + '0';
		write_char(result);
	}
}
