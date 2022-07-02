/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:00:30 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 12:00:32 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_quote_checker_pt2(t_dollar *dollar)
{
	int	ret;

	if (!dollar->sq && !dollar->dq)
		ret = 0;
	else if (dollar->sq && !dollar->dq)
		ret = 1;
	else if (!dollar->sq && dollar->dq)
		ret = 2;
	free(dollar);
	return (ret);
}

int	ms_quote_checker(t_token *token, size_t *index)
{
	t_dollar	*dollar;

	dollar = (t_dollar *)malloc(sizeof(*dollar));
	dollar->i = 0;
	dollar->sq = 0;
	dollar->dq = 0;
	while (token->str[dollar->i] && dollar->i < *index)
	{
		if (token->str[dollar->i] == '\'' && !dollar->sq && !dollar->dq)
			dollar->sq++;
		if (token->str[dollar->i] == '\'' && !dollar->sq && dollar->dq)
			continue ;
		if (token->str[dollar->i] == '\'' && dollar->sq && !dollar->dq)
			dollar->sq--;
		if (token->str[dollar->i] == '\"' && !dollar->dq && !dollar->sq)
			dollar->dq++;
		if (token->str[dollar->i] == '\"' && !dollar->dq && dollar->sq)
			continue ;
		if (token->str[dollar->i] == '\"' && !dollar->sq && dollar->dq)
			dollar->dq--;
		dollar->i++;
	}
	return (ms_quote_checker_pt2(dollar));

}

int	ms_dollar_checker(t_token *token)
{
	size_t	i;

	i = 0;
	while (token->str)
	{
		if (token->str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}
