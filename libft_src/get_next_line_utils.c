/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:00:16 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/06 18:50:45 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	carc;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	carc = (unsigned char)c;
	while (*str)
	{
		if (*str == carc)
			return (str);
		str++;
	}
	if (carc == '\0')
		return (str);
	return (NULL);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str_dest;
	unsigned const char	*str_src;

	if (!src && !dest)
		return (NULL);
	str_dest = (unsigned char *)dest;
	str_src = (unsigned const char *)src;
	while (n--)
		*str_dest++ = *str_src++;
	return (dest);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*new_str;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (free(s1), NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	return (free(s1), new_str);
}
