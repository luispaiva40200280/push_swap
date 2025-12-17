/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:54:49 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/17 01:36:30 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int 	ft_putnbr_base(long long nbr, char *base, int base_zise, int count)
{
	char digits[65];
	int i;
	if (nbr == 0)
		return (write(1, "0", 1), count++);
	if (nbr < 0)
	{
		write(1, "0", 1);
		nbr = -nbr;
		count++;
	}
	i = 0;
	while (nbr > 0)
	{
		digits[i++] = base[nbr % base_zise];
		nbr /= base_zise;
	}
	while (i >= 0)
	{
		write(1, &digits[i--], 1);
		count++;
	}
	return (count);	 
}
int 	ft_putnbr_base_uns(unsigned long long nbr, char *base, int base_zise, int count)
{
	char digits[65];
	int i;
	
	if (nbr == 0)
		return (write(1, "0", 1), count++);
	i = 0;
	while (nbr > 0)
	{
		digits[i++] = base[nbr % base_zise];
		nbr /= base_zise;
	}
	while (i >= 0)
	{
		write(1, &digits[i--], 1);
		count++;
	}
	return (count);	 
}

int ft_ptptr(void *ptr, int count)
{
	if ((unsigned long)ptr == 0)
		return (write(1, "(nil)", 5), count);
	write(1, "0x", 2);
	count += 2;
	count = ft_putnbr_base_uns((unsigned long)ptr, "0123456789abcdef", 16, count);
	return (count);

}
