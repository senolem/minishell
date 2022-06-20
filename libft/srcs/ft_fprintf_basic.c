/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:34 by faventur          #+#    #+#             */
/*   Updated: 2022/06/16 15:11:18 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_putoctals_count(int nbr, char *base, t_tools var)
{
	int			i;
	int			ret[100];

	i = 0;
	if (nbr == 0)
		ft_putchar_count(0 + '0', var);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_count('-', var);
	}
	while (nbr > 0)
	{
		ret[i] = nbr % 8;
		nbr /= 8;
		i++;
	}
	while (--i >= 0)
		ft_putchar_count(base[ret[i]], var);
	return (*var.n_char);
}

int	ft_puthexa(unsigned int nbr, char *base, t_tools var)
{
	int			i;
	int			ret[100];

	i = 0;
	if (nbr == 0)
		ft_putchar_count(0 + '0', var);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_count('-', var);
	}
	while (nbr > 0)
	{
		ret[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar_count(base[ret[i]], var);
	return (*var.n_char);
}

int	ft_putaddr_count(unsigned long long nbr, t_tools var)
{
	int	i;
	int	ret[100];

	i = 0;
	if (nbr == 0)
	{
		ft_putstr_count("0x0", var);
		return (*var.n_char);
	}
	while (nbr)
	{
		ret[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	ft_putstr_count("0x", var);
	while (--i >= 0)
		ft_putchar_count("0123456789abcdef"[ret[i]], var);
	return (*var.n_char);
}
