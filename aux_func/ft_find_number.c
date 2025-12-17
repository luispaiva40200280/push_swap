
#include "../push_swap.h"

int ft_find_number(int *numbers, int size, int value)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (numbers[i] == value)
			return (1);
		i++;
	}
	return (0);
}