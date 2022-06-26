/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:37:19 by faventur          #+#    #+#             */
/*   Updated: 2022/06/26 15:38:00 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printerror(char *program, char *pathname)
{
	ft_fprintf(2, "%s: %s: %s\n", program, pathname, strerror(errno));
	exit(1);
}
