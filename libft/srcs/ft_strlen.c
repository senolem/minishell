/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:00:43 by faventur          #+#    #+#             */
/*   Updated: 2022/02/26 13:18:02 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strlen() function calculates the length of the string s, excluding
** the terminating null byte.
** 
** Return Value: The strlen() function returns the number of bytes in the
** string s.
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}
