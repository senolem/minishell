/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_stack_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:49:33 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:56:18 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tok_stack_remove_if() function removes from the passed list any
** element the data of which is "equal" to the reference data.
*/

#include "tok_stacks.h"

static void	ft_tok_stack_remove_if_pt2(t_tok_stack *begin_list, void *data_ref,
	int (*cmp)())
{
	t_token	*current;
	t_token	*tmp;
	t_token	*prev;

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

void	ft_tok_stack_remove_if(t_tok_stack *begin_list, void *data_ref, int (*cmp)())
{
	t_token	*current;
	t_token	*tmp;

	if (begin_list == NULL)
		return ;
	current = begin_list->top;
	while (!cmp(data_ref, begin_list->top->content))
	{
		tmp = begin_list->top;
		begin_list->top = begin_list->top->next;
		free(tmp);
	}
	ft_tok_stack_remove_if_pt2(begin_list, data_ref,
		cmp);
}
