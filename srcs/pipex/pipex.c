/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/14 14:19:53 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_exec_min(char *cmd)
{
	size_t	a;
	size_t	b;
	size_t	i;

	a = 0;
	b = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			++a;
		else if (cmd[i] == '.')
			++b;
		++i;
	}
	if (a > 0 && b > 0)
		return (1);
	else if (a > 0 && b == 0)
		return (2);
	else if (a == 0 && b > 0)
		return (3);
	return (0);
}

int	ft_exec(char **cmd_args)
{
	pid_t	pid;
	char	*cmd;
	char	**env;

	sig_toggle(1);
	if (builtin_launch(cmd_args) != -99 || !cmd_args || !cmd_args[0])
		return (sig_toggle(0));
	env = env_read(ENV_FILE);
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
	{
		errno = 0;
		if (ft_self_searcher(env, cmd_args))
			return (sig_toggle(0));
		else if (!access(cmd_args[0], X_OK) && ft_exec_min(cmd_args[0]) > 0)
			cmd = cmd_args[0];
		if (errno != 0)
		{
			if (ft_exec_min(cmd_args[0]) == 0)
			{
				ft_printf("minishell: %s: command not found\n", cmd_args[0]);
				return (sig_toggle(0));
			}
			ft_printf("minishell: %s: %s\n", cmd_args[0], strerror(errno));
			return (sig_toggle(0));
		}
	}
	errno = 0;
	pid = fork();
	if (pid == 0)
		execve(cmd, cmd_args, env);
	if (errno != 0)
	{
		printf("%i\n", errno);
		ft_printf("minishell: %s: %s\n", cmd_args[0], strerror(errno));
	}
	waitpid(pid, NULL, 0);
	ft_arr_freer(env);
	return (sig_toggle(0));
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
