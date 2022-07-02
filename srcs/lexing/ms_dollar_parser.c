/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:16:18 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 15:18:34 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_dollar_measurer(t_dollar *dollar)
{
	dollar->i = 0;
	dollar->j = 0;
	dollar->var_len = ft_strlen(dollar->var);
	dollar->len = ft_strlen(dollar->line) - dollar->varname_len
		+ dollar->var_len;
}

static char	*ms_dollar_replacer(t_dollar *dollar)
{
	dollar->var = ft_get_env(dollar->varname);
	if (dollar->var)
	{
		ms_dollar_measurer(dollar);
		ft_printf("count %d\n", dollar->len);
		dollar->str = malloc(sizeof(char) * (dollar->len + 1));
		if (!dollar->str)
			return (NULL);
		while (dollar->line[dollar->i] && dollar->line[dollar->i] != '$')
			dollar->str[dollar->j++] = dollar->line[dollar->i++];
		if (dollar->line[dollar->i] == '$')
			dollar->str[dollar->j++] = '\0';
		ft_printf("here we go %s\n", dollar->str);
		ft_strcat(dollar->str, dollar->var);
		dollar->i += dollar->varname_len + 1;
		dollar->j = ft_strlen(dollar->str);
		dollar->str[dollar->j++] = dollar->line[dollar->i++];
		dollar->i++;
		ft_printf("here we go %s\n", dollar->str);
		free(dollar->line);
		ft_printf("here we go %s\n", dollar->str);
		dollar->line = dollar->str;
	}
	ft_strdel(&dollar->varname);
	return (dollar->line);
}

static int	ms_dollar_charset_checker(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '\"')
		return (1);
	return (0);
}

static void	ms_dollar_counter(t_dollar *dollar, size_t *index)
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

void	ms_dollar_parser(t_token *token, size_t *index)
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
	token->str = dquote_dollar_replacer(&dollar);
	ft_printf("line:\n%s\n%s\n", dollar.line, token->str);
}
