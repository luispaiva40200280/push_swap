/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:19 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/22 20:12:29 by lpaiva           ###   ########.fr       */
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

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (ft_printf("Error\n"), NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

t_node	*build_from_arr(int *arr, int size)
{
	t_node *head;
	t_node *current;
	int i;

	if (!arr || size <= 0)
		return (ft_printf("Error\n"), NULL);
	i = 0;
	head = create_node(*arr);
	if (head == (t_node *)NULL)
		return (ft_printf("Error\n"), NULL);
	current = head;
	while (i < size)
	{
		current->next = create_node(arr[i]);
		if (!current->next)
			return (free_list(head), NULL);
		current = current->next;
		i++;
	}
	ass_index(head);
	return (head);
}
