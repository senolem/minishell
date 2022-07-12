/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:46:47 by faventur          #+#    #+#             */
/*   Updated: 2022/04/07 09:37:18 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void	ft_sum(int a, int b);
void	ft_subtraction(int a, int b);
void	ft_multiplication(int a, int b);
void	ft_division(int a, int b);
void	ft_modulo(int a, int b);

int		ft_check_num(char *c);
int		ft_check_op(char *c);
void	ft_do_op(int a, char *sign, int b);

int		ft_atoi(const char *nptr);
void	ft_putnbr(int nb);
void	ft_putstr(char const *str);
void	ft_putchar(char c);

#endif