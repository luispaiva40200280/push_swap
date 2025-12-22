
#include "../push_swap.h"

t_node	*find_min_un(t_node *lst)
{
	t_node	*min;
	
	min = NULL;
	while(lst)
	{
		if (lst->index == -1 && (!min || lst->value < min->value))
			min = lst;
		lst = lst->next;
	}
	return (min);
}

void	ass_index(t_node *lst)
{
	int		index;
	t_node	*min;
	
	index = 0;
	min = NULL;
	while (1)
	{
		min = find_min_un(lst);
		if(!min)
			break ;
		min->index = index;
		index++;
	}
}