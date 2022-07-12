/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:37:04 by faventur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/01 11:10:31 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void(*f)(int));

void	ft_foreach(int *tab, int length, void(*f)(int))
=======
/*   Updated: 2021/12/02 17:49:55 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_foreach(int *tab, int length, void (*f)(int))
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
{
	int	i;

	i = 0;
<<<<<<< HEAD
	while (i < length)
=======
	while (tab[i] && i < length)
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
	{
		f(tab[i]);
		i++;
	}
}
