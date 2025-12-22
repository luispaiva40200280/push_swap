/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:16:00 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/22 20:40:47 by lpaiva           ###   ########.fr       */
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
	if (!is_sort(*lst))
		return ;
	else if (lst_size(*lst) == 2)
		sa(lst, 1);
	else if (lst_size(*lst) <= 3)
		return ;
		//sort_3(lst);
	else if (lst_size(*lst) <= 5)
		return ;
		//sort_5(lst);
	else
		return ;

}
