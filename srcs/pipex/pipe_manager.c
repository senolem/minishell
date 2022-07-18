/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/18 16:57:12 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_last_action(t_var var, int ac, char *av[])
{
	close(var.fd[1]);
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_TRUNC, 0644);
	if (var.fd[1] < 0)
		ft_puterror("Error: Impossible to open the file.");
}

int	pipe_manager(t_stack *stack)
{
	t_stack	**arr;
	char	**av;
	t_var	var;
	size_t	j;
	size_t	len;

	j = 0;
	len = 0;
	arr = ft_stack_splitter(stack);
	len = 0;
	//ft_redir_parser(arr, &var);
	//ft_redir_del(arr);
	var.fd[0] = 0;
	var.fd[1] = 1;
	while (arr[len])
		++len;
	if (len == 1)
	{
		av = ft_lst_to_arr(arr[0]);
		ft_stackclear(arr[0], (void *)ft_tokdel);
		var.pid = fork();
		if (var.pid < 0)
		{
			perror("minishell: fork");
			exit(EXIT_FAILURE);
		}
		else if (var.pid == 0)
		{
			ft_exec(av, &var);
			ft_arr_freer(av);
		}
		else
		{
			close(0);
			close(1);
			waitpid(var.pid, NULL, 0);
		}
	}
	else if (len > 1) 
	{
		pipex_pipes(len, &var);
		while (arr[j])
		{
			if (pipex_open(arr, j, &var) == 1
				|| child_process(arr, j, &var) == 1)
				return (1);
			ft_printf("fd: %d %d pipe %d %d\n", var.fd[0], var.fd[1], var.pipes[j][0], var.pipes[j][1]);
			waitpid(var.pid, NULL, 0);
			pipex_close(arr, j, &var);
			++j;
		}
	}
	return (0);
}
