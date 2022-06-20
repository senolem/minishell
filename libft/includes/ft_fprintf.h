/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:18:37 by faventur          #+#    #+#             */
/*   Updated: 2022/06/16 15:09:21 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_tools
{
	int	fd;
	int	n_char[1];
}			t_tools;

int		ft_putchar_count(char c, t_tools var);
int		ft_putstr_count(char *str, t_tools var);
int		ft_putnbr_count(int nbr, char *base, t_tools var);
int		ft_put_unsigned(int nbr, char *base, t_tools var);
int		ft_putoctals_count(int nbr, char *base, t_tools var);
int		ft_puthexa(unsigned int nbr, char *base, t_tools var);
int		ft_putaddr_count(unsigned long long nbr, t_tools var);
int		ft_check(va_list arg_p, t_tools var, const char *format, int i);
int		ft_fprintf(int fd, const char *format, ...);

#endif