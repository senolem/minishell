<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:59:51 by faventur          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:54 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
int ft_is_sort(int *tab, int length, int (*f)(int, int));

int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
<<<<<<< HEAD
    int	i;
=======
	int	i;
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601

	i = 0;
	while (tab[i] && f(tab[i], tab[i + 1]) == 0)
		i++;
	if (tab[i] && f(tab[i], tab[i + 1]) > 0)
	{
		while (++i < length - 1)
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
	}
	if (tab[i] && f(tab[i], tab[i + 1]) < 0)
	{
		while (++i < length - 1)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
	}
<<<<<<< HEAD
    return (1);
=======
	return (1);
>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
}