/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:16:24 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 15:24:48 by faventur         ###   ########.fr       */
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
	node = node->next;
	node->prev = tmp->prev;
	del(tmp->content);
	free(tmp);
}

static void	ft_stack_remove_if_pt2(t_stack *begin_list, void *data_ref,
	int (*cmp)())
{
	t_node	*current;
	t_node	*tmp;
	t_node	*prev;

	prev = begin_list->top;
	current = begin_list->top->next;
	while (current)
	{
		if (!cmp(current->content, data_ref))
		{
			tmp = current;
			current = current->next;
			prev->next = current;
			free(tmp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	ft_stack_remove_if(t_stack *begin_list, void *data_ref, int (*cmp)())
{
	t_node	*current;
	t_node	*tmp;

	if (begin_list == NULL)
		return ;
	current = begin_list->top;
	while (!cmp(data_ref, begin_list->top->content))
	{
		tmp = begin_list->top;
		begin_list->top = begin_list->top->next;
		free(tmp);
	}
	ft_stack_remove_if_pt2(begin_list, data_ref,
		cmp);
}
