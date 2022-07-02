/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:00:30 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 20:20:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_dollar_check_charset(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '\"')
		return (1);
	return (0);
}

void	ms_dollar_counter(t_dollar *dollar, ssize_t *index)
{
	dollar->varname_len = 0;
	if (dollar->line[*index] == '$')
		(*index)++;
	while (dollar->line[*index]
		&& !ms_dollar_check_charset(dollar->line[*index]))
	{
		dollar->varname_len++;
		(*index)++;
	}
}

int	ms_quote_checker_pt2(t_dollar *dollar)
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
//		else if (token->str[dollar.i] == '\'' && !dollar.sq && dollar.dq)
//			;
		else if (token->str[dollar.i] == '\'' && dollar.sq && !dollar.dq)
			dollar.sq--;
		else if (token->str[dollar.i] == '\"' && !dollar.dq && !dollar.sq)
			dollar.dq++;
//		else if (token->str[dollar.i] == '\"' && !dollar.dq && dollar.sq)
//			;
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
