/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/12 16:42:55 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exec(char *cmd)
{
	char **cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
		ft_puterror("Error: Impossible to find the binary file.");
	if (execve(cmd, cmd_args, NULL))
		ft_printerror("pipex", cmd);
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

static void	child_process(t_var var, char *cmd, int fdin)
{
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	close(var.end[1]);
	if (fdin == STDIN_FILENO)
		exit(1);
	ft_exec(cmd);
	exit(EXIT_FAILURE);
}

void	pipex(char *cmd, int fdin)
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
		child_process(var, cmd, fdin);
	parent_process(var);
}
