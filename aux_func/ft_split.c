/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:08:36 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/19 02:15:11 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_all(char **arr, int n)
{
	int i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_countwords(const char *str, int c)
{
	int words;
	int i;

	if (! str)
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

int	ft_len(const char *str)
{
	int	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}


char	**ft_split(const char *str, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;
	int		start;

	if (!str)
		return (NULL);
	words = ft_countwords(str, c);
	result = malloc(sizeof(char *) * (words + 1));  // +1 for NULL terminator
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < words)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && str[i] != c)
				i++;
			result[j] = ft_strndup((char *)str + start, i - start);
			if (!result[j])
				return (free_all(result, j), NULL);
			j++;
		}
	}
	result[j] = NULL;  // NULL terminate the array
	return (result);
}
