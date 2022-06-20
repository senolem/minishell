/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:29 by faventur          #+#    #+#             */
/*   Updated: 2022/02/28 10:51:19 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memalloc() function allocates (with malloc(3)) and returns a
** "fresh" zone of memory. The allocated memory is set to 0.
** If the allocation fails, a NULL pointer is returned.
** 
** Return Value: The function returns the allocated zone of memory.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*room;

	room = (unsigned char *)malloc(size);
	if (room == NULL)
		return (NULL);
	ft_bzero(room, size);
	return ((void *)room);
}
