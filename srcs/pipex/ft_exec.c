/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:07 by albaur            #+#    #+#             */
/*   Updated: 2022/07/14 15:20:45 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_exec_found(char **env, char **cmd_args, char *cmd)
{
	pid_t	pid;

	errno = 0;
	pid = fork();
	if (pid == 0)
		execve(cmd, cmd_args, env);
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

int	ft_exec(char **cmd_args)
{
	int		i;
	char	*cmd;
	char	**env;

	sig_toggle(1);
	if (builtin_launch(cmd_args) != -99 || !cmd_args || !cmd_args[0])
		return (sig_toggle(0));
	env = env_read(ENV_FILE);
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
	{
		if (!access(cmd_args[0], X_OK) && ft_exec_min(cmd_args[0]) > 0)
			i = ft_exec_found(env, cmd_args, cmd_args[0]);
		else
			i = ft_exec_not_found(env, cmd_args);
	}
	else
		i = ft_exec_found(env, cmd_args, cmd);
	if (i == 1)
		ft_printf("minishell: %s: %s\n", cmd_args[0], strerror(errno));
	else if (i == 2)
		ft_printf("minishell: %s: command not found\n", cmd_args[0]);
	sig_toggle(0);
	return (0);
}