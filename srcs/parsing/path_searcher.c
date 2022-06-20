/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_searcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:24:11 by faventur          #+#    #+#             */
/*   Updated: 2022/06/08 09:45:02 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_searcher(char *cmd)
{
	char	**paths;
	char	*exec_path;
	char	*env_path;
	char	**cmd_args;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	env_path = getenv("PATH");
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
		i++;
	}
	ft_arr_freer(paths);
	ft_arr_freer(cmd_args);
	return (NULL);
}
/*
int	main(int argc, char *argv[])
{
	char	*exec;

	(void)argc;
	(void)argv;
	exec = path_searcher("ls");
	ft_printf("%s\n", exec);
}
*/