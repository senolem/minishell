#include <unistd.h>
#include <stdio.h>
#include "ft_map.c"

int	ft_add_five(int nb);

int	main()
{
	int	i = 0;
	int	tab[6] = {1, 2, 56, 76, 34, 65};
	int	length = 6;
	int *array = ft_map(tab, length, &ft_add_five);
	while (i < length)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int	ft_add_five(int nb)
{
	return (nb + 5);
}