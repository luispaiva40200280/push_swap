
#include "../push_swap.h"
/* 
	Each pass separates numbers based on the current bit.
	Numbers with 0 in the bit go to B, numbers with 1 stay in A (or are rotated).
	After each pass, B is emptied back into A.
	After max_bits passes, stack A is fully sorted.
	exemple::
	Pass 0 (bit 0):
		A: [3,0,2,1] -> [3,1]
		B: []       -> [2,0]
		Push back B: A = [0,2,3,1]

		Pass 1 (bit 1):
		A: [0,2,3,1] -> [2,3]
		B: []        -> [1,0]
		Push back B: A = [0,1,2,3]
 */ 
size_t	max_bits(t_node *lst)
{
	int 	max;
	size_t	bits;
	t_node	*tmp;

	max = 0;
	bits = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **lst, t_node **lst_b)
{
	int 	i;
	int 	j;
	int 	size;
	size_t 	bits;
	
	bits = max_bits(*lst);
	size = lst_size(*lst);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if(((*lst)->index >> i) & 1)
				ra(lst, 1);
			else
				pb(lst, lst_b, 1);
			j++;
		}
		while (*lst_b)
			pa(lst, lst_b, 1);
		if (is_sort(lst))
			break;
		i++;
	}
}
