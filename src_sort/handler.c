/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:16:00 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/19 03:40:24 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this will make the handler for my push_swap logic 

#include "../push_swap.h"

void	handler_swp(t_node lst)
{	
	if (!is_sort(lst))
		return ;
	else if (lst_size(lst) <= 5)
		sort_small_lst(lst);
}
