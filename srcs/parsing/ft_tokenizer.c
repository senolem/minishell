/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:09 by faventur          #+#    #+#             */
/*   Updated: 2022/06/22 17:26:35 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	subcategorize(t_token *token, int subtype)
{
	token->subtype = subtype;
}

int	ft_tokcmp(t_token *token, int type)
{
	if (token->type == type)
		return (0);
	return (1);
}

t_node	*token_parser(t_stack *stack, int type)
{
	t_node	*current;

	current = stack->top;
	while (current->next)
	{
		if (ft_tokcmp(current->content, type))
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*
static void	ft_token_creator_pt2(t_token *token, char c)
{
	if (c == '\n')
		token->type = newline_type;
	else if (c == '~')
		token->type = tilde_type;
	else if (c == '/')
		token->type = slash_type;
}

t_token	*ft_token_creator(char *line, int line_index)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	ft_memset(token, 0, sizeof(*token));
	token->word = ft_strdup(line);
	token->index = line_index;
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
	else
		ft_token_creator_pt2(token, c);
	return (token);
}
*/
/*
// je cree une liste d'elements que je vais inserer dans ma liste chainee apres coup
t_node	*ft_tokstr_parser(t_token *tok, char c)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = 0;
	str = malloc(sizeof(char) * count);
	while (tok->str && ft_isalnum(tok->str))
		i++;
	while (tok->str && !ft_isalnum(tok->str))
	{
		if (tok->str[i] == '>')
		{
			count++;
			i++;
			if (tok->str[i] == '>')
			{
				count++;
				break ;
			}
		}
		i++;
	}
	str = malloc(sizeof(char) * (count + 1));
	while (count--)
		str[count] = '>';
}

void	ft_token_manager(t_stack *stack)
{
	t_node	*current;
	t_token	*temp;

	current = stack->top;
	while (current)
	{
		temp = (t_token *)current->content;
		if ()	// function for parsing a token->str
	}
}
*/
t_token	*ft_word_creator(char *line, int line_index)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	ft_memset(token, 0, sizeof(*token));
	token->str = ft_strdup(line);
	token->index = line_index;
	token->type = str_type;
	return (token);
}

t_stack	*ft_tokenizer(char *arr[])
{
	t_stack	*new;
	int		i;

	i = 0;
	new = ft_stacknew();
	while (arr[i])
	{
		ft_stackadd_bottom(new, ft_newnode(ft_word_creator(arr[i], i)));
		i++;
	}
//	ft_token_manager(new);
	ft_arr_freer(arr);
	return (new);
}