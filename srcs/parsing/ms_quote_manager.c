/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/06/30 22:04:18 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The dquote_dollar_counter() function counts the amount of
 * characters of the name of the environment variable preceded by
 * the dollar ($) symbol in the string passed as a parameter.
 * 
 * The dquote_dollar_parser() function allocates (with malloc(3)) and
 * returns a "fresh" null-terminated string representing the the name
 * of the environment variable found in the string passed as a
 * parameter.
 * 
 * The ft_get_env() function takes an environment variable name as a
 * parameter and returns its content.
 * 
 * The dquote_dollar_replacer() function checks if the environment
 * variable name passed as a parameter corresponds to an existant
 * variable and, if it's the case, replaces it with its content
 * in the new string.
*/

#include "minishell.h"

char	*ft_get_env(char *varname)
{
	char	**arr;
	char	*str;

	arr = env_read(ENV_FILE);
	str = env_get(varname, arr);
	ft_arr_freer(arr);
	return (str);
}

void	dquote_dollar_counter(t_dollar dollar, size_t *index)
{
	t_dollar	dollar;

	dollar.varname_len = 0;
	while (dollar.line[*index] != '$')
		(*index)++;
	if (dollar.line[*index] == '$')
		(*index)++;
	while (dollar.line[*index] && !ms_check_charset(dollar.line[*index]))
	{
		dollar.varname_len++;
		(*index)++;
	}
}

void	dquote_dollar_parser(char *quote, char *line, size_t *index,
			size_t *j)
{
	t_dollar	dollar;
	char		*str;

	dollar.quote = quote;
	dollar.line = line;
	dollar.index = *index;
	dollar.j = *j;
	dquote_dollar_counter(dollar, &dollar.index);
	dollar.i = 0;
	str = malloc(sizeof(char) * (dollar.varname_len + 1));
	dollar.index -= dollar.varname_len;
	while (line[dollar.index] && !ms_check_charset(line[dollar.index]))
		str[dollar.i++] = line[dollar.index++];
	str[dollar.i] = '\0';
	dollar.varname = str;
	dquote_dollar_replacer(dollar);
}

char	*dquote_dollar_replacer(t_dollar dollar)
{
	char	*newstr;

	dollar.quote[*dollar.j] = '\0';
	dollar.var = ft_get_env(dollar.varname);
	if (dollar.var)
	{
		dollar.var_len = ft_strlen(dollar.var);
		dollar.quotelen = ft_strlen(dollar.quote) - dollar.varname_len
			+ dollar.var_len;
		newstr = malloc(sizeof(char) * (dollar.quotelen + 1));
		if (!newstr)
			return (NULL);
		ft_strcpy(newstr, dollar.quote);
		ft_strcat(newstr, dollar.var);
		free(dollar.quote);
		dollar.quote = newstr;
	}
	free(dollar.line);
	free(dollar.varname);
	free(dollar.var);
	return (dollar.quote);
}
