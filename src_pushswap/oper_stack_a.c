/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:18:15 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/03 02:10:30 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swap operations for stack a */

/* Swap the first 2 elements at the top of stack a. */
void	sa(t_node **lst, int print)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = *lst;
	*lst = second;
	if (print)
		ft_dprintf(1, "sa\n");
}

/* Shift up all elements of stack a by 1 */
void	ra(t_node **lst, int print)
{
	t_node	*first;
	t_node	*last;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	if (print)
		ft_dprintf(1, "ra\n");
}

/* Shift down all elements of stack a by 1. */
void	rra(t_node **lst, int print)
{
	t_node	*prev;
	t_node	*last;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
	if (print)
		ft_dprintf(1, "rra\n");
}

/*Take the first element at the top of b and put it at the top of a.*/
void	pa(t_node **lst, t_node **lst_b, int print)
{
	t_node	*tmp;

	if (!lst_b || !(*lst_b))
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = *lst;
	*lst = tmp;
	if (print)
		ft_dprintf(1, "pa\n");
}
