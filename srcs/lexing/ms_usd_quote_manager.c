/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_usd_quote_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:18:19 by faventur          #+#    #+#             */
/*   Updated: 2022/07/11 16:10:30 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_usd_quote_counter(char *str, size_t *i, size_t *counter, char quote)
{
	if (str[*i] == quote)
	{
		(*counter)++;
		(*i)++;
	}
	while (str[*i] != quote)
		(*i)++;
	if (str[*i] == quote)
	{
		(*counter)++;
		(*i)++;
	}
}

size_t	ft_usd_quote_len(char *str)
{
	size_t	counter;
	size_t	i;

	if (!str)
		return (0);
	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ft_usd_quote_counter(str, &i, &counter, '\'');
		else if (str[i] == '\"')
			ft_usd_quote_counter(str, &i, &counter, '\"');
		else
			i++;
	}
	return (counter);
}

void	ft_usd_quote_pruner(t_dollar *dollar, char quote)
{
	if (dollar->line[dollar->i] == quote)
		dollar->i++;
	while (dollar->line[dollar->i] && dollar->line[dollar->i] != quote)
	{
		dollar->str[dollar->j] = dollar->line[dollar->i];
		printf("j %zu %c\n", dollar->j, dollar->str[dollar->j]);
		dollar->j++;
		dollar->i++;
	}
	if (dollar->line[dollar->i] == quote)
		dollar->i++;
	printf("j2 %zu\n", dollar->j);
	dollar->str[dollar->j] = '\0';
}

void	ms_usd_quote_replacer(t_token *token)
{
	t_dollar	dollar;

	dollar.i = 0;
	dollar.j = 0;
	dollar.line = token->str;
	dollar.len = ft_strlen(dollar.line)
		- ft_usd_quote_len(dollar.str);
	dollar.str = malloc(sizeof(char) * (dollar.len + 1));
	while (dollar.line[dollar.i])
	{
		if (dollar.line[dollar.i] == '\'')
			ft_usd_quote_pruner(&dollar, '\'');
		else if (dollar.line[dollar.i] == '\"')
			ft_usd_quote_pruner(&dollar, '\"');
		else
			dollar.str[dollar.j++] = dollar.line[dollar.i++];
	}
	dollar.str[dollar.j] = '\0';
	ft_strdel(&token->str);
	token->str = dollar.str;
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
			ms_usd_quote_replacer(current->content);
		current = current->next;
	}
}
