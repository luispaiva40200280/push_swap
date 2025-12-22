/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:25:45 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/22 20:39:06 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	sort_3(t_node **lst)
{
	int	first;
	int	scond;
	int	third;
	
	first = (*lst)->index;
	scond = (*lst)->next->index;
	third = (*lst)->next->next->index;
	
	if (first > scond && scond < third && first < third)
		sa(lst, 1);
}
void	sort_5(t_node **lst)
{
	
}