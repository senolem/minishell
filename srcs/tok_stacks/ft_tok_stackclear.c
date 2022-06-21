/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stackclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:37 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:57:29 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tok_stackclear() function suppresses and frees the memory of the
** element passed as a parameter and of all the following elements by
** using the del function and free(3). Finally, the initial pointer is
** to be set to NULL.
*/

#include "tok_stacks.h"

void	ft_tok_stackclear(t_tok_stack *stack, void (*del)(void *))
{
	t_token	*temp;
	t_token	*delenda;

	if (!stack || !del)
		return ;
	delenda = stack->top;
	while (delenda != NULL)
	{
		temp = delenda->next;
		ft_tok_stackdelone(delenda, del);
		delenda = temp;
	}
}
