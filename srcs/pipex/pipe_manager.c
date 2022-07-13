/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/13 11:22:13 by faventur         ###   ########.fr       */
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

	j = 0;
	/*
	if (!ft_strstrbool(av[1], "here_doc"))
	{
		var = hd_managing(ac, av);
		i = 3;
	}
	*/
	arr = ft_stack_splitter(stack);
	ft_redir_parser(arr, &var);
	ft_redir_del(arr);
	if (arr[1] == NULL)
	{
		av = ft_lst_to_arr(arr[0]);
		ft_stackclear(arr[0], (void *)ft_tokdel);
		ft_exec(av);
		ft_arr_freer(av);
	}
	else
	{
		while (arr[j + 1])
		{
			av = ft_lst_to_arr(arr[j]);
			ft_stackclear(arr[j], (void *)ft_tokdel);
			pipex(av);
			ft_arr_freer(av);
			j++;
		}
	/*
		ft_last_action(var, ac, av);
	*/
		av = ft_lst_to_arr(arr[j]);
		ft_exec(av);
		ft_arr_freer(av);
	}
	return (0);
}
