/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/22 21:57:13 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	ft_last_action(t_var var, int ac, char *av[])
{
	close(var.fd[1]);
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_TRUNC, 0644);
	if (var.fd[1] < 0)
		ft_puterror("Error: Impossible to open the file.");
	unlink(TMP_FILE);
}
*/

static void	manager_exit(t_var *var, t_stack **arr)
{
	ft_intarr_freer(var->pipes);
	ft_stacktab_clear(arr);
}

static void	init_fd(t_var *var)
{
	var->fd[0] = 0;
	var->fd[1] = 1;
}

int	pipe_manager(t_stack *stack)
{
	t_stack	**arr;
	t_var	var;
	size_t	j;
	size_t	len;

	j = -1;
	init_fd(&var);
	arr = ft_stack_splitter(stack);
	len = ft_stacktablen(arr);
	pipex_pipes(len, &var);
	while (arr[++j])
	{
		if (ft_redir_parser(arr[j], &var) == 1)
			break ;
		if (j != 0 && arr[j - 1] && ft_stacklen(arr[j - 1]) != 0)
			init_fd(&var);
		if (pipex_open(arr, j, &var) || child_process(arr, j, &var))
		{
			manager_exit(&var, arr);
			return (1);
		}
		pipex_close(arr, j, &var);
	}
	manager_exit(&var, arr);
	return (0);
}
