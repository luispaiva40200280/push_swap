/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:25 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/22 20:13:52 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this main will be use for testting the code
#include "push_swap.h"

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	ft_printf("List: ");
	while (current)
	{
		ft_printf("[value:  %d, index: %d] -> ", current->value, current->index);
		current = current->next;
	}
	ft_printf("NULL\n");
}

int	*init_list_one(char *argv, int *nbrs)
{
	char	**numbers;
	int		i;
	int		size;
	int		value;

	size = ft_countwords((const char *)argv, ' ');
	numbers = ft_split(argv, ' ');
	if (!numbers)
		return (ft_printf("Error\n"), NULL);
	nbrs = (int *)malloc(sizeof(int) * size);
	if (!nbrs)
		return (ft_printf("Error\n"), free(numbers), NULL);
	i = 0;
	while (numbers[i])
	{
		value = ft_atol(numbers[i]);
		nbrs[i] = value;
		if (ft_find_number(nbrs, i, value))
			return (ft_printf("Error\n"), free(numbers), free(nbrs), NULL);
		i++;
	}
	return (free(numbers), nbrs);
}

int	*init_list_more(char **argv, int *nbrs, int size)
{
	int	value;
	int	i;

	nbrs = (int *)malloc(sizeof(int) * size);
	if (!nbrs)
		return (ft_printf("Error\n"), NULL);
	i = 0;
	while (i < size)
	{
		value = ft_atol(argv[i]);
		nbrs[i] = value;
		if (ft_find_number(nbrs, i, value))
			return (ft_printf("Error\n"), free(nbrs), NULL);
		i++;
	}
	return (nbrs);
}

int	main(int argc, char **argv)
{
	int		*nbrs;
	t_node	*list_a;

	nbrs = NULL;
	list_a = NULL;
	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
	{
		nbrs = init_list_one(argv[1], nbrs);
		list_a = build_from_arr(nbrs, ft_countwords((const char *)argv[1], ' '));
	}
	else if (argc > 2)
	{
		nbrs = init_list_more(argv + 1, nbrs, argc - 1);
		list_a = build_from_arr(nbrs, argc - 1);
	}
	if (!list_a)
		return (free(nbrs), ft_printf("Error\n") ,0);
	handler_sort(list_a);
	while (list_a)
	{
		printf("[value: %d | index: %d] -> ", list_a->value, list_a->index);
		list_a = list_a->next;
	}
	printf("NULL\n");
	return (free_list(list_a), free(nbrs), 0);
}
