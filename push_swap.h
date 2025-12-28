/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:08 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/28 00:37:54 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*all lib need  */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>  

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// debuger helper 
void print_stacks(t_node *a, t_node *b);

void	print_list(t_node *head);
/* creation of the stack and sorting*/
t_node		*build_from_arr(int *arr, int size);
t_node		*find_min_node(t_node *lst);
void		free_list(t_node *head);
int			get_pos(t_node *lst, t_node *node);
int			is_sort(t_node **lst);
int			lst_size(t_node *lst);
int			lst_min_ind(t_node **lst);
int			lst_max_ind(t_node **lst);
void		handler_sort(t_node **lst);
void		sort_3(t_node **lst);
void		sort_5(t_node **lst, t_node **lst_b);
void		ass_index(t_node *lst);
void		sa(t_node **lst, int to_print);
void		rra(t_node **lst, int to_print);
void		ra(t_node **lst, int to_print);
void		rb(t_node **lst, int to_print);
void		pa(t_node **lst,t_node **lst_b, int to_print);
void		pb(t_node **lst, t_node **lst_b, int to_print);
void		radix_sort(t_node **lst, t_node **lst_b);
void		push_small_b(t_node **lst, t_node **lst_b);

/* helper func for ft_ptintf */
int		ft_printf(const char *format, ...);
int 	ft_putnbr_base(long long nbr, char *base, int base_zise, int count);
int 	ft_putnbr_base_uns(unsigned long long nbr, char *base, int base_zise, int count);
int		ft_ptptr(void *ptr, int count);

/* helper func for ft_spit */
char	**ft_split(const char *str, char c);
char	*ft_strndup(char *str, int n);
int		ft_countwords(const char *str, int c);
int 	ft_find_number(int *numbers, int size, int value);
int		ft_strchr(const char *str, char c);

/* helper func for atol */
int		ft_atol(char *str);

#endif
