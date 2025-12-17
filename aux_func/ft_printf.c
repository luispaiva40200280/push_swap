/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:15:33 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/17 02:45:25 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(char *str, int count, int fd)
{
	int len;
	
	len = 0;
	while(str[len])
		write(fd, &str[len++], 1);
	return (count + len);
}

int	ft_handler(const char flag, va_list args ,int count)
{ 
	if (flag == 'c')
		count = ft_putchar(va_arg(args, int), count);
    else if (flag == 's')
		count = ft_putstr(va_arg(args, char *), count, 2);
	else if (flag == 'd' || flag == 'i')
		count = ft_putnbr_base((long long)va_arg(args, int), "0123456789", 10, count);
	else if (flag == 'u')
		count = ft_putnbr_base_uns((unsigned long long)va_arg(args, unsigned int), "0123456789", 10, count);
	else if (flag == 'x')
		count = ft_putnbr_base_uns((unsigned long long)va_arg(args, unsigned int), "0123456789abcdef", 16, count);
	else if (flag == 'X')
		count = ft_putnbr_base_uns((unsigned long long)va_arg(args, unsigned int), "0123456789ABCDEF", 16, count);
	else if (flag == 'p')
		count = ft_ptptr(va_arg(args, void *), count);
	else if (flag == '%')
		count = ft_putchar('%', count);
	return (count);
}
int ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int 	count;

	i = 0;
	count = 0;
	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count = ft_handler(format[++i], args, count);
		else
		{
			write(1, &format[i], 1);		
			count++;	
		}
		i++;
	}
	va_end(args);
	return (count);
}
