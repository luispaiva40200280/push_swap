/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:06:44 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/09 18:46:04 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*------  all lib need ----------- */
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* ------------------------ */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;
/*---- functions for linked lists {utils && craetion} -----*/
t_node				*init_stack_a(long *arr_nbrs, int size);
t_node				*find_min_node(t_node *lst);
t_node				*find_max_node(t_node *lst);
void				handler_sort_type(t_node **lst_a);
int					lst_size(t_node *lst);
int					get_pos(t_node **lst, t_node *target);
void				free_stack(t_node *head);

/* **** functions to sort list (sort >> 3 && sort >> 5 && butterfly) */
void				sort_lst_3(t_node **lst_a);
void				sort_lst_5(t_node **lst_a, t_node **lst_b);
void				butterfly_sort(t_node **lst_a, t_node **lst_b, int size_a);
/*----- operations too the stacks  -----*/
/*----- stack A*/
void				pa(t_node **lst, t_node **lst_b, int print);
void				rra(t_node **lst, int print);
void				ra(t_node **lst, int print);
void				sa(t_node **lst, int print);
/* ------stack B */
void				pb(t_node **lst, t_node **lst_b, int print);
void				rrb(t_node **lst, int print);
void				rb(t_node **lst, int print);
void				sb(t_node **lst, int print);
/*---- both stacks A && B"mostly for the ckecker {bonus}"  */
void				ss(t_node **lst_a, t_node **lst_b, int print);
void				rr(t_node **lst_a, t_node **lst_b, int print);
void				rrr(t_node **lst_a, t_node **lst_b, int print);

/*---- functions for printin erros && operations -----*/
int					ft_dprintf(int fd, const char *format, ...);
int					ft_putnbr_base(long nbr, char *base, int len, int fd);
int					ft_putnbr_base_uns(unsigned long nbr, char *base, int size,
						int fd);
int					ft_putchar(char c, int count, int fd);
int					ft_putstr(char *str, int count, int fd);
int					ft_ptptr(void *ptr, int count, int fd);

/* -------- parser functions  ------ */
long				ft_atol(char *str);
/*parser for the arr */

int					find_number_arr(long *numbers, int size, long value);
int					arr_size(char **str);
long				*init_arr(char **av, long *arr_nbrs, int size);
/* -------- ft_split functions ------ */
char				*ft_strndup(char *str, int n);
char				**ft_split(char const *s, char c);
void				free_mem(char **arr, size_t j);

/*----- DEBUGGING ----*/
void				print_list(t_node *head);
int					ft_issort(t_node **lst_a);

/*---- GET NEXT LINE OPERACTIONS AND LIB  ---*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

unsigned int		ft_strlen(const char *str);
char				*ft_strjoin_free(char *s1, const char *s2);
unsigned char		*ft_strchr(const char *s, int c);
char				*get_next_line(int fd);

#endif