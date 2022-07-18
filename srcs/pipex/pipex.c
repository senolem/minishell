/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/18 17:11:27 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipex_pipes(size_t len, t_var *var)
{
	size_t	i;

	i = 0;
	var->pipes = malloc(sizeof(int *) * (len + 1));
	while (i < len)
	{
		var->pipes[i] = malloc(sizeof(int) * 2);
		//var->pipes[i][0] = -1;
		//var->pipes[i][1] = -1;
		++i;
	}
	var->pipes[i] = 0;
}

int	pipex_open(t_stack **stack, size_t i, t_var *var)
{
	if (stack[i + 1])
	{
		if (pipe(var->pipes[i]) == -1)
		{
			perror("minishell: pipe");
			return (1);
		}
		ft_printf("fd popen: %d %d pipe %d %d\n", var->fd[0], var->fd[1], var->pipes[i][0], var->pipes[i][1]);
	}
	return (0);
}

int	pipex_close(t_stack **stack, size_t i, t_var *var)
{
	if (stack[i + 1])
	{
		close(var->pipes[i][1]);
	}
	if (i != 0 && stack[i - 1])
	{
		close(var->pipes[i - 1][0]);
	}
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
		ft_printf("fd popen: %d %d pipe %d %d\n", var->fd[0], var->fd[1], var->pipes[i][0], var->pipes[i][1]);
		ft_exec(args, var);
		ft_arr_freer(args);
	}
	waitpid(var->pid, NULL, 0);
	return (0);
}

void	pipex(t_stack **stack, size_t i, t_var *var)
{
	dup2(var->fd[1], STDOUT_FILENO);
	dup2(var->fd[0], STDIN_FILENO);
	if (stack[i + 1])
	{
		close(var->pipes[i][0]);
		dup2(var->pipes[i][1], var->fd[1]);
		close(var->pipes[i][1]);
	}
	if (i != 0 && stack[i - 1])
	{
		dup2(var->pipes[i - 1][0], var->fd[0]);
		close(var->pipes[i - 1][0]);
	}
}
