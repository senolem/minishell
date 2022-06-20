/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:38:55 by faventur          #+#    #+#             */
/*   Updated: 2022/06/18 18:24:01 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	between_squotes(char *str, int *index)
{
	int	counter;

	counter = 0;
	if (str[*index] == '\'')
		(*index)++;
	while (str[*index])
	{
		if (str[*index] == '\'' && ms_check_charset(str[*index + 1]))
		{
			counter++;
			break ;
		}
		else if (str[*index] == '\'' && !ms_check_charset(str[*index + 1]))
			break ;
		(*index)++;
	}
	return (counter);
}

int	squote_len_index(char *str, int *index)
{
	int	counter;

	counter = 0;
	if (str[*index] == '\'')
		(*index)++;
	while (str[*index] && str[*index] != '\'')
	{
		counter++;
		(*index)++;
	}
	if (str[*index] == '\'' && str[*index + 1] != '\0')
		(*index)++;
	return (counter);
}

char	*ft_squote_pruner_index(char *quote, char *str, int *index, int	*j)
{
	if (str[*index] == '\'')
		(*index)++;
	while (str[*index] && str[*index] != '\'')
	{
		quote[*j] = str[*index];
		(*j)++;
		(*index)++;
	}
	if (str[*index] == '\'' && str[*index + 1] != '\0')
		(*index)++;
	quote[*j] = '\0';
	return (quote);
}
