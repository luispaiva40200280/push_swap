/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:16:00 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/23 23:32:14 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this will make the handler for my push_swap logic 
/*
t_node *a;    // pointer to first node
t_node **a;   // handle to MOVE the first node
*/

#include "../push_swap.h"

void	handler_sort(t_node **lst)
{
	t_node *lst_b;

	lst_b = NULL;
	//printf("lst_size = %d\n", lst_size(*lst));
	if (is_sort(lst))
		return ;
	else if (lst_size(*lst) <= 3)
		sort_3(lst);
	else if (lst_size(*lst) <= 6)
		sort_5(lst, &lst_b);
	else
		return ;

}
