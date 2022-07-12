#include <unistd.h>

#include "ft_foreach.c"

void	ft_putchar(char c);
void	ft_putnbr(int nb);

int	main()
{
	int	tab[6] = {1, 2, 56, 76, 34, 65};
	int	length = 6;
	ft_foreach(tab, length, &ft_putnbr);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
