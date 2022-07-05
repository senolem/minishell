/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_searcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:24:11 by faventur          #+#    #+#             */
/*   Updated: 2022/07/05 16:00:23 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path_searcher(char *cmd)
{
	char	**paths;
	char	*exec_path;
	char	*env_path;
	char	**cmd_args;
	size_t	i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	env_path = ft_getenv("PATH");
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		exec_path = ft_strjoin(paths[i], ft_strjoin("/", cmd_args[0]));
		if (!access(exec_path, R_OK))
		{
			ft_arr_freer(paths);
			ft_arr_freer(cmd_args);
			return (exec_path);
		}
		++i;
	}
	ft_arr_freer(paths);
	ft_arr_freer(cmd_args);
	return (NULL);
}
