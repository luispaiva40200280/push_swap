
#include "../push_swap.h"

void	pb(t_node **lst, t_node **lst_b, int to_print)
{
	t_node *tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	if (to_print)
		ft_printf("pb\n");	
}

void	rb(t_node **lst, int to_print)
{
	t_node	*first;
	t_node	*last;

	if (!lst || !(*lst) || !(*lst)->next)
		return;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	if (to_print)
		ft_printf("rb\n");
}

void reverse_rotate(t_node **stack)
{
    t_node  *last;
    t_node  *penultimate;

    if (!*stack || !(*stack)->next)
        return;

    penultimate = NULL;
    last = *stack;

    // Move last to the end, and penultimate to the node before it
    while (last->next != NULL)
    {
        penultimate = last;
        last = last->next;
    }

    // The second-to-last node now points to nothing (it's the new tail)
    penultimate->next = NULL;
    // The last node points to the old head
    last->next = *stack;
    // The head pointer now points to the last node
    *stack = last;
}
void rrb(t_node **lst_b, int print)
{
    reverse_rotate(lst_b);
    if (print)
        write(1, "rrb\n", 4);
 }
