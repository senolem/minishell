/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:22:29 by albaur            #+#    #+#             */
/*   Updated: 2022/06/27 17:48:03 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_concat(char *s1, char *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, len_s1);
	ft_memcpy((dst + len_s1), s2, len_s2);
	free((void *)s1);
	return (dst);
}

size_t	ft_arrlen(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != NULL)
		++i;
	return (i);
}

char	**ft_arrdup(char **arr)
{
	char	**dup;
	size_t	arr_len;

	dup = NULL;
	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
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
