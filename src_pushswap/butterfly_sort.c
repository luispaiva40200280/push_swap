/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:30:53 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/03 02:12:06 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_b_in_chunks(t_node **lst_a, t_node **lst_b, int size_a)
{
	int	chunk;
	int	count;

	count = 0;
	if (size_a <= 100)
		chunk = 15;
	else
		chunk = 35;
	while (*lst_a)
	{
		if ((*lst_a)->index <= count)
		{
			pb(lst_a, lst_b, 1);
			rb(lst_b, 1);
			count++;
		}
		else if ((*lst_a)->index <= count + chunk)
		{
			pb(lst_a, lst_b, 1);
			count++;
		}
		else
			ra(lst_a, 1);
	}
}

static void	move_max_top(t_node **lst_b, t_node *max, int size)
{
	int	pos;

	pos = get_pos(lst_b, max);
	if (pos == 1)
		return (sb(lst_b, 1));
	if (pos <= size / 2)
		while (*lst_b != max)
			rb(lst_b, 1);
	else
		while (*lst_b != max)
			rrb(lst_b, 1);
}

void	butterfly_sort(t_node **lst_a, t_node **lst_b, int size_a)
{
	t_node	*max;

	push_b_in_chunks(lst_a, lst_b, size_a);
	while (*lst_b)
	{
		max = find_max_node((*lst_b));
		if (lst_size(*lst_b) > 1 && (*lst_b)->index == (max->index - 1))
		{
			pa(lst_a, lst_b, 1);
			move_max_top(lst_b, max, lst_size(*lst_b));
			pa(lst_a, lst_b, 1);
			sa(lst_a, 1);
		}
		else
		{
			move_max_top(lst_b, max, lst_size(*lst_b));
			pa(lst_a, lst_b, 1);
		}
	}
}
