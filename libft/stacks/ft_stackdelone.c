/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:16:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/19 09:07:29 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackdelone() function frees the memory of the element passed
** as a parameter with the del function and free(3). The memory of next
** mustn't be freed.
*/

#include "stacks.h"

static void	ft_stackdelone_pt2(t_stack *stack, t_node *node)
{
	if (node->prev == NULL)
	{
		stack->top = node->next;
		if (stack->top)
			stack->top->prev = NULL;
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
}

void	ft_stackdelone(t_stack *stack, t_node *node, void (*del)(void *))
{
	if (!stack || !node || !stack->top || del)
		return ;
	if (node != NULL)
	{
		if (node->next == NULL)
		{
			stack->bottom = node->prev;
			if (stack->bottom)
				stack->bottom->next = NULL;
		}
		else
			ft_stackdelone_pt2(stack, node);
		del(node->content);
		node->content = NULL;
		free(node);
		node = NULL;
		node->next = NULL;
	}
}
