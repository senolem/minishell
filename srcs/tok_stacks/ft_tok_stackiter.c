/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stackiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:05:18 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:58:21 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tok_stackiter() function iterates in the stack passed as a parameter
** and applies the f function to the content of every element.
*/

#include "tok_stacks.h"

void	ft_tok_stackiter(t_tok_stack *stack, void (*f)(void *))
{
	t_token	*current;

	if (!stack || !f)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
