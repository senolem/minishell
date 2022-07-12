/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/12 12:06:19 by faventur         ###   ########.fr       */
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
t_node	*ft_stack_swap(t_node *node)
{
	t_node	*delenda;

	if (node && node->next)
	{
		delenda = node;
		node = node->next;
		ft_stackdelone(delenda, ft_nodedel);
		return (node);
	}
	else
	{
		ft_stackdelone(node, ft_nodedel);
		return (NULL);
	}
}

t_stack	*ft_dgt_manager(t_stack *av, t_var *var)
{
	t_node	*node;
	char	*tmp;

	node = av->top;
	while (node && node->content)
	{
		if (!ft_tokcmp(node->content, d_greater_than_type))
		{
			node = ft_stack_swap(node);
			tmp = ft_lst_to_arrdup(node->content);
			if (!tmp)
				break ;
			var->fd[1] = open(tmp, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (var->fd[1] < 0)
				throwback_error(strerror(errno), NULL, 0);
			node = ft_stack_swap(node);
			free(tmp);
			break ;
		}
		node = node->next;
	}
	return (av);
}

t_stack	*ft_st_manager(t_stack *av, t_var *var)
{
	t_node	*node;
	char	*tmp;

	node = av->top;
	while (node && node->content)
	{
		if (!ft_tokcmp(node->content, smaller_than_type))
		{
			node = ft_stack_swap(node);
			tmp = ft_lst_to_arrdup(node->content);
			if (!tmp)
				break ;
			var->fd[0] = open(tmp, O_RDONLY);
			if (var->fd[0] < 0)
				throwback_error(strerror(errno), NULL, 0);
			node = ft_stack_swap(node);
			free(tmp);
			break ;
		}
		node = node->next;
	}
	return (av);
}

t_stack	*ft_gt_manager(t_stack *av, t_var *var)
{
	t_node	*node;
	char	*tmp;

	node = av->top;
	while (node && node->content)
	{
		if (!ft_tokcmp(node->content, greater_than_type))
		{
			node = ft_stack_swap(node);
			tmp = ft_lst_to_arrdup(node->content);
			if (!tmp)
				break ;
			var->fd[1] = open(tmp, O_WRONLY | O_CREAT, 0644);
			if (var->fd[1] < 0)
				throwback_error(strerror(errno), NULL, 0);
			node = ft_stack_swap(node);
			free(tmp);
			break ;
		}
		node = node->next;
	}
	return (av);
}

void	ft_redir_parser(t_stack **av, t_var *var)
{
	size_t	i;
	t_node	*node;
	t_token	*tmp;

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
			{
				av[i] = ft_gt_manager(*av, var);
				ft_printf("%d\n", 1);
				ft_tokdisplay(tmp);
			}
			if (!ft_strnstrbool(tmp->str, "<", 1))
			{
				av[i] = ft_st_manager(*av, var);
				ft_printf("%d\n", 1);
				ft_tokdisplay(tmp);
			}
			if (!ft_strnstrbool(tmp->str, ">>", 2))
				av[i] = ft_dgt_manager(*av, var);
//			if (!ft_strnstrbool(tmp->str, "<<", 2))
//				av[i] = ft_dst_manager(av, var);
			node = node->next;
		}
		i++;
	}
}
