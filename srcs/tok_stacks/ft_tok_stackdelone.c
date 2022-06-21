/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stackdelone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:16:24 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:37:35 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackdelone() function frees the memory of the element passed
** as a parameter with the del function and free(3). The memory of next
** mustn't be freed.
*/

#include "tok_stacks.h"

void	ft_stackdelone(t_token *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	free(node);
}
