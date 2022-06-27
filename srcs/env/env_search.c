/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:16:11 by albaur            #+#    #+#             */
/*   Updated: 2022/06/27 18:15:18 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

ssize_t	env_search(char *str, char **env)
{
	ssize_t	i;

	if (!str || !env || !*env)
		return (-1);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(str, env[i], ft_strlen(str)))
			return (i);
		++i;
	}
	return (-1);
}
