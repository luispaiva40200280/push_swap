/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:17:08 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/30 21:52:07 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putchar(char c, int count, int fd)
{
	write(fd, &c, 1);
	return (++count);
}

int	ft_putstr(char *str, int count, int fd)
{
	while (*str)
		count = ft_putchar(*str++, count, fd);
	return (count);
}

int	handler_dprintf(const char f, va_list args, int count, int fd)
{
	if (f == 'c')
		count = ft_putchar(va_arg(args, int), count, fd);
	else if (f == 's')
		count = ft_putstr(va_arg(args, char *), count, fd);
	else if (f == 'd' || f == 'i')
		count += ft_putnbr_base((long)va_arg(args, int), "0123456789", 10, fd);
	else if (f == 'u')
		count += ft_putnbr_base_uns((unsigned long)va_arg(args, unsigned int),
				"0123456789", 10, fd);
	else if (f == 'x')
		count += ft_putnbr_base_uns((unsigned long)va_arg(args, unsigned int),
				"0123456789abcdef", 16, fd);
	else if (f == 'X')
		count += ft_putnbr_base_uns((unsigned long)va_arg(args, unsigned int),
				"0123456789ABCDEF", 16, fd);
	else if (f == 'p')
		count = ft_ptptr(va_arg(args, void *), count, fd);
	else if (f == '%')
		count = ft_putchar('%', count, fd);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count = handler_dprintf(format[++i], args, count, fd);
		else
		{
			write(fd, &format[i], 1);
			count++;
		}
		i++;
	}
	return (va_end(args), count);
}
