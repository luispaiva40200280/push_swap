
#include "../push_swap.h"
	
void	pa(t_node **a,t_node **b, int to_print)
{
	t_node	*tmp;

	// If B is empty, do nothing
	if (!b || !*b)
		return;

	// Save top of B
	tmp = *b;

	// Move B head to next node
	*b = (*b)->next;

	// Put tmp on top of A
	tmp->next = *a;
	*a = tmp;

	if (to_print)
		ft_printf("pa\n");
	
}
void	sa(t_node **lst, int to_print)
{
	t_node	*first;
	t_node	*second;
	
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	
	first->next = second->next;
	second->next = first;
	*lst = second;
	if (to_print)
		ft_printf("sa\n");
}


void	rra(t_node **lst, int to_print)
{
	t_node	*prev;
	t_node	*last;

	if (!lst || !(*lst) || !(*lst)->next)
		return;

	prev = NULL;
	last = *lst;
	while(last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
	if (to_print)
		ft_printf("rra\n");
}

void	ra(t_node **lst, int to_print)
{
	t_node	*first;
	t_node	*last;

	if (!lst || !(*lst) || !(*lst)->next)
		return;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	if (to_print)
		ft_printf("ra\n");
}
