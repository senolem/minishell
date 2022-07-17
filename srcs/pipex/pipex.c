/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/17 17:57:58 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parent_process(t_var *var)
{
//	dup2(var->fd[1], STDOUT_FILENO);
//	close(var->fd[1]);
	close(var->end[1]);
	dup2(var->end[0], STDIN_FILENO);
	close(var->end[0]);
	waitpid(var->pid, NULL, 0);
}

static int	child_process(char **cmd_args, t_var *var, int fdin)
{
	(void)fdin;
//	dup2(var->fd[0], STDIN_FILENO);
//	close(var->fd[0]);
	close(var->end[0]);
	dup2(var->end[1], STDOUT_FILENO);
	close(var->end[1]);
	ft_fprintf(2, "ciao");
//	if (fdin == STDIN_FILENO)
//		exit(1);
	ft_fprintf(2, "rao");
	return (ft_exec(cmd_args, var));
}

void	pipex(char **cmd_args, t_var *var, int fdin)
{
	if (pipe(var->end) == -1)
		ft_printerror("pipex", cmd_args[0]);
	var->pid = fork();
	if (var->pid < 0)
	{
		close(var->end[0]);
		close(var->end[1]);
		ft_printerror("pipex", cmd_args[0]);
	}
	if (var->pid == 0)
	{
		ft_fprintf(2, "miao pipe");
		if (child_process(cmd_args, var, fdin) != 0)
			return ;
	}
	parent_process(var);
}
