/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:18:19 by faventur          #+#    #+#             */
/*   Updated: 2022/07/04 14:32:04 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_quote_checker_pt2(t_dollar *dollar)
{
	int	ret;

	if (!dollar->sq && !dollar->dq)
		ret = 0;
	else if (dollar->sq && !dollar->dq)
		ret = 1;
	else
		ret = 2;
	return (ret);
}

int	ms_quote_checker(t_token *token, ssize_t *index)
{
	t_dollar	dollar;

	dollar.i = 0;
	dollar.sq = 0;
	dollar.dq = 0;
	while (token->str[dollar.i] && dollar.i < *index)
	{
		if (token->str[dollar.i] == '\'' && !dollar.sq && !dollar.dq)
			dollar.sq++;
		else if (token->str[dollar.i] == '\'' && dollar.sq && !dollar.dq)
			dollar.sq--;
		else if (token->str[dollar.i] == '\"' && !dollar.dq && !dollar.sq)
			dollar.dq++;
		else if (token->str[dollar.i] == '\"' && !dollar.sq && dollar.dq)
			dollar.dq--;
		dollar.i++;
	}
	return (ms_quote_checker_pt2(&dollar));
}

ssize_t	ms_dollar_checker(t_token *token)
{
	ssize_t	i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '$' && (ft_isalnum(token->str[i + 1])
				|| token->str[i + 1] == '_'))
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_tokstrlen(t_token *token)
{
	size_t	i;

	if (!token || !token->str)
		return (0);
	while (token->str[i])
		i++;
	return (i);
}

void	ms_dollar_quote_eraser(t_stack *stack)
{
	t_node	*current;
	ssize_t	index;

	index = 0;
	current = stack->top;
	while (current)
	{
		index = ft_tokstrlen(current->content);
		if (index > 0 && (ms_quote_checker(current->content, &index) >= 0))
//			ms_dollar_quote_rewriter(current->content, &index);
			ft_printf("%d\n", ms_quote_checker(current->content, &index));
		current = current->next;
	}
}
