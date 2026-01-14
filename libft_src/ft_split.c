/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:47:49 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/06 19:13:19 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_countw(char const *s, char c)
{
	size_t	words;
	size_t	i;

	if (!s)
		return (0);
	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

void	free_mem(char **arr, size_t j)
{
	while (j > 0)
	{
		free(arr[j - 1]);
		j--;
	}
	free(arr);
}

static char	**fill_result(char **result, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[j] = ft_strndup((char *)s + start, i - start);
		if (!result[j])
			return (free_mem(result, j), NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_countw(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_result(result, s, c, count));
}
