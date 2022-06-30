/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:32:29 by albaur            #+#    #+#             */
/*   Updated: 2022/06/30 14:18:32 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **env_delete(char *str, char ***env)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**ptr;
	char	**new;

	i = 0;
	j = 0;
	k = env_search(str, *env);
	ptr = *env;
	new = malloc(sizeof(char *) * (ft_arrlen(ptr)));
	if (!new)
		return (NULL);

	while (ptr[j])
	{
		if (j == k)
		{
			free(ptr[j]);
			++j;
		}
		else
		{
			new[i] = ptr[j];
			++i;
			++j;
		}
	}
	new[i] = 0;
	free(*env);
	return (new);
}