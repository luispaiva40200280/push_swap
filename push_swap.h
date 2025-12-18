/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:08 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/18 21:31:23 by lpaiva           ###   ########.fr       */
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

/* creation of the stack */
t_node		*build_from_arr(int *arr, int size);
void		free_list(t_node *head);

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
