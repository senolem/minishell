/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/13 16:56:54 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(char **cmd_args)
{
	pid_t	pid;
	char	*cmd;
	char	**env;

	if (builtin_launch(cmd_args) == 1)
		return (1);
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
	{
		ft_printf("minishell: command not found: %s\n", cmd_args[0]);
		return (0);
	}
	env = env_read(ENV_FILE);
	pid = fork();
	if (pid == 0)
		execve(cmd, cmd_args, env);
	waitpid(pid, NULL, 0);
	ft_arr_freer(env);
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

static int	child_process(t_var var, char **cmd_args)
{
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	close(var.end[1]);
//	if (fdin == STDIN_FILENO)
//		exit(1);
	return (ft_exec(cmd_args));
}

void	pipex(char **cmd_args)
{
	t_var	var;

	if (pipe(var.end) == -1)
		ft_printerror("pipex", cmd_args[0]);
	var.pid = fork();
	if (var.pid < 0)
	{
		close(var.end[0]);
		close(var.end[1]);
		ft_printerror("pipex", cmd_args[0]);
	}
	if (var.pid == 0)
	{
		if (child_process(var, cmd_args) != 0)
			return ;
	}
	parent_process(var);
}
