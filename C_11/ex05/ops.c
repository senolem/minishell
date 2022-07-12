/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:01:23 by faventur          #+#    #+#             */
/*   Updated: 2022/04/07 09:44:28 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_sum(int a, int b)
{
	ft_putnbr(a + b);
	ft_putchar('\n');
}

void	ft_subtraction(int a, int b)
{
	ft_putnbr(a - b);
	ft_putchar('\n');
}

void	ft_multiplication(int a, int b)
{
	ft_putnbr(a * b);
	ft_putchar('\n');
}

void	ft_division(int a, int b)
{
	if (b != 0)
	{
		ft_putnbr(a / b);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("Stop : division by zero");
		ft_putchar('\n');
	}
}

void	ft_modulo(int a, int b)
{
	if (a >= 0 && b != 0)
	{
		ft_putnbr(a % b);
		ft_putchar('\n');
	}
	else if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		ft_putchar('\n');
	}
	else if (a < 0)
	{
		ft_putstr("Stop : modulo on a negative number");
		ft_putchar('\n');
	}
}
