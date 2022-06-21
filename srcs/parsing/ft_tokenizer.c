/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:09 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 13:39:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_token_creator(char c, int index)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	ft_memset(token, 0, sizeof(*token));
	token->c = c;
	token->index = index;
	if (ft_isalnum(c))
		token->type = char_type;
	else if (c == '\\')
		token->type = backslash_type;
	else if (c == '\'')
		token->type = squote_type;
	else if (c == '\"')
		token->type = dquote_type;
	else if (c == '|')
		token->type = pipe_type;
	else if (c == '<')
		token->type = smaller_than_type;
	else if (c == '>')
		token->type = greater_than_type;
	else if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		token->type = whitespace_type;
	else if (c == '\n')
		token->type = newline_type;
	return (token);
}

void	ft_tokenizer(char *line)
{
	t_stack	*new;
	int		i;

	i = 0;
	new = ft_stacknew();
	while (line[i])
	{
		ft_stackadd_bottom(new, ft_newnode(ft_token_creator(line[i], i)));
		i++;
	}
	ft_stackiter(new, (void *)ft_putendl);
	ft_stackclear(new, ft_delete);
}
