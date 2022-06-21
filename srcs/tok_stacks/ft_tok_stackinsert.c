/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stackinsert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:14 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:54:46 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tok_stacks.h"

static void	ft_toklinker(t_tok_stack *stack, t_token *current, t_token *new)
{
	if (current->next == NULL)
	{
		stack = ft_tok_stackadd_bottom(stack, new);
	}
	else if (current->prev == NULL)
	{
		stack = ft_tok_stackadd_top(stack, new);
	}
	else
	{
		current->next->prev = new;
		current->prev->next = new;
		new->prev = current->prev;
		new->next = current;
		stack->length++;
	}
}

t_tok_stack	*ft_tok_stackinsert(t_tok_stack *stack, t_token *node, int position)
{
	t_token	*temp;
	int		i;

	if (stack != NULL && node != NULL)
	{
		temp = stack->top;
		i = 1;
		while (temp != NULL && i <= position)
		{
			if (position == i)
				ft_tokenlinker(stack, temp, node);
			else
				temp = temp->next;
			i++;
		}
	}
	return (stack);
}
