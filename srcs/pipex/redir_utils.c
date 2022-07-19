/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:04 by albaur            #+#    #+#             */
/*   Updated: 2022/07/19 14:47:26 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_manager(t_stack **av, t_var *var, int mode, int type, int fd)
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
			var->fd[fd] = open(path, mode, 0644);
			if (var->fd[fd] < 0)
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
			redir_manager(&av, var, O_WRONLY | O_CREAT,
				greater_than_type, 1);
		else if (!ft_tokcmp(node->content, smaller_than_type))
			redir_manager(&av, var, O_RDONLY,
				smaller_than_type, 0);
		else if (!ft_tokcmp(node->content, d_greater_than_type))
			redir_manager(&av, var, O_WRONLY | O_CREAT | O_APPEND,
				d_greater_than_type, 1);
//		else if (!ft_tokcmp(node->content, d_smaller_than_type))
//			ft_dst_manager(av, var);
		node = node->next;
	}
}
