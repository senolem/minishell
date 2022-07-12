/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:59:51 by faventur          #+#    #+#             */
/*   Updated: 2022/03/01 16:17:56 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

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
	return (1);
}
