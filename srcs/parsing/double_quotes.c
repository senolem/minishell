/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:46:13 by faventur          #+#    #+#             */
/*   Updated: 2022/07/01 14:20:33 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between_dquotes(char *str, size_t *index)
{
	int			counter;

	counter = 0;
	if (str[*index] == '\"')
		(*index)++;
	while (str[*index])
	{
		if (str[*index] == '\"' && (ft_isoper(str[*index + 1])
				|| ms_check_charset(str[*index + 1])))
		{
			counter++;
			break ;
		}
		else if (str[*index] == '\"' && !ms_check_charset(str[*index + 1]))
			break ;
		(*index)++;
	}
	return (counter);
}

int	dquote_len_index(char *str, size_t *index)
{
	int	counter;

	counter = 0;
	if (str[*index] == '\"')
		(*index)++;
	while (str[*index] && str[*index] != '\"')
	{
		counter++;
		(*index)++;
	}
	if (str[*index] == '\"' && str[*index + 1] != '\0')
		(*index)++;
	return (counter);
}

char	*ft_dquote_pruner_index(char *quote, char *str, size_t *index,
			size_t *j)
{
	if (str[*index] == '\"')
		(*index)++;
	while (str[*index] && str[*index] != '\"')
	{
		if (str[*index] == '$')
		{
			dquote_dollar_parser(quote, str, index, j);
			if (str[*index] == '\"')
				break ;
			ft_printf("%d %c, %d %c, %s\n", *j, quote[*j], *index, str[*index], quote);
		}
		else
		{
			quote[*j] = str[*index];
			ft_printf("%c\n", quote[*j]);
			(*j)++;
			(*index)++;
		}
	}
	if (str[*index] == '\"' && str[*index + 1] != '\0')
		(*index)++;
	quote[*j] = '\0';
	ft_printf("quote %s\n", quote);
	return (quote);
}
