
#include "push_swap.h"

int	ft_countwords(const char *str, int c)
{
	int words;
	int i;

	if (!str)
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		while(str[i] && str[i] == c)
			i++;
		if (str[i])
			words++;
		while(str[i] && str[i] != c)
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

char	*ft_trim(const char *str, int c)
{
	int start;
	int end;
	int len;
	char *str_tim;
	int i;
	
	if (!str)
		return (NULL);
	start = 0;
	end = ft_len(str);
	while (str[start] && str[start] == c)
		start++;
	end--;
	while (str[end] && str[end] == c)
		end--;
	if (end < start)
		return (NULL);
	len = end - start + 1;
	str_tim = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (start <= end)
		str_tim[i++] = str[start++];
	str_tim[i] = '\0';
	return (str_tim);
	
}
void free_all(char **arr, int n)
{
	while (n > 0)
	{
		free(arr[n--]);
		n--;
	}
	free(arr);
	
}

char	**ft_split(const char *str, int c)
{
	char	*str_trim;
	char	**numbres;
	int		i;
	int		j;
	int		start;
	int 	words;

	if(!str)
		return NULL;
	str_trim = ft_trim(str, c);
	if (!str_trim)
		return (NULL);
	words = ft_countwords((const char *)str_trim, c);
	numbres = malloc((words+ 1) * sizeof(char *));
	if (!numbres)
		return (free(str_trim) ,NULL);
	i = 0;
	j = 0;
	while(str_trim[i] && j < words)
	{
		while(str_trim[i] && str_trim[i] == c)
			i++;
		start = i;
		while(str_trim[i] && str_trim[i] != c)
			i++;
		if (start < i)
		{
			numbres[j] = ft_strndup(str_trim + start, i - start);
			if (!numbres[j])
				return (free_all(numbres, j), free(str_trim), NULL);
			j++;
		}	
	}
	numbres[j] = NULL;
	 free(str_trim);
	return (numbres);
}

