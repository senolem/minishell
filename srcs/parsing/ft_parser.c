/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:01:06 by faventur          #+#    #+#             */
/*   Updated: 2022/07/25 17:16:58 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ret_parse_err(t_token *token)
{
	if (token && token->str)
		ft_printf("minishell: syntax error near unexpected token '%s'\n",
			token->str);
	return (258);
}

int	ft_parser(t_stack *stack)
{
	t_node	*current;
	size_t	i;

	current = stack->top;
	i = 0;
	if (!ft_tokcmp(current->content, pipe_type))
		return (ret_parse_err(current->content));
	while (current)
	{
		if (!ft_tokcmp(current->content, and_type)
			|| !ft_tokcmp(current->content, or_type))
			return (ret_parse_err(current->content));
		else if ((!ft_tokcmp(current->content, greater_than_type)
				|| !ft_tokcmp(current->content, smaller_than_type)
				|| !ft_tokcmp(current->content, d_greater_than_type)
				|| !ft_tokcmp(current->content, d_smaller_than_type))
			&& (!current->next
				|| !ft_tokcmp(current->next->content, greater_than_type)
				|| !ft_tokcmp(current->next->content, smaller_than_type)
				|| !ft_tokcmp(current->next->content, d_greater_than_type)
				|| !ft_tokcmp(current->next->content, d_smaller_than_type)))
			return (ret_parse_err(current->content));
		else if (!ft_tokcmp(current->content, pipe_type) && (!current->next
				|| !ft_tokcmp(current->next->content, pipe_type)
				|| !ft_tokcmp(current->next->content, and_type)))
			return (ret_parse_err(current->content));
		current = current->next;
	}
	return (0);
}
