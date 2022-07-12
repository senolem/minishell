/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:16:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/12 17:13:49 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackdelone() function frees the memory of the element passed
** as a parameter with the del function and free(3). The memory of next
** mustn't be freed.
*/

#include "stacks.h"

void	ft_stackdelone(t_stack *stack, t_node *node, void (*del)(void *))
{
	t_node	*current;

	if (node != NULL)
	{
		current = stack->top;
		if (current->next == NULL)
		{
			stack->bottom = current->prev;
			stack->bottom->next = NULL;
		}
		else if (current->prev == NULL)
		{
			stack->top = current->next;
			stack->top->prev = NULL;
		}
		else
		{
			current->next->prev = current->prev;
			current->prev->next = current->next;
		}
		del(current->content);
		free(current);
	}
}
