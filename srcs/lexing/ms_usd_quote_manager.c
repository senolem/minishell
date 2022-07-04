/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_usd_quote_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:18:19 by faventur          #+#    #+#             */
/*   Updated: 2022/07/04 16:01:57 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_usd_quote_len(char *str, ssize_t *index, char quote)
{
	size_t	counter;

	counter = 0;
	if (str[*index] == quote)
		(*index)++;
	while (str[*index] && str[*index] != quote)
	{
		counter++;
		(*index)++;
	}
	if (str[*index] == quote)
		(*index)++;
	return (counter);
}

char	*ft_usd_quote_pruner(t_dollar *dollar, size_t *index,
			size_t *j)
{
	if (str[*index] == '\'')
	{
		quote[*j] = str[*index];
		(*index)++;
		(*j)++;
	}
	while (str[*index] && str[*index] != '\'')
	{
		quote[*j] = str[*index];
		(*j)++;
		(*index)++;
	}
	if (str[*index] == '\'' && str[*index + 1] != '\0')
	{
		quote[*j] = str[*index];
		(*index)++;
		(*j)++;
	}
	quote[*j] = '\0';
	return (quote);
}

int	ms_usd_quote_replacer(t_token *token, ssize_t *index, char quote)
{
	t_dollar	dollar;

	dollar.i = 0;
	dollar.j = 0;
	dollar.line = token->str;
//	dollar.len = ft_usd_quote_len(token->str, index, quote);
//	dollar.str = malloc(sizeof(char) * (dollar.len + 1));
	while (token->str[dollar.i] && dollar.i != '\0')
	{
		if (dollar.line[dollar.i] == '\'' || token->str[dollar.i] == '\"')
		{
			ft_usd_quote_len(char *str, ssize_t *index, char quote)
		}
		dollar.i++;
	}
	ft_strdel(&token->str);
	token->str = dollar.str;
	return (ms_usd_quote_checker_pt2(&dollar));
}

ssize_t	ms_dollar_quote_finder(t_token *token)
{
	ssize_t	i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '\'' || token->str[i] == '\"')
			return (i);
		i++;
	}
	return (-1);
}

void	ms_dollar_quote_eraser(t_stack *stack)
{
	t_node	*current;
	ssize_t	index;

	index = 0;
	current = stack->top;
	while (current)
	{
		index = ms_dollar_quote_finder(current->content);
		if (index >= 0)
			ms_usd_quote_replacer(current->content, &index);
		current = current->next;
	}
}
