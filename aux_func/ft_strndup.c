
#include "push_swap.h"

char *ft_strndup(char *str, int n)
{
	char *strdup;
	int i;

	strdup = (char *)malloc((n + 1) * sizeof(char));
	if(!strdup)
		return (NULL);
	i = -1;
	while (i++ < n)
		strdup[i] = str[i]; 
	strdup[i] = '\0'; 
	return (strdup);
}
