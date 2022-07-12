#include <stdio.h>
#include "ft_any.c"

int	ft_str_is_lowercase(char *str);

int	main()
{
    char	*tab[] = {"bon jour", "bon soir", "bonnenuit"};
	int x = ft_any(tab, &ft_str_is_lowercase);
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
