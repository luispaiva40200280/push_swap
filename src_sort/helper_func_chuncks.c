
#include "../push_swap.h"

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
// Returns the position of the closest element in a chunk (start → end)
int find_chunk_pos(t_node **lst, int start_indx, int end_indx)
{
	int pos;
	t_node	*tmp;

	tmp = *lst;
	pos = 0;
	while (tmp)
	{
		if (tmp->index >= start_indx && tmp->index >= start_indx)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}


void	push_chunk_b(t_node **lst, t_node **lst_b, int chunk_start, int chunk_end)
{
	int	pos;
	int size;

	size = lst_size(*lst);
	while ((pos = find_chunk_pos(lst, chunk_start, chunk_end)) != -1)
	{
		if (pos <= size / 2)
            while (pos-- > 0)
                ra(lst, 1);
        else
        {
            int r = lst_size(*lst) - pos;
            while (r-- > 0)
                rra(lst, 1);
        }
		pb(lst, lst_b, 1);
		if ((*lst_b)->index < (chunk_start + chunk_end) / 2)
			rb(lst_b, 1);
	}
}

int choose_chunk_count(int size)
{
	if(size <= 100)
		return (5);
	return (11);
}