/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:04 by albaur            #+#    #+#             */
/*   Updated: 2022/07/19 20:57:27 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_clear(t_node *node, t_stack **av)
{
	t_node	*next;
	if (!node->prev)
	{
		if (node->next)
		{
			if (node->next->next)
				node->next->next->prev = node->next;
			next = node->next;
			free(node);
			node = next;
			node->prev = NULL;
		}
		else
		{
			free(node);
			node = NULL;
			(*av)->top = NULL;
		}
	}
	else
	{
		if (node->next)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			free(node);
		}
		else
		{
			node->prev->next = NULL;
			free(node);
		}
	}
}

static t_redir	ft_redir_data(int mode, int type, int fd)
{
	t_redir	redir;

	redir.mode = mode;
	redir.type = type;
	redir.fd = fd;
	return (redir);
}

int	redir_manager(t_stack **av, t_var *var, t_redir i)
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
	return (0);
}

int	ft_redir_parser(t_stack *av, t_var *var)
{
	size_t	i;
	t_node	*node;

	i = 0;
	if (!av || !av->top || !var)
		return (1);
	node = av->top;
	while (node && node->content)
	{
		if (!ft_tokcmp(node->content, greater_than_type))
		{
			i = redir_manager(&av, var, ft_redir_data(O_WRONLY | O_CREAT,
					greater_than_type, 1));
			node = av->top;
		}
		else if (!ft_tokcmp(node->content, smaller_than_type))
		{
			i = redir_manager(&av, var, ft_redir_data(O_RDONLY,
					smaller_than_type, 0));
			node = av->top;
		}
		else if (!ft_tokcmp(node->content, d_greater_than_type))
		{
			i = redir_manager(&av, var, ft_redir_data(O_WRONLY | O_CREAT | O_APPEND,
					d_greater_than_type, 1));
			node = av->top;
		}
		if (!node)
			break;
		if (i != 0)
			return (1);
//		else if (!ft_tokcmp(node->content, d_smaller_than_type))
//			ft_dst_manager(av, var);
		node = node->next;
	}
	return (0);
}
