/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/16 23:00:48 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipex_open(t_stack **stack, size_t i, t_var *var)
{
	if (stack[i + 1])
	{
		if (pipe(var->pipes) == -1)
		{
			perror("minishell: pipe");
			return (1);
		}
	}
	return (0);
}

int	pipex_close(t_stack **stack, size_t i, t_var *var)
{
	if (stack[i + 1])
		close(var->pipes[1]);
	if (i != 0 && stack[i - 1])
		close(var->pipes[0]);
	return (0);
}

int	child_process(t_stack **stack, size_t i, t_var *var)
{
	pid_t	pid;
	char	**args;

	pid = fork();
	if (pid)
		var->pid = pid;
	if (pid < 0)
	{
		perror("minishell: fork:");
		return (1);
	}
	if (pid == 0)
	{
		args = ft_lst_to_arr(stack[i]);
		pipex(stack, i, var);
		ft_exec(args, var);
		ft_arr_freer(args);
	}
	return (0);
}

void	pipex(t_stack **stack, size_t i, t_var *var)
{
	dup2(var->fd[0], STDOUT_FILENO);
	dup2(var->fd[1], STDIN_FILENO);
	if (stack[i + 1])
	{
		close(var->pipes[0]);
		dup2(var->pipes[1], var->fd[0]);
		close (var->pipes[1]);
	}
	if (i != 0 && stack[i - 1])
	{
		dup2(var->pipes[0], var->fd[1]);
		close(var->pipes[0]);
	}
}
