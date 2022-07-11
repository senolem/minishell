/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/11 17:25:55 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void ft_dst_manager(char **av, t_var *var)
{
	var->fd[0] = open(av[1], O_RDONLY);
	if (var->fd[0] < 0)
		ft_printerror("pipex", av[1]);
}
*/
void ft_dgt_manager(t_stack *av, t_var *var)
{
	t_node *node;
	t_node *tmp;
	char *tmp2;
	node = av->top;
	while (node)
	{
		if (!ft_tokcmp(node->content, d_greater_than_type))
		{
			tmp = node;
			node = node->next;
			ft_stackdelone(tmp, ft_nodedel);
			tmp2 = ft_lst_to_arrdup(node->content);
			var->fd[1] = open(tmp2, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (var->fd[1] < 0)
				throwback_error(strerror(errno), NULL, 0);
			ft_stackdelone(node, ft_nodedel);
			free(tmp2);
			break;
		}
		node = node->next;
	}
}

void	ft_st_manager(t_stack *av, t_var *var)
{
	t_node *node;
	t_node *tmp;
	char *tmp2;
	node = av->top;
	while (node)
	{
		if (!ft_tokcmp(node->content, smaller_than_type))
		{
			tmp = node;
			node = node->next;
			ft_stackdelone(tmp, ft_nodedel);
			tmp2 = ft_lst_to_arrdup(node->content);
			var->fd[0] = open(tmp2, O_RDONLY);
			if (var->fd[1] < 0)
				throwback_error(strerror(errno), NULL, 0);
			ft_stackdelone(node, ft_nodedel);
			free(tmp2);
			break;
		}
		node = node->next;
	}
}

void	ft_gt_manager(t_stack *av, t_var *var)
{
	t_node	*node;
	t_node	*tmp;
	char	*tmp2;
	node = av->top;
	while (node)
	{
		if (!ft_tokcmp(node->content, greater_than_type))
		{
			tmp = node;
			node = node->next;
			ft_stackdelone(tmp, ft_nodedel);
			tmp2 = ft_lst_to_arrdup(node->content);
			var->fd[1] = open(tmp2, O_WRONLY | O_CREAT, 0644);
			if (var->fd[1] < 0)
				throwback_error(strerror(errno), NULL, 0);
			ft_stackdelone(node, ft_nodedel);
			free(tmp2);
			break ;
		}
		node = node->next;
	}
}

void	ft_redir_parser(t_stack **av, t_var *var)
{
	size_t	i;
	t_node	*node;
	t_token	*tmp;

	i = 0;
	node = (*av)->top;
	while (av[i])
	{

		while (node)
		{
			tmp = node->content;
			if (ft_strnstrbool(tmp->str, ">", 1))
				ft_gt_manager(*av, var);
			else if (!ft_strnstrbool(tmp->str, "<", 1))
				ft_st_manager(*av, var);
			else if (!ft_strnstrbool(tmp->str, ">>", 2))
				ft_dgt_manager(*av, var);
			// else if (!ft_strnstrbool(tmp->str, "<<", 2))
			//	ft_dst_manager(av, var);
			node = node->next;
		}
		i++;
	}
}
