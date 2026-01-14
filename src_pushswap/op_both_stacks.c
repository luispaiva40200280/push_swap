/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:06:51 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/08 19:20:20 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_node **lst_a, t_node **lst_b, int print)
{
	sa(lst_a, 0);
	sb(lst_b, 0);
	if (print)
		ft_dprintf(1, "ss\n");
}

void	rr(t_node **lst_a, t_node **lst_b, int print)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	if (print)
		ft_dprintf(1, "rr\n");
}

void	rrr(t_node **lst_a, t_node **lst_b, int print)
{
	rra(lst_a, 0);
	rrb(lst_b, 0);
	if (print)
		ft_dprintf(1, "rrr\n");
}
