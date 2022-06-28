/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/06/28 18:13:56 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The dquote_dollar_parser() function counts the number of characters
 * occupied by the name of the environment variable/s introduced by the
 * dollar ($) symbol.
 * 
 * The () function takes an environment variable name as a parameter
 * and returns its length.
 * 
 * The () function replaces an environment variable name with the length of the given
 * variable/s.
 * 
*/

#include "minishell.h"

size_t	dquote_dollar_parser(char *line, size_t *index)
{
	size_t	counter;

	counter = 0;
	while (line[*index] && (line != '$' || line[*index] != '\"'))
		(*index)++;
	if (line[*index] == '$')
	{
		(*index)++;
		counter++;
		while (line[*index] && !ms_check_charset(line[*index]))
		{
			counter++;
			(*index)++;
		}
	}
	return (counter);
}

size_t	dquote_dollar_parser(char *line, size_t *index)
{
	size_t	counter;

	counter = 0;
	while (line[*index] && (line != '$' || line[*index] != '\"'))
		(*index)++;
	if (line[*index] == '$')
	{
		(*index)++;
		while (line[*index] && !ms_check_charset(line[*index]))
		{
			counter++;
			(*index)++;
		}
	}
	return (counter);
}
