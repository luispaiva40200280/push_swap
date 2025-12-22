
#include "../push_swap.h"

int is_sort(t_node *lst)
{
	while(lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

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

t_node	*f_last(t_node *lst)
{
	while (lst)
		lst = lst->next;
	return (lst);
}