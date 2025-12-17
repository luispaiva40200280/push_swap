/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:40:12 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/17 00:44:54 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_atol(char *str)
{
	long number;
	int i;
	int sign;
	 
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}else if (str[i] == '+')
		i++;
	number = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (number >= INT_MAX || number <= INT_MIN)
		return (ft_printf("error\n"), '\0');
	return (sign * number);
} 
