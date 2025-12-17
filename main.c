/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:25 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/17 01:35:56 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this main will be use for testting the code 
#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return(ft_printf("Error\n"), 0);
	else if (ac == 2)
	{
		char	**n_char; 
		int		*nbrs;
		int 	value;
		int		i; 
		
		n_char = ft_split(av[1], ' ');
		if (!n_char)
			return (ft_printf("error\n"), 0);
		nbrs = malloc(sizeof(int) * ft_countwords((const char *)av[1], ' '));
		i = 0;
		/* while (n_char[i] )
		{
			ft_printf("%s", n_char[i]);
			i++;
		} */
		while (n_char[i])
		{
			value = ft_atol(n_char[i]);
			if (ft_find_number(nbrs, i , value))
				return (ft_printf("Error\n"), 0); //erro 
			nbrs[i++] = value;
			ft_printf("%d ", nbrs[i - 1]);
		}
		free(nbrs);
		free(n_char);
	}
	else if (ac > 2)
{
	int i = 1;
	int j = 0;
	int *nunb;

	nunb = malloc(sizeof(int) * (ac - 1));
	if (!nunb)
		return (1);

	while (i < ac)
	{
		nunb[j] = ft_atol(av[i]);
		if (nunb[j] == '\0')
			return (free(nunb),0);
		j++;
		i++;
	}

	j = 0;
	while (j < ac - 1)
	{
		//ft_printf("%d\n", nunb[j]);
		printf("%d ", nunb[j]);
		j++;
	}

	free(nunb);
}

	return (0);
}
