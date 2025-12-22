

#include "../push_swap.h"

void	sa(t_node **lst, int to_print)
{
	t_node	*first;
	t_node	*second;
	
	if (!(*lst) || !lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	
	first->next = second->next;
	second->next = first;
	*lst = second;
	if (to_print)
		ft_printf("sa\n");
}
