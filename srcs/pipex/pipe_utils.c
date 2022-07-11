/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:48:03 by faventur          #+#    #+#             */
/*   Updated: 2022/07/11 11:32:16 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	pipe_counter(t_stack *stack)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (ft_tokcmp(node->content, pipe_type))
			++i;
		node = node->next;
	}
	return (i);
}

int	parg_size(char *str, size_t i)
{
	int	counter;

	counter = 0;
	while (str[i])
	{
		if (str[i - 1] != '|' && str[i] == '|' && str[i + 1] != '|')
			break ;
		++counter;
		++i;
	}
	++counter;
	return (counter);
}
