/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/19 14:37:51 by faventur         ###   ########.fr       */
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
	t_var	var;
	size_t	j;
	size_t	len;

	j = 0;
	len = 0;
	arr = ft_stack_splitter(stack);
	var.fd[0] = 0;
	var.fd[1] = 1;
	while (arr[len])
		++len;
	pipex_pipes(len, &var);
	while (arr[j])
	{
		ft_redir_parser(arr[j], &var);
		if (pipex_open(arr, j, &var) == 1
			|| child_process(arr, j, &var) == 1)
			return (1);
		pipex_close(arr, j, &var);
		++j;
	}
	ft_stacktab_clear(arr);
	ft_intarr_freer(var.pipes);
	return (0);
}
