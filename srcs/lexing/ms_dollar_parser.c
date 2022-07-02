/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:16:18 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 17:15:56 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The dquote_dollar_counter() function counts the amount of characters
 * of the name of the environment variable preceded by the dollar ($)
 * symbol in the string passed as a parameter.
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

static void	ms_dollar_tailor(t_dollar *dollar)
{
	dollar->i = 0;
	dollar->j = 0;
	dollar->var_len = ft_strlen(dollar->var);
	dollar->len = ft_strlen(dollar->line) - (dollar->varname_len + 1)
		+ dollar->var_len;
	ft_printf("count %d\n", dollar->len);
	dollar->str = malloc(sizeof(char) * (dollar->len + 1));
	if (!dollar->str)
		return ;
	while (dollar->line[dollar->i] && dollar->line[dollar->i] != '$')
		dollar->str[dollar->j++] = dollar->line[dollar->i++];
	if (dollar->line[dollar->i] == '$')
		dollar->str[dollar->j] = '\0';
	ft_strcat(dollar->str, dollar->var);
	if (!dollar->str)
		return ;
	dollar->i += dollar->varname_len + 1;
	dollar->j = ft_strlen(dollar->str);
	dollar->str[dollar->j++] = dollar->line[dollar->i++];
	dollar->i++;
	ft_printf("here we go %s\n", dollar->str);
}

static char	*ms_dollar_replacer(t_dollar *dollar)
{
	dollar->var = ft_get_env(dollar->varname);
	if (dollar->var)
	{
		ms_dollar_tailor(dollar);
		ft_printf("here we go %s\n", dollar->str);
		free(dollar->line);
		ft_printf("here we go %s\n", dollar->str);
		dollar->line = dollar->str;
	}
	ft_strdel(&dollar->varname);
	return (dollar->line);
}

static int	ms_dollar_check_charset(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '\"')
		return (1);
	return (0);
}

static void	ms_dollar_counter(t_dollar *dollar, ssize_t *index)
{
	dollar->varname_len = 0;
	if (dollar->line[*index] == '$')
		(*index)++;
	ft_printf("%d %d\n", *index, dollar->varname_len);
	while (dollar->line[*index]
		&& !ms_dollar_check_charset(dollar->line[*index]))
	{
		ft_printf("boucle %d %d\n", *index, dollar->varname_len);
		dollar->varname_len++;
		(*index)++;
	}
}

void	ms_dollar_parser(t_token *token, ssize_t *index)
{
	t_dollar	dollar;

	dollar.line = token->str;
	ms_dollar_counter(&dollar, index);
	ft_printf("%d\n", dollar.varname_len);
	dollar.i = 0;
	dollar.varname = malloc(sizeof(char) * (dollar.varname_len + 1));
	*index -= dollar.varname_len;
	while (dollar.line[*index] && !ms_dollar_check_charset(dollar.line[*index]))
		dollar.varname[dollar.i++] = dollar.line[(*index)++];
	dollar.varname[dollar.i] = '\0';
	ft_printf("%d, %s\n", dollar.varname_len, dollar.varname);
	token->str = ms_dollar_replacer(&dollar);
	ft_printf("line:\n%s\n%s\n", dollar.line, token->str);
}
