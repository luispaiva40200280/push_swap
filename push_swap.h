/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:31:08 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/17 21:46:50 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

char	*ft_strndup(char *str, int n);
char	**ft_split(const char *str, char c);

int 	ft_find_number(int *numbers, int size, int value);
int		ft_countwords(const char *str, int c);
int		ft_atol(char *str);
int		ft_printf(const char *format, ...);
int 	ft_putnbr_base(long long nbr, char *base, int base_zise, int count);
int 	ft_putnbr_base_uns(unsigned long long nbr, char *base, int base_zise, int count);
int		ft_ptptr(void *ptr, int count);
int		ft_strchr(const char *str, char c);

#endif
