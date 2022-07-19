/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:04 by albaur            #+#    #+#             */
/*   Updated: 2022/07/20 00:09:35 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir	rdata(int mode, int type, int fd)
{
	t_redir	redir;

	redir.mode = mode;
	redir.type = type;
	redir.fd = fd;
	return (redir);
}

int	redir_fd(t_stack **av, t_var *var, t_redir i)
{
	t_node	*node;
	char	*path;

	node = (*av)->top;
	while (node)
	{
		if (!ft_tokcmp(node->content, i.type))
		{
			if (node->next)
				node = node->next;
			else
				return (ret_err("minishell: parse error", NULL, 1));
			path = ft_lst_to_arrdup(node->content);
			var->fd[i.fd] = open(path, i.mode, 0644);
			if (var->fd[i.fd] < 0)
				ret_err(strerror(errno), NULL, 0);
			redir_clear(node->prev, av);
			redir_clear(node, av);
			free(path);
			return (0);
		}
		if (node->next)
			node = node->next;
	}
	return (1);
}

int	ft_redir_parser(t_stack *av, t_var *var)
{
	size_t	i;
	t_node	*node;

	i = -1;
	if (!av || !av->top || !var)
		return (1);
	node = av->top;
	while (node && node->content)
	{
		if (!ft_tokcmp(node->content, greater_than_type))
			i = redir_fd(&av, var, rdata(513, greater_than_type, 1));
		else if (!ft_tokcmp(node->content, smaller_than_type))
			i = redir_fd(&av, var, rdata(0, smaller_than_type, 0));
		else if (!ft_tokcmp(node->content, d_greater_than_type))
			i = redir_fd(&av, var, rdata(521, d_greater_than_type, 1));
		else if (!ft_tokcmp(node->content, d_smaller_than_type))
			NULL;
		if (i == 0)
			node = av->top;
		if (i == 1)
			return (1);
		if (node)
			node = node->next;
	}
	return (0);
}
