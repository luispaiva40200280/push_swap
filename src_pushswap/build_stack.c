/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:01:38 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/03 03:01:57 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*find_min_un(t_node *lst)
{
	t_node	*min;

	min = NULL;
	while (lst)
	{
		if (lst->index == -1 && (!min || lst->value < min->value))
			min = lst;
		lst = lst->next;
	}
	return (min);
}

static void	index_assigned(t_node *lst)
{
	int		index;
	t_node	*min;

	index = 0;
	min = NULL;
	while (1)
	{
		min = find_min_un(lst);
		if (!min)
			break ;
		min->index = index;
		index++;
	}
}

void	free_stack(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

static t_node	*create_node(long value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = (int)value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

t_node	*init_stack_a(long *arr_nbrs, int size)
{
	t_node	*head;
	t_node	*current;
	int		i;

	if (!arr_nbrs || size <= 1)
		return (NULL);
	head = create_node(*arr_nbrs);
	if (head == NULL)
		return (NULL);
	i = 1;
	current = head;
	while (i < size)
	{
		current->next = create_node(arr_nbrs[i]);
		if (!current->next)
			return (free(arr_nbrs), free_stack(head), NULL);
		current = current->next;
		i++;
	}
	index_assigned(head);
	return (free(arr_nbrs), head);
}
