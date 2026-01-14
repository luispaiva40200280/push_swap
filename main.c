/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:03:03 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/09 21:04:28 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* debuging  */
void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	ft_dprintf(1, "List: ");
	while (current)
	{
		ft_dprintf(1, "[value:  %d, index: %d] -> ", current->value,
			current->index);
		current = current->next;
	}
	ft_dprintf(1, "NULL\n");
}
/* ------------------------- */

int	main(int ac, char **av)
{
	t_node	*lst_a;
	long	*arr_nbrs;
	int		size;

	lst_a = NULL;
	arr_nbrs = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av++;
	size = arr_size(av);
	arr_nbrs = init_arr(av, arr_nbrs, size);
	if (!arr_nbrs)
	{
		if (ac == 2)
			free_mem(av, (size_t)size);
		return (ft_dprintf(2, "Error\n"), 1);
	}
	lst_a = init_stack_a(arr_nbrs, size);
	handler_sort_type(&lst_a);
	if (ac == 2)
		free_mem(av, (size_t)size);
	return (free_stack(lst_a), 0);
}
