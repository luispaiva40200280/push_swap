
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
//min and max index
int lst_min_ind(t_node **lst)
{
	int	min;
	t_node	*tmp;

	tmp = *lst;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}
t_node		*find_min_node(t_node *lst)
{
	t_node	*min;
	t_node	*tmp;

	tmp = lst;
	min = tmp;
	while (tmp)
	{
		if (tmp->index < min->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
	
}

int lst_max_ind(t_node **lst)
{
	int	max;
	t_node	*tmp;

	tmp = *lst;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}


t_node		*find_bigest_node(t_node *lst)
{
	t_node	*max;
	t_node	*tmp;

	tmp = lst;
	max = tmp;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}