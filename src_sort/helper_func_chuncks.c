
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
int find_chepeast_chunk_pos(t_node **lst, int start_indx, int end_indx, int size)
{
	int		pos;
	t_node	*tmp;
	int     first_match;
    int     last_match;

    first_match = -1;
    last_match = -1;
	tmp = *lst;
	pos = 0;
	while (tmp)
	{
		if (tmp->index >= start_indx && tmp->index <= end_indx)
		{
			if (first_match == -1)
				first_match = pos;
			last_match = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (first_match == -1)
		return (-1);
	if (first_match <= (size - last_match))
		return (first_match);
	else
		return (last_match);
		
}

/*
	this func will find the esiast node to move
	cheking the movements need it;  
*/
void	push_chunk_b(t_node **lst, t_node **lst_b, int chunk_start, int chunk_end)
{
	int	pos;
	int size;

	size = lst_size(*lst);
	while (1)
    {
        pos = find_chepeast_chunk_pos(lst, chunk_start, chunk_end, size);
        if (pos == -1)
            break;

        size = lst_size(*lst);

        // Rotate A to bring the chosen number to top
        if (pos <= size / 2)
        {
            while (pos-- > 0)
                ra(lst, 1);
        }
        else
        {
            // Optimize: calculate exactly how many rra needed
            int moves = size - pos;
            while (moves-- > 0)
                rra(lst, 1);
        }

        // Push to B
        pb(lst, lst_b, 1);

        // Butterfly Optimization:
        // If the number is in the lower half of the chunk, send to bottom of B.
        // This helps sort B while pushing.
        if ((*lst_b)->index < (chunk_start + chunk_end) / 2)
        {
            rb(lst_b, 1);
        }
    }
}
