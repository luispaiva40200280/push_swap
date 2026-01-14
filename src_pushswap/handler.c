/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:24:09 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/06 19:51:03 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issort(t_node **lst_a)
{
	t_node	*tmp;

	tmp = *lst_a;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	handler_sort_type(t_node **lst_a)
{
	t_node	*lst_b;
	int		size;

	lst_b = NULL;
	size = lst_size(*lst_a);
	if (size == 1 || ft_issort(lst_a))
		return ;
	else if (size <= 3)
		sort_lst_3(lst_a);
	else if (size <= 5)
		sort_lst_5(lst_a, &lst_b);
	else
		butterfly_sort(lst_a, &lst_b, size);
}
