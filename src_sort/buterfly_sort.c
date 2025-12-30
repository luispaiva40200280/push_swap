
#include "../push_swap.h"

// returns the COUNT of chunks::
static int	get_size_chunk(int size)
{
	if (size <= 100)
		return (15);
	return (35);
}

/*
	move max node to the top of the stck b
	if the node is it the top half rotate normaly rb
	else revers rotate;
*/
static void	move_max_top(t_node **lst_b, t_node *max_node, int size)
{
	int	pos;

	pos = get_pos(*lst_b, max_node);
	if (pos <= size / 2)
		while (*lst_b != max_node)
			rb(lst_b, 1);
	else
		while (*lst_b != max_node)
			rrb(lst_b, 1);
}
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
	int moves;

	while (1)
    {
		size = lst_size(*lst);
        pos = find_chepeast_chunk_pos(lst, chunk_start, chunk_end, size);
        if (pos == -1)
            break;
        if (pos <= size / 2)
            while (pos-- > 0)
                ra(lst, 1);
        else
        {
			moves = size - pos;
            while (moves-- > 0)
                rra(lst, 1);
        }
        pb(lst, lst_b, 1);
        if ((*lst_b)->index < (chunk_start + chunk_end) / 2)
            rb(lst_b, 1);
    }
}
/*	
	main func {butterfly sort}
	combines all the helper functions
void	butterfly_sort(t_node **lst, t_node **lst_b, int size)
{
	t_node	*max;
	int 	chunk_count;
	int		i;
	int		start;
	int 	end;
	int		chunk_size;

	i = 0;
	chunk_count = get_size_chunk(size);
	chunk_size = size / chunk_count;
	while (i < chunk_count)
	{
		start = i * chunk_size;
		if (i == chunk_count - 1)
			end = size - 1;
		else
			end = (i + 1) * chunk_size - 1;
		push_chunk_b(lst, lst_b, start, end);
		i++; 
	}
	while (*lst_b)
	{
		max = find_bigest_node(*lst_b);
		move_max_top(lst_b, max, lst_size(*lst_b));
		pa(lst, lst_b, 1);
	}
}
*/

void	butterfly_sort(t_node **lst, t_node **lst_b, int size)
{
	int	count;
	int	chunk;
	t_node	*max;

	count = 0;
	chunk = get_size_chunk(size);
	max = NULL;
	while (*lst)
	{
		if ((*lst)->index <= count)
		{
			pb(lst, lst_b, 1);
			rb(lst_b, 1);
			count++;
		}
		else if ((*lst)->index <= count + chunk)
		{
			pb(lst, lst_b, 1);
			count++;
		}
		else
			ra(lst, 1);
	}
	while (*lst_b)
	{
		max = find_bigest_node(*lst_b);
		if (lst_size(*lst_b) > 1 && (*lst_b)->index == (max->index -1))
		{
			pa(lst, lst_b, 1);
			move_max_top(lst_b, max, lst_size(*lst_b));
			pa(lst, lst_b, 1);
			sa(lst, 1);
		}
		else
		{
			move_max_top(lst_b, max, lst_size(*lst_b));
			pa(lst, lst_b, 1);	
		}
	}
}
