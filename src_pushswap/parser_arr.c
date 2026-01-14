/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:35:44 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/09 21:00:59 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_number_arr(long *numbers, int size, long value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	arr_size(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long	*init_arr(char **av, long *arr_nbrs, int size)
{
	long	value;
	int		i;

	if (size <= 0)
		return (NULL);
	arr_nbrs = (long *)malloc(sizeof(long) * size);
	if (!arr_nbrs)
		return (NULL);
	i = 0;
	while (i < size)
	{
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (free(arr_nbrs), NULL);
		arr_nbrs[i] = value;
		if (find_number_arr(arr_nbrs, i, value))
			return (free(arr_nbrs), NULL);
		i++;
	}
	return (arr_nbrs);
}
