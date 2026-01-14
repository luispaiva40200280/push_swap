/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:53:42 by lpaiva            #+#    #+#             */
/*   Updated: 2025/12/30 22:57:07 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strndup(char *str, int n)
{
	char	*strdup;
	int		i;

	strdup = (char *)malloc((n + 1) * sizeof(char));
	if (!strdup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		strdup[i] = str[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}
