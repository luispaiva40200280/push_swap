/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:38:44 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/03 02:11:48 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* find min && max nodes */
t_node	*find_min_node(t_node *lst)
{
	t_node	*min;

	min = NULL;
	while (lst)
	{
		if (!min || lst->value < min->value)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_node	*find_max_node(t_node *lst)
{
	t_node	*max;

	max = NULL;
	while (lst)
	{
		if (!max || lst->value > max->value)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

/* get the lst size dynamacly */
int	lst_size(t_node *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/* get the posision of a ceten node "target" */
int	get_pos(t_node **lst, t_node *target)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp == target)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
