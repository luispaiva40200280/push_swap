/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_smaller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:38:18 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/08 23:32:38 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Logic ::
	find the biggest node and see if it is the 1st 2st node
	if so do ra || rra for the respected case
*/
void	sort_lst_3(t_node **lst_a)
{
	t_node	*biggest_node;

	biggest_node = find_max_node(*lst_a);
	if (biggest_node == *lst_a)
		ra(lst_a, 1);
	else if ((*lst_a)->next == biggest_node)
		rra(lst_a, 1);
	if ((*lst_a)->index > (*lst_a)->next->index)
		sa(lst_a, 1);
}

/* Logic::
	reduce the stack a to 3 nbrs and sorted it usind the logic for 3
	and sort the stack b if need it 
*/
static void	rotate_to_top(t_node **lst, t_node *min, int size)
{
	int	pos;
	int	rev;

	pos = get_pos(lst, min);
	rev = size - pos;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(lst, 1);
	else
		while (rev-- > 0)
			rra(lst, 1);
}

void	sort_lst_5(t_node **lst_a, t_node **lst_b)
{
	t_node	*min;

	while (lst_size(*lst_a) > 3)
	{
		min = find_min_node(*lst_a);
		rotate_to_top(lst_a, min, lst_size(*lst_a));
		pb(lst_a, lst_b, 1);
	}
	sort_lst_3(lst_a);
	if ((*lst_b)->index && ((*lst_b)->index < (*lst_b)->next->index))
		sb(lst_b, 1);
	while (*lst_b)
		pa(lst_a, lst_b, 1);
}
