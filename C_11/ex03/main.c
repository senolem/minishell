#include <stdio.h>
#include "ft_count_if.c"

int	ft_str_is_lowercase(char *str);

int	main()
{
    char	*tab[] = {"bonjour", "bonsoir", "bonne nuit", "bonne journee", "Bau", "Ciao"};
	int x = ft_count_if(tab, 6, &ft_str_is_lowercase);
    printf("%d", x);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
