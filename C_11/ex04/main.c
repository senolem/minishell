#include <stdio.h>
#include "ft_is_sort.c"

int ft_is_it_sorted(int n1, int n2);

int main()
{
    int	i = 0;
	int	tab[6] = {8, 7, 7, 5, 3, 2};
	int	length = 6;
    int p = ft_is_sort(tab, length, &ft_is_it_sorted);
    printf("%d\n", p);
}

int ft_is_it_sorted(int n1, int n2)
{
    return (n1 - n2);
}