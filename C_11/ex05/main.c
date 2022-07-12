/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:56:23 by faventur          #+#    #+#             */
/*   Updated: 2022/04/07 09:48:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char *argv[])
{
	int		par1;
	int		par2;

	if (argc == 4)
	{
		if (ft_check_num(argv[1]) && ft_check_op(argv[2])
			&& ft_check_num(argv[3]))
		{
			par1 = ft_atoi(argv[1]);
			par2 = ft_atoi(argv[3]);
			ft_do_op(par1, argv[2], par2);
		}
	}
	return (1);
}

int	ft_check_num(char *c)
{
	if (c[0] >= '0' && c[0] <= '9')
		return (1);
	else
		return (0);
}

int	ft_check_op(char *c)
{
	if (c[0] == '+' || c[0] == '-' || c[0] == '/'
		|| c[0] == '*' || c[0] == '%')
		return (1);
	else
		return (0);
}

void	ft_do_op(int a, char *sign, int b)
{
	void	(*op[5])(int x, int y);

	op[0] = ft_sum;
	op[1] = ft_subtraction;
	op[2] = ft_multiplication;
	op[3] = ft_division;
	op[4] = ft_modulo;
	if (sign[0] == '+')
		op[0](a, b);
	else if (sign[0] == '-')
		op[1](a, b);
	else if (sign[0] == '*')
		op[2](a, b);
	else if (sign[0] == '/')
		op[3](a, b);
	else if (sign[0] == '%')
		op[4](a, b);
}
