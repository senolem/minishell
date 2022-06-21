/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stackiter_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:26:49 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:58:06 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tok_stackiter_if() function iterates in the stack passed as a
** parameter and applies the f function to the content of any element
** the data of which is different from the reference data.
*/

#include "tok_stacks.h"

void	ft_tok_stackiter_if(t_tok_stack *stack, void (*f)(void *), void *data_ref,
		int (*cmp)())
{
	t_token	*current;

	if (!stack || !f)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		if (cmp(current->content, data_ref))
			f(current->content);
		current = current->next;
	}
}
