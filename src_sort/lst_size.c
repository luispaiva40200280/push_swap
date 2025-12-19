/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 00:54:30 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/19 00:56:02 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int lst_size(t_node *lst)
{
	int size;
	
	size = 0;
	while(lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
