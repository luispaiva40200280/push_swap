/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:25:45 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/28 22:43:21 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void sort_3(t_node **lst)
{
	t_node *big_node;

	big_node = find_bigest_node(*lst);
	if (big_node == *lst)
		ra(lst, 1);
	else if ((*lst)->next == big_node)
		rra(lst,1);
	if ((*lst)->index > (*lst)->next->index)
		sa(lst,1);
}


void	rotate_to_top(t_node **a, t_node *target)
{
	int	pos;
	int	size;
	int	rev;

	pos = get_pos(*a, target);
	size = lst_size(*a);
	rev = size - pos;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a, 1);
	else
		while (rev-- > 0)
			rra(a, 1);
			
}


void	push_small_b(t_node **lst, t_node **lst_b)
{
	t_node	*min;
	int		pos;
	int 	size;

	min = find_min_node(*lst);
	rotate_to_top(lst, min);
	pb(lst, lst_b, 1);	
}

void	sort_5(t_node **lst, t_node **lst_b)
{
	t_node	*min;

	while (lst_size(*lst) > 3)
	{
		min = find_min_node(*lst);
		//print_list(*lst_b);
		rotate_to_top(lst,min);
		pb(lst, lst_b, 1);
	}	
	sort_3(lst);
	//print_list(*lst);
    if ((*lst_b)->index < (*lst_b)->next->index)
        sa(lst_b, 1);
	while (*lst_b)
		pa(lst, lst_b, 1);
	//print_list(*lst); 
}
