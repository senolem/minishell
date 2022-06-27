/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:16:11 by albaur            #+#    #+#             */
/*   Updated: 2022/06/27 16:34:31 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	env_search(char *str, char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(str, env[i], ft_strlen(str)))
			return (i);
		++i;
	}
	return (-1);
}
