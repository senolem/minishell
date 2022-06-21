/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stacksize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:13:51 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:58:42 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stacksize() function counts the number of elements of the stack
** passed as a parameter.
*/

#include "tok_stacks.h"

int	ft_tok_stacksize(t_tok_stack *stack)
{
	t_token	*current;
	int		counter;

	if (stack != NULL)
	{
		current = stack->top;
		counter = 0;
		while (current != NULL)
		{
			counter++;
			current = current->next;
		}
		return (counter);
	}	
	return (0);
}
