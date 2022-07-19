/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_searcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:24:11 by faventur          #+#    #+#             */
/*   Updated: 2022/07/19 13:49:07 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_path_searcher_free(t_searcher *s)
{
	ft_arr_freer(s->paths);
	ft_arr_freer(s->cmd_args);
	return (NULL);
}

char	*ft_path_searcher(char *cmd)
{
	t_searcher	s;

	s.i = -1;
	s.cmd_args = ft_split(cmd, ' ');
	if (!s.cmd_args)
		return (NULL);
	s.env_path = ft_getenv("PATH");
	s.paths = ft_split(s.env_path, ':');
	free(s.env_path);
	if (!s.paths)
		return (NULL);
	while (s.paths[++s.i])
	{
		s.append = ft_strjoin("/", s.cmd_args[0]);
		s.exec_path = ft_strjoin(s.paths[s.i], s.append);
		if (!access(s.exec_path, R_OK) && ft_exec_min(cmd) != 1)
		{
			ft_path_searcher_free(&s);
			return (s.exec_path);
		}
		free(s.append);
		free(s.exec_path);
	}
	return (ft_path_searcher_free(&s));
}
