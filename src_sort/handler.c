/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:16:00 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/29 21:15:43 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this will make the handler for my push_swap logic 
/*
t_node *a;    // pointer to first node
t_node **a;   // handle to MOVE the first node
*/

#include "../push_swap.h"
#include <stdio.h>

static void print_stack_deb(const char *name, t_node *lst)
{
    printf("Stack %s: ", name);
    if (!lst)
    {
        printf("(empty)\n");
        return;
    }
    while (lst)
    {
        printf("[%d | idx:%d] -> ", lst->value, lst->index);
        lst = lst->next;
    }
    printf("NULL\n");
}

void print_stacks(t_node *a, t_node *b)
{
    print_stack_deb("A", a);
    print_stack_deb("B", b);
    printf("--------\n");
}

void	handler_sort(t_node **lst)
{
	t_node *lst_b;
    int size;
    
	lst_b = NULL;
    size = lst_size(*lst);
	//printf("lst_size = %d\n", lst_size(*lst));
	if (is_sort(lst))
		return ; 
	else if (size == 2)
        sa(lst, 1);
    else if (size <= 3)
		sort_3(lst);
	else if (size <= 5)
		sort_5(lst, &lst_b);
	else
		butterfly_sort(lst, &lst_b, size);
}
