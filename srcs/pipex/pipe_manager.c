/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/20 14:49:49 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int	ft_stacktablen(t_stack **stack)
{
	size_t	len;

	len = 0;
	while (stack[len])
		++len;
	return (len);
}

int	ft_stacklen(t_stack *stack)
{
	size_t	len;
	t_node	*node;

	node = stack->top;
	len = 0;
	while (node)
	{
		node = node->next;
		++len;
	}
	return (len);
}

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
	var.fd[0] = 0;
	var.fd[1] = 1;
	arr = ft_stack_splitter(stack);
	len = ft_stacktablen(arr);
	pipex_pipes(len, &var);
	while (arr[j])
	{
		if (ft_redir_parser(arr[j], &var) == 1)
			break ;
		if (j != 0 && arr[j - 1] && ft_stacklen(arr[j - 1]) != 0)
			var.fd[0] = 0;
		var.fd[1] = 1;
		if (pipex_open(arr, j, &var) || child_process(arr, j, &var))
			return (1);
		pipex_close(arr, j, &var);
		++j;
	}
	ft_stacktab_clear(arr);
	ft_intarr_freer(var.pipes);
	return (0);
}
