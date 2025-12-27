/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:25:45 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/27 00:04:20 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	sort_3(t_node **lst)
{
	int	first;
	int	scond;
	int	third;

	if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
		return ;
	first = (*lst)->index;
	scond = (*lst)->next->index;
	third = (*lst)->next->next->index;
	if (first > scond && scond < third && first < third)
		sa(lst, 1);
	else if (first > scond && scond > third)
		sa(lst, 1);
	else if (first > scond && scond < third && first > third)
		ra(lst, 1);
	else if (first < scond && scond > third && first < third)
	{
		sa(lst, 1);
		ra(lst, 1);
	}
	else if (first < scond && scond > third && first > third)
		rra(lst, 1);
}

static void	push_small_b(t_node **lst, t_node **lst_b)
{
	t_node *tmp;
	int		min;
	int		pos;
	int 	i;
	int size;

	size = lst_size(*lst);
	tmp = *lst;
	min = tmp->index;
	pos = 0; 
	i = 0; 
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (pos <= lst_size(*lst) / 2)
		while (pos-- > 0)
			ra(lst, 1);
	else
	{
		int r = size - pos; 
		while (r > 0)
		{
			rra(lst, 1);
			r--;
		}
	}
	pb(lst, lst_b, 1);	
}

void	sort_5(t_node **lst, t_node **lst_b)
{
	int	size;
	
	size = lst_size(*lst);
	while (size > 3)
	{	
		push_small_b(lst, lst_b);
		size--;
	}	
	sort_3(lst);
	while (*lst_b)
		pa(lst, lst_b, 1);
}
