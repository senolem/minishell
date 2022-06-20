/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:21:03 by albaur            #+#    #+#             */
/*   Updated: 2022/06/20 16:19:00 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:22:29 by albaur            #+#    #+#             */
/*   Updated: 2022/06/16 16:49:37 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		arr_len;

	dup = NULL;
	if (!arr)
		return (NULL);
	arr_len = ft_strlen(*arr);
	if (!arr_len)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!dup)
		return (NULL);
	dup[arr_len] = NULL;
	while (arr_len--)
	{
		dup[arr_len] = ft_strdup(arr[arr_len]);
		if (!dup[arr_len])
		{
			free(dup);
			return (NULL);
		}
	}
	return (dup);
}

void	throw_error(t_data *data, char *msg, int err)
{
	free(data);
	if (err != 0)
		errno = err;
	perror(msg);
	exit(EXIT_FAILURE);
}
