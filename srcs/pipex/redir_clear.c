/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:23:25 by albaur            #+#    #+#             */
/*   Updated: 2022/07/19 23:30:45 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redir_clear_1_1(t_node *node, t_stack **av)
{
	if (node->next->next)
		node->next->next->prev = node->next;
	node->next->prev = NULL;
	(*av)->top = node->next;
	free(node);
}

static void	redir_clear_1_2(t_node *node, t_stack **av)
{
	(*av)->top = NULL;
	free(node);
}

static void	redir_clear_2_1(t_node *node, t_stack **av)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	(*av)->top = node->prev;
	free(node);
}

static void	redir_clear_2_2(t_node *node, t_stack **av)
{
	node->prev->next = NULL;
	(*av)->top = node->prev;
	free(node);
}

void	redir_clear(t_node *node, t_stack **av)
{
	if (!node->prev)
	{
		if (node->next)
			redir_clear_1_1(node, av);
		else
			redir_clear_1_2(node, av);
	}
	else
	{
		if (node->next)
			redir_clear_2_1(node, av);
		else
			redir_clear_2_2(node, av);
	}
}
