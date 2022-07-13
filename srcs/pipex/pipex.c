/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/13 09:58:52 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(char *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
		return (0);
	if (execve(cmd, cmd_args, NULL))
		return (0);
	return (1);
}

static void	parent_process(t_var var)
{
	dup2(var.fd[1], STDOUT_FILENO);
	close(var.fd[1]);
	close(var.end[1]);
	dup2(var.end[0], STDIN_FILENO);
	close(var.end[0]);
	waitpid(var.pid, NULL, 0);
}

static int	child_process(t_var var, char *cmd, int fdin)
{
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	close(var.end[1]);
	if (fdin == STDIN_FILENO)
		exit(1);
	return (ft_exec(cmd));
}

int	pipex(char *cmd, int fdin)
{
	t_var	var;

	if (pipe(var.end) == -1)
		ft_printerror("pipex", cmd);
	var.pid = fork();
	if (var.pid < 0)
	{
		close(var.end[0]);
		close(var.end[1]);
		ft_printerror("pipex", cmd);
	}
	if (var.pid == 0)
	{
		if (child_process(var, cmd, fdin) != 0)
			return (1);
	}
	parent_process(var);
}
