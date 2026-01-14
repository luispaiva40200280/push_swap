/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:55:29 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/12 01:51:44 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this is going to be my checker for the project
static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	check_inst(t_node **lst_a, t_node **lst_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(lst_a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(lst_b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(lst_a, lst_b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(lst_a, lst_b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(lst_a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(lst_b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(lst_a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(lst_b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(lst_a, lst_b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(lst_a, lst_b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(lst_a, lst_b, 0);
	else
		return (ft_dprintf(2, "Error\n"), exit(1) ,1);
	return (1);
}

static void	checker(t_node **lst_a)
{
	char	*line;
	t_node	*lst_b;
	int		instrunctions;

	line = get_next_line(0);
	lst_b = NULL;
	while (line)
	{
		instrunctions = check_inst(lst_a, &lst_b, line);
		if (instrunctions == 0)
		{
			ft_dprintf(2, "Error\n");
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (ft_issort(lst_a) && !lst_b)
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
}

int	main(int ac, char **av)
{
	t_node	*lst_a;
	long	*arr_nbrs;

	lst_a = NULL;
	arr_nbrs = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av++;
	arr_nbrs = init_arr(av, arr_nbrs, arr_size(av));
	if (!arr_nbrs)
	{
		if (ac == 2)
			free_mem(av, (size_t)arr_size(av));
		return (ft_dprintf(2, "Error\n"), 1);
	}
	lst_a = init_stack_a(arr_nbrs, arr_size(av));
	checker(&lst_a);
	if (ac == 2)
		free_mem(av, (size_t)arr_size(av));
	return (free_stack(lst_a), 0);
}
