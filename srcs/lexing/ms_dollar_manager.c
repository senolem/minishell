/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 20:20:13 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_dollar_manager(t_stack *stack)
{
	t_node	*current;
	ssize_t	index;

	index = 0;
	current = stack->top;
	while (current)
	{
		index = ms_dollar_checker(current->content);
		if (index >= 0 && (ms_quote_checker(current->content, &index) == 2
				|| !ms_quote_checker(current->content, &index)))
			ms_dollar_parser(current->content, &index);
		else
			current = current->next;
	}
}
