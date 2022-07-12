<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:30:16 by faventur          #+#    #+#             */
/*   Updated: 2021/12/02 18:07:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
#include <stdio.h>

int ft_any(char **tab, int (*f)(char*));

int ft_any(char **tab, int (*f)(char*))
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
<<<<<<< HEAD
}
=======
}
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
