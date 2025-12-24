
#include "../push_swap.h"

int is_sort(t_node **lst)
{
	t_node *tmp = *lst;

	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int lst_size(t_node *lst)
{
	int size;
	
	size = 0;
	while(lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_node	*f_last(t_node *lst)
{
	while (lst)
		lst = lst->next;
	return (lst);
}