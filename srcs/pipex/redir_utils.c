/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:04 by albaur            #+#    #+#             */
/*   Updated: 2022/07/19 18:00:56 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_clear(t_node *node)
{
	t_node	*next;
	t_node	*prev;

	next = NULL;
	prev = NULL;
	if (node->next && node->next->next)
		next = node->next->next;
	if (node->prev)
		prev = node->prev;
	if (next)
	{
		if (prev)
		{
			next->prev = prev;
			prev->next = next;
		}
		else
			next->prev = NULL;
	}
	else if (prev)
		prev->next = NULL;
	node = NULL;
}

static t_redir	ft_redir_data(int mode, int type, int fd)
{
	t_redir	redir;

	redir.mode = mode;
	redir.type = type;
	redir.fd = fd;
	return (redir);
}

void	redir_manager(t_stack **av, t_var *var, t_redir i)
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
			//faut remplacer ici dans le cas ou next existe pas
			//on est censé stop l'execution (parsing error)
			path = ft_lst_to_arrdup(node->content);
			var->fd[i.fd] = open(path, i.mode, 0644);
			if (var->fd[i.fd] < 0)
				ret_err(strerror(errno), NULL, 0);
			free(path);
			return ;
		}
		if (node->next)
			node = node->next;
	}
}

void	ft_redir_parser(t_stack *av, t_var *var)
{
	size_t	i;
	t_node	*node;

	i = 0;
	if (!av || !av->top || !var)
		return ;
	node = av->top;
	while (node && node->content)
	{
		if (!ft_tokcmp(node->content, greater_than_type))
			redir_manager(&av, var, ft_redir_data(O_WRONLY | O_CREAT,
					greater_than_type, 1));
		else if (!ft_tokcmp(node->content, smaller_than_type))
			redir_manager(&av, var, ft_redir_data(O_RDONLY,
					smaller_than_type, 0));
		else if (!ft_tokcmp(node->content, d_greater_than_type))
			redir_manager(&av, var, ft_redir_data(O_WRONLY | O_CREAT | O_APPEND,
					d_greater_than_type, 1));
//		else if (!ft_tokcmp(node->content, d_smaller_than_type))
//			ft_dst_manager(av, var);
		node = node->next;
	}
}
