/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:07 by albaur            #+#    #+#             */
/*   Updated: 2022/07/17 19:27:11 by faventur         ###   ########.fr       */
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
//	pid_t		pid;
	struct stat	stats;

	(void)var;
	if (stat(cmd_args[0], &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode))
			return (3);
	}
	errno = 0;
/*
	pid = fork();
	if (pid < 0)
	{
		close(var->end[0]);
		close(var->end[1]);
		ft_puterror("T'as tout cassé");
	}
	if (pid == 0)
	{
		ft_dup_and_run(var);
		execve(cmd, cmd_args, env);
	}
	ft_fprintf(2, "raviolo\n");
	waitpid(pid, NULL, 0);
*/
	execve(cmd, cmd_args, env);

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
	if (cmd_args && tilde_searcher(cmd_args))
		tilde_replacer(cmd_args);
	if (builtin_launch(cmd_args) != -99 || !cmd_args || !cmd_args[0])
		return (sig_toggle(0));
	env = env_read(ENV_FILE);
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
	{
		if (!access(cmd_args[0], X_OK) && ft_exec_min(cmd_args[0]) > 0)
			i = ft_exec_found(env, ft_exec_args(cmd_args), "/bin/bash", var);
		else
			i = ft_exec_not_found(env, cmd_args);
	}
	else
		i = ft_exec_found(env, cmd_args, cmd, var);
	ft_exec_error(i, cmd_args);
	sig_toggle(0);
	return (0);
}
