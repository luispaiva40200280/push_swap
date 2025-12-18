/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:19 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/18 21:26:54 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this will be the core code of my program
//**** the creation of the linked list having the array as base;

#include "push_swap.h"

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

t_node	*create_node(int value, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (ft_printf("Error\n"), NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_node	*build_from_arr(int *arr, int size)
{
	t_node *head;
	t_node *current;
	int index;

	if (!arr || size <= 0)
		return (ft_printf("Error\n"), NULL);
	index = 0;
	head = create_node(*arr, index);
	if (head == (t_node *)NULL)
		return (ft_printf("Error\n"), NULL);
	current = head;
	while (index++ < size)
	{
		current->next = create_node(arr[index], index);
		if (!current->next)
			return (free_list(head), ft_printf("Error\n"), NULL);
		current = current->next;
	}
	return (head);
}