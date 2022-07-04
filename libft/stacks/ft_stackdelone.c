/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:16:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/04 12:34:06 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackdelone() function frees the memory of the element passed
** as a parameter with the del function and free(3). The memory of next
** mustn't be freed.
*/

#include "stacks.h"

void	ft_stackdelone(t_node *node, void (*del)(void *))
{
	t_node	*tmp;

	if (!node || !del)
		return ;
	tmp = node;
	if (node->next)
	{
		node = node->next;
		if (tmp->prev)
			node->prev = tmp->prev;
		else
			node->prev = NULL;
	}
	del(tmp->content);
	free(tmp);
}
