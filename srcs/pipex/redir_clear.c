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

void	redir_clear(t_node *node, t_stack **av)
{
	t_node	*top;
	t_token	*token;
	int		i;

	t_token	*tmp2 = node->content;
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
	{
		token = top->content;
		if (top->next)
			(*av)->top = top->next;
		else
			(*av)->top = NULL;
		free(token->str);
		free(token);
		free(top);
	}
	else if (i == 1)
	{
		if (top->next)
			(*av)->top = top->next;
		else
			(*av)->top = NULL;
		if (top->next)
			top->next->prev = NULL;
		token = top->content;
		free(token->str);
		free(token);
		free(top);
	}
	else if (i > 1)
	{
		if (top->next)
			top->prev->next = top->next;
		else
			top->prev->next = NULL;
		token = top->content;
		free(token->str);
		free(token);
		free(top);
	}
}
