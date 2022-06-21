/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stackadd_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:52:37 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:57:03 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tok_stackadd_top() function adds the new element on top of the stack
** passed as a parameter.
*/

#include "tok_stack.h"

t_tok_stack	*ft_tok_stackadd_top(t_tok_stack *stack, t_token *new)
{
	if (stack != NULL && new != NULL)
	{
		if (stack->bottom == NULL)
		{
			new->next = NULL;
			stack->top = new;
			stack->bottom = new;
		}
		else
		{
			stack->top->prev = new;
			new->next = stack->top;
			stack->top = new;
		}
		stack->length++;
	}
	return (stack);
}
