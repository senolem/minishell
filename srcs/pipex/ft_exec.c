/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:07 by albaur            #+#    #+#             */
/*   Updated: 2022/07/15 01:32:18 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup_and_run(t_var *var)
{
	if (var->fd[0] && var->fd[0] != -1)
	{
		dup2(var->fd[0], STDIN_FILENO);
		close(var->fd[0]);
	}
	if (var->fd[1] != 1 && var->fd[1] != -1)
	{
		dup2(var->fd[1], STDOUT_FILENO);
		close(var->fd[1]);
	}
}

int	ft_exec_min(char *cmd)
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
	if (a == 0 && b == 0)
		return (0);
	else if (a > 0 && b > 0)
		return (1);
	else if (a > 0 && b == 0)
		return (2);
	else if (a == 0 && b > 0)
		return (3);
	return (4);
}

int	ft_exec_found(char **env, char **cmd_args, char *cmd, t_var *var)
{
	pid_t		pid;
	struct stat	stats;

	stat(cmd_args[0], &stats);
	if (S_ISDIR(stats.st_mode))
		return (3);
	errno = 0;
	pid = fork();
	if (pid == 0)
	{
		ft_dup_and_run(var);
		execve(cmd, cmd_args, env);
	}
	waitpid(pid, NULL, 0);
	ft_arr_freer(env);
	return (0);
}

int	ft_exec_not_found(char **env, char **cmd_args)
{
	if (ft_self_searcher(env, cmd_args))
		return (0);
	if (errno != 0)
	{
		if (ft_exec_min(cmd_args[0]) == 0)
			return (2);
		return (1);
	}
	ft_arr_freer(env);
	return (0);
}

int	ft_exec(char **cmd_args, t_var *var)
{
	int		i;
	char	*cmd;
	char	**env;

	i = 0;
	sig_toggle(1);
	if (builtin_launch(cmd_args) != -99 || !cmd_args || !cmd_args[0])
		return (sig_toggle(0));
	env = env_read(ENV_FILE);
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
	{
		if (!access(cmd_args[0], X_OK) && ft_exec_min(cmd_args[0]) > 0)
			i = ft_exec_found(env, cmd_args, "/bin/bash", var);
		else
			i = ft_exec_not_found(env, cmd_args);
	}
	else
		i = ft_exec_found(env, cmd_args, cmd, var);
	if (i == 1)
		ft_printf("minishell: %s: %s\n", cmd_args[0], strerror(errno));
	else if (i == 2)
		ft_printf("minishell: %s: command not found\n", cmd_args[0]);
	else if (i == 3)
		ft_printf("minishell: %s: is directory\n", cmd_args[0]);
	sig_toggle(0);
	return (0);
}
