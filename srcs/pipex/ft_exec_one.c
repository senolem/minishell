/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:06:59 by albaur            #+#    #+#             */
/*   Updated: 2022/07/18 17:16:29 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_self_searcher_one(char **env, char **cmd_args)
{
	char		*args[3];
	char		*insidepwd;
	pid_t		pid;

	if (cmd_args[0][0] != '.')
		return (0);
	insidepwd = ft_strjoin(ft_strjoin(ft_getenv("PWD"), "/"), cmd_args[0]);
	args[0] = cmd_args[0];
	args[1] = insidepwd;
	args[2] = 0;
	if (!access(insidepwd, X_OK))
	{
		pid = fork();
		if (pid == 0)
			execve("/bin/bash", args, env);
		ft_arr_freer(env);
		free(insidepwd);
		return (1);
	}
	free(insidepwd);
	return (0);
}

int ft_exec_found_one(char **env, char **cmd_args, char *cmd, t_var *var)
{
	struct stat stats;
	pid_t		pid;

	(void)var;
	if (stat(cmd_args[0], &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode))
			return (3);
	}
	errno = 0;
	pid = fork();
	if (pid == 0)
		execve(cmd, cmd_args, env);
	else if (pid < 0)
	{
		perror("minishell: fork:");
		ft_arr_freer(env);
		return (1);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

int ft_exec_not_found_one(char **env, char **cmd_args)
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

int ft_exec_one(char **cmd_args, t_var *var)
{
	int i;
	char *cmd;
	char **env;

	i = 0;
	sig_toggle(1);
	if (cmd_args && tilde_searcher(cmd_args))
		tilde_replacer(cmd_args);
	if (builtin_launch(cmd_args) != -99 || !cmd_args || !cmd_args[0])
	{
		sig_toggle(0);
		return (0);
	}
	env = env_read(ENV_FILE);
	cmd = ft_path_searcher(cmd_args[0]);
	if (!cmd)
	{
		if (!access(cmd_args[0], X_OK) && ft_exec_min(cmd_args[0]) > 0)
			i = ft_exec_found_one(env, ft_exec_args(cmd_args), "/bin/bash", var);
		else
			i = ft_exec_not_found_one(env, cmd_args);
	}
	else
		i = ft_exec_found_one(env, cmd_args, cmd, var);
	ft_exec_error(i, cmd_args);
	sig_toggle(0);
	return (0);
}
