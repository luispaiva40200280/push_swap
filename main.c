/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:25 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/14 02:28:53 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// this main will be use for testting the code 

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac == 1)
		return 0;
	
	if (ac == 2)
	{
		char **stack = ft_split(av[1], ' ');
		if (!stack)
			return 0;
		int index = 0;
		int i = 0;
		while (stack[index])
		{
			int *nbrs[i++] = fr_atol(stack[index++]); 
		}
	}
	
}