/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartab_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:15 by faventur          #+#    #+#             */
/*   Updated: 2022/06/27 17:20:56 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chartab_len(char **arr)
{
	size_t	i;

	if (!arr || *arr)
		return (NULL);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
