/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 14:28:26 by faventur         ###   ########.fr       */
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

char	*ms_dollar_replacer(t_dollar *dollar)
{
	char	*newstr;
	size_t	i;

	dollar->i = 0;
	dollar->var = ft_get_env(dollar->varname);
	if (dollar->var)
	{
		i = 0;
		dollar->var_len = ft_strlen(dollar->var);
		dollar->len = ft_strlen(dollar->line) - dollar->varname_len
			+ dollar->var_len;
		ft_printf("count %d\n", dollar->len);
		newstr = malloc(sizeof(char) * (dollar->len + 1));
		if (!newstr)
			return (NULL);
		while (dollar->line[dollar->i] && dollar->line[dollar->i] != '$')
			newstr[i++] = dollar->line[dollar->i++];
		if (dollar->line[dollar->i] == '$')
			newstr[i++] = '\0';
		ft_printf("here we go %s\n", newstr);
		ft_strcat(newstr, dollar->var);
		dollar->i += dollar->varname_len + 1;
		i = ft_strlen(newstr);
		newstr[i++] = dollar->line[dollar->i++];
		dollar->i++;
		ft_printf("here we go %s\n", newstr);
		free(dollar->line);
		ft_printf("here we go %s\n", newstr);
		dollar->line = newstr;
	}
	ft_strdel(&dollar->varname);
	return (dollar->line);
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
	ft_printf("%s\n", dollar.line);
}

void	ms_dollar_manager(t_stack *stack)
{
	t_node	*current;
	size_t	index;

	current = stack->top;
	index = -1;
	while (current && index < 0)
	{
		index = ms_dollar_checker(current->content);
		if (index >= 0 && (ms_quote_checker(current->content, &index) == 2
				|| !ms_quote_checker(current->content, &index)))
			ms_dollar_parser();
		current = current->next;
	}
}
