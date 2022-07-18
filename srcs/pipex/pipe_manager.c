/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/18 12:00:02 by albaur           ###   ########.fr       */
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

t_var	get_args(char ac, char *av[])
{
	t_var	var;

	var.fd[0] = open(av[1], O_RDONLY);
	if (var.fd[0] < 0)
		ft_printerror("pipex", av[1]);
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT, 0644);
	if (var.fd[1] < 0)
		ft_printerror("pipex", av[ac - 1]);
	return (var);
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
	var.fd[0] = 0;
	var.fd[1] = 1;
	while (arr[len])
		++len;
	if (len == 1)
	{
		av = ft_lst_to_arr(arr[0]);
		ft_stackclear(arr[0], (void *)ft_tokdel);
		ft_exec(av, &var);
		ft_arr_freer(av);
	}
	else if (len > 1) 
	{
		pipex_pipes(len, &var);
		while (arr[j])
		{
			//ft_stackclear(arr[j], (void *)ft_tokdel);
			if (pipex_open(arr, j, &var) == 1 || child_process(arr, j, &var) == 1)
				return (1);
			pipex_close(arr, j, &var);
			++j;
		}
	}
	return (0);
}
