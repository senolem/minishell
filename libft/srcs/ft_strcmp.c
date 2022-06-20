/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:02:26 by faventur          #+#    #+#             */
/*   Updated: 2022/02/25 20:48:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strcmp() function compares the two strings s1 and s2. It returns
** an integer less than, equal to, or greater than zero if s1 is found,
** respectively, to be less than, to match, or be greater than s2.
** 
** Return Value: The strcmp() function returns an integer less than,
** equal to, or greater than zero if s1 is found, respectively, to be
** less than, to match, or be greater than s2.
*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (((unsigned char *)s1)[i] != '\0' && ((unsigned char *)s2)[i] != '\0')
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (((unsigned char *)s2)[i] == '\0')
		return (((unsigned char *)s1)[i]);
	if (((unsigned char *)s1)[i] == '\0')
		return (-((unsigned char *)s2)[i]);
	return (0);
}
