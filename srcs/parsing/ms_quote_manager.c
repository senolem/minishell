/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/06/30 18:39:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The dquote_dollar_parser() function counts the number of characters
 * occupied by the name of the environment variable introduced by the
 * dollar ($) symbol and creates a malloc(3) and returns .
 * 
 * The () function takes an environment variable name as a parameter
 * and returns its length.
 * 
 * The () function replaces an environment variable name with the length
 * of the given variable.
 * 
*/

#include "minishell.h"
/*
char	*dquote_dollar_parser(char *quote, char *line, size_t *index)
{
	char	**arr;
	char	*str;
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	if (line[*index] == '$')
		(*index)++;
	while (line[*index] && !ms_check_charset(line[*index]))
	{
		counter++;
		(*index)++;
	}
	str = malloc(sizeof(char) * (counter + 1));
	*index -= counter;
	while (line[*index] && !ms_check_charset(line[*index]))
		str[i++] = line[(*index)++];
	str[i] = '\0';
	arr = env_read(ENV_FILE);
	if (env_get(str, arr))
		dquote_dollar_replacer()
	free()
	return (NULL);
}

void	dquote_dollar_replacer(char *varname, char *quote, char *line,
			size_t *index)
{
	char	**arr;
	char	*newstr;
	size_t	quotelen;
	size_t	len;

	arr = env_read(ENV_FILE);
	if (env_get(varname, arr))
	{
		len = ft_strlen(env_get(varname, arr));
		if (line[*index] == '$')
		{
			quotelen = ft_strlen(quote);
			quote -= dquote_dollar_parser(line);
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
}
*/