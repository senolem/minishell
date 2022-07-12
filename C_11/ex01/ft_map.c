/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2021/12/01 16:03:02 by faventur          #+#    #+#             */
/*   Updated: 2021/12/02 18:09:34 by faventur         ###   ########.fr       */
=======
/*   Created: 2021/12/01 11:44:51 by faventur          #+#    #+#             */
/*   Updated: 2022/02/21 15:34:26 by faventur         ###   ########.fr       */
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

<<<<<<< HEAD
int *ft_map(int *tab, int length, int (*f)(int))
=======
int	*ft_map(int *tab, int length, int (*f)(int))
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * length);
	while (tab[i] && i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}
