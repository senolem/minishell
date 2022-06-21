/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:43 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:55:51 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_newnode() function allocates (with malloc(3)) and returns a
** new "fresh" element. The "content" member variable is initialised to
** the value of the "content" parameter. The "next" variable is
** set to NULL.
*/

#include "tok_stacks.h"

t_token	*ft_newnode(void *content)
{
	t_token	*stack;

	stack = malloc(sizeof(*stack));
	if (stack == NULL)
		return (NULL);
	stack->content = content;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}
