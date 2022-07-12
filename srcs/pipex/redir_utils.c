/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:04 by albaur            #+#    #+#             */
/*   Updated: 2022/07/12 14:21:21 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redir_manager(t_stack **av, t_var *var, int mode, int type, int fd)
{
	t_node	*node;
	char	*path;

	node = (*av)->top;
	while (node)
	{
		if (!ft_tokcmp(node->content, type))
		{
			if (node->next)
				node = node->next;
			path = ft_lst_to_arrdup(node->content);
			printf("path = %s\n", path);
			var->fd[fd] = open(path, mode, 0644);
			if (var->fd[fd] < 0)
				throwback_error(strerror(errno), NULL, 0);
			free(path);
			return;
		}
		if (node->next)
			node = node->next;
	}
}

void ft_redir_parser(t_stack **av, t_var *var)
{
	size_t i;
	t_node *node;
	t_token *tmp;

	i = 0;
	var->fd[0] = -1;
	var->fd[1] = -1;
	while (av[i])
	{
		node = av[i]->top;
		while (node && node->content)
		{
			tmp = (t_token *)node->content;
			if (!ft_strnstrbool(tmp->str, ">", 1))
				redir_manager(&av[i], var, O_WRONLY | O_CREAT, greater_than_type, 1);
			else if (!ft_strnstrbool(tmp->str, "<", 1))
				redir_manager(&av[i], var, O_RDONLY, smaller_than_type, 0);
			else if (!ft_strnstrbool(tmp->str, ">>", 2))
				redir_manager(&av[i], var, O_WRONLY | O_CREAT | O_APPEND, d_greater_than_type, 1);
			//			else if (!ft_strnstrbool(tmp->str, "<<", 2))
			//				ft_dst_manager(av, var);
			node = node->next;
		}
		i++;
	}
}
