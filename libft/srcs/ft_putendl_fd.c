/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:29:35 by faventur          #+#    #+#             */
/*   Updated: 2022/03/01 18:17:29 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl_fd() function writes a string on the file descriptor
** followed by a carriage return.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (fd >= 0)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
