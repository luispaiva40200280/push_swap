/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:25 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/15 19:41:24 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this main will be use for testting the code 
#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return 0;
	else if (ac == 2)
	{
		char	**n_char; 
		int		i; 
		//int		**numbres;
		
		n_char = ft_split(av[1], ' ');
		i = -1;
		while (n_char[i++])
			printf("%s", n_char[i]);
	}
	return (0);
	
}