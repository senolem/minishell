/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_searcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:24:11 by faventur          #+#    #+#             */
/*   Updated: 2022/07/14 14:15:09 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path_searcher(char *cmd)
{
	t_searcher	s;

	s.i = 0;
	s.cmd_args = ft_split(cmd, ' ');
	if (!s.cmd_args)
		return (NULL);
	s.env_path = ft_getenv("PATH");
	s.paths = ft_split(s.env_path, ':');
	s.i = 0;
	while (s.paths[s.i])
	{
		s.exec_path = ft_strjoin(s.paths[s.i], ft_strjoin("/", s.cmd_args[0]));
		if (!access(s.exec_path, X_OK))
		{
			ft_arr_freer(s.paths);
			ft_arr_freer(s.cmd_args);
			return (s.exec_path);
		}
		++s.i;
	}
	ft_arr_freer(s.paths);
	ft_arr_freer(s.cmd_args);
	return (NULL);
}
