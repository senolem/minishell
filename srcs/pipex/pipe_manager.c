/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/07/11 13:20:06 by faventur         ###   ########.fr       */
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
//	char	**av;
//	t_var	var;
	//size_t	i;
	size_t	j;

	j = 0;
	/*
	if (!ft_strstrbool(av[1], "here_doc"))
	{
		var = hd_managing(ac, av);
		i = 3;
	}
	else
	{
		var = get_args(ac, av);
		i = 2;
	}
	ft_redir_parser(stack);
	*/
	arr = ft_stack_splitter(stack);
	while (arr[j])
	{
		ft_printf("boucle, %d\n", j);
		ft_stackiter(arr[j], (void *)ft_tokdisplay);
		ft_stackclear(arr[j], (void *)ft_tokdel);
//		av = ft_lst_to_arr(arr[j]); // on peut retravailler pour avoir un char**
//		pipex(av[j], var.fd[0]);
//		ft_arr_freer(av);
		j++;
	}
	/*
	while (i < ac - 2)
		pipex(av[i++], 1);
	ft_last_action(var, ac, av);
	ft_exec(av[i]);
	*/
	return (0);
}
