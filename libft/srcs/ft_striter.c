/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:04:44 by faventur          #+#    #+#             */
/*   Updated: 2022/02/28 10:51:37 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_striter() function applies the f function to every character of
** the string passed as a parameter. Every character is passed by address
** to the f function so that it may be modified if necessary.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] && s[i] != '\0')
	{
		f(&s[i]);
		i++;
	}
}
