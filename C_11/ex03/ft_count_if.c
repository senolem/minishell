<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:09:00 by faventur          #+#    #+#             */
/*   Updated: 2021/12/02 18:09:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 09bd96d6e3bc1d3cb7bbb345ea20b73df095e601
int ft_count_if(char **tab, int length, int (*f)(char*));

int ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
    int counter;

	i = 0;
    counter = 0;
	while (tab[i] && i < length)
	{
		if (f(tab[i]))
			counter++;
		i++;
	}
	return (counter);
}
