/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:32:29 by albaur            #+#    #+#             */
/*   Updated: 2022/06/30 13:47:33 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **env_delete(size_t k, char ***env)
{
	size_t	i;
	size_t	j;
	char	**ptr;
	char	**new;

	i = 0;
	j = 0;
	ptr = *env;
	new = malloc(sizeof(char *) * (ft_arrlen(ptr)));
	if (!new)
		return (NULL);
	while (ptr[i])
	{
		if (i == k)
			++i;
		new[j] = ptr[i];
		++i;
		++j;
	}
	if (!new[i])
	{
		free(new);
		return (NULL);
	}
	new[i + 1] = 0;
	free(*env);
	return (new);
}