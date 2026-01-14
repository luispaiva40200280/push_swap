/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:41:53 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/30 21:33:08 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putnbr_base(long nbr, char *base, int size, int fd)
{
	int		count;
	int		i;
	char	digit[65];

	count = 0;
	i = 0;
	if (nbr == 0)
		return (write(fd, "0", 1), ++count);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		digit[i++] = base[nbr % size];
		nbr /= size;
	}
	count += i;
	while (i > 0)
		write(fd, &digit[--i], 1);
	return (count);
}

int	ft_putnbr_base_uns(unsigned long nbr, char *base, int size, int fd)
{
	int	count;

	count = 0;
	if (nbr >= (unsigned long)size)
		count = ft_putnbr_base_uns(nbr / size, base, size, fd);
	count = ft_putchar(base[nbr % size], count, fd);
	return (count);
}

int	ft_ptptr(void *ptr, int count, int fd)
{
	if ((unsigned long)ptr == 0)
		return (write(fd, "(nil)", 5), count + 5);
	count = ft_putstr("0x", count, fd);
	count = ft_putnbr_base_uns((unsigned long)ptr, "0123456789abcdef", 16,
			count);
	return (count);
}
