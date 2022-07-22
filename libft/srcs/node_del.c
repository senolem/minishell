/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:12:55 by albaur            #+#    #+#             */
/*   Updated: 2022/07/22 21:15:45 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	clear_gt1(t_node *top)
{
	t_token	*token;

	if (top->next)
	{
		top->prev->next = top->next;
		top->next->prev = top->prev;
	}
	else
		top->prev->next = NULL;
	token = top->content;
	free(token->str);
	free(token);
	free(top);
}

static void	clear_eq1(t_node *top)
{
	t_token	*token;
	
	if (top->next)
	{
		top->prev->next = top->next;
		top->next->prev = top->prev;
	}
	else
		top->prev->next = NULL;
	token = top->content;
	free(token->str);
	free(token);
	free(top);
}

static void	clear_eq0(t_stack **av, t_node *top)
{
	t_token	*token;

	token = top->content;
	if (top->next)
	{
		top->next->prev = NULL;
		(*av)->top = top->next;
	}
	else
		(*av)->top = NULL;
	free(token->str);
	free(token);
	free(top);
}

void	node_del(t_node *node, t_stack **av)
{
	int		i;
	t_node	*top;

	i = -1;
	top = (*av)->top;
	while (top)
	{
		++i;
		if (top == node)
			break ;
		top = top->next;
	}
	if (i == -1)
		return ;
	else if (i == 0)
		clear_eq0(av, top);
	else if (i == 1)
		clear_eq1(top);
	else if (i > 1)
		clear_gt1(top);
}
