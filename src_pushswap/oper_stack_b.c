/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 02:22:32 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/03 02:11:13 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*  */
void	sb(t_node **lst, int print)
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
		ft_dprintf(1, "sb\n");
}

/*  */

void	rb(t_node **lst, int print)
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
		ft_dprintf(1, "rb\n");
}

void	rrb(t_node **lst, int print)
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
		ft_dprintf(1, "rrb\n");
}

/*  */
void	pb(t_node **lst, t_node **lst_b, int print)
{
	t_node	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	if (print)
		ft_dprintf(1, "pb\n");
}
