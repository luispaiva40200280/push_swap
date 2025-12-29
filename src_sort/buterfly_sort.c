
#include "../push_swap.h"

// see what sizes of our chunks will we use ::
static int	get_size_chunk(int size)
{
	if (size <= 100)
		return (25);
	return (40);
}
/*
	iterates trow original stack is empty;
	3 cases:
		1:: our node is small {it will to lower halk of the chunk}
			&& we push to B and rotate the same stack
		2:: our node is midium {upper half of our chunk}
			&& we push to B and keep the node at top
		3:: the number is one of the biggst {it will be i the end of stack A}
			&& rotate A
---- Now Stack A is empty,
	and Stack B contains everything in a "Butterfly" shape
	(largest values are gathered in the middle/top of B).---------------
*/

static void	push_all_b(t_node **lst, t_node **lst_b, int size)
{
	int	count;
	int	chunk;

	count = 0;
	chunk = get_size_chunk(size);
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

/*
 iterate to stack b and push all node to A
*/
static void	push_all_a(t_node **lst, t_node **lst_b)
{
	t_node	*max;
	int		size_b;

	max = NULL;
	size_b = lst_size(*lst_b);
	while (*lst_b)
	{
		max = find_bigest_node(*lst_b);
		move_max_top(lst_b, max, size_b);
		pa(lst, lst_b, 1);
	}
}

/*
	main func {butterfly sort}
	combines all the helper functions
*/
void	butterfly_sort(t_node **lst, t_node **lst_b)
{/*  */
/* 	int	size; */

/* 	size = lst_size(*lst); */
/* 	push_chunk_b(lst, lst_b, size); */
/* 	push_all_a(lst, lst_b); */
int i;
    int n;
    int chunk_count;
    int chunk_size;
    int start;
    int end;

    n = lst_size(*a);
    chunk_count = get_chunk_count(n);
    chunk_size = n / chunk_count;
    i = 0;

    // PHASE 1: Push chunks to B
    while (i < chunk_count)
    {
        start = i * chunk_size;
        
        // If it's the last chunk, grab everything remaining
        if (i == chunk_count - 1)
            end = n - 1; 
        else
            end = (i + 1) * chunk_size - 1;

        // Call your function to empty this specific range
        push_chunk_b(a, b, start, end);
        
        i++;
    }

    // PHASE 2: Push back to A (Using the Max-to-Top logic we discussed)
    // Make sure you have the 'push_all_to_a' or similar function defined!
    while (*b)
    {
        t_node *max = find_max_index_node(*b);
        rotate_to_top_b(b, max); // The 'rb'/'rrb' specific version
        pa(a, b, 1);
    }
}
