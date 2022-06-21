/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:09 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 16:00:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tokcmp(t_token *token, int type)
{
	if (token->type == type)
		return (0);
	return (1);
}

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

t_stack	*ft_tokenizer(char *line)
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
//	ft_stackclear(new, ft_delete);
	return (new);
}

void	token_manager(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && ft_tokcmp(current->content, squote_type))
	{
		if (!ft_tokcmp(current->content, squote_type))
			ft_stackdelone(current, ft_nodedel);
		current = current->next;
	}
}
