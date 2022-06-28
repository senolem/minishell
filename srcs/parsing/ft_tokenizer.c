/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:09 by faventur          #+#    #+#             */
/*   Updated: 2022/06/28 23:36:55 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokdisplay(t_token *token)
{
	ft_printf("string: %s\ntype: %d\n", token->str, token->type);
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

t_token	*ft_token_creator(char *line, size_t line_index)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	if (!token)
		return (NULL);
	ft_memset(token, 0, sizeof(*token));
	token->str = ft_strdup(line);
	if (!token->str)
	{
		free(token);
		return (NULL);
	}
	token->index = line_index;
	if (!ft_strstrbool(line, "&&"))
		token->type = and_type;
	else if (!ft_strstrbool(line, "||"))
		token->type = or_type;
	else if (!ft_strstrbool(line, "|"))
		token->type = pipe_type;
	else if (!ft_strstrbool(line, "<<"))
		token->type = d_smaller_than_type;
	else if (!ft_strstrbool(line, "<"))
		token->type = smaller_than_type;
	else if (!ft_strstrbool(line, ">>"))
		token->type = d_greater_than_type;
	else if (!ft_strstrbool(line, ">"))
		token->type = greater_than_type;
	else if (line[0] == '\0')
		token->type = empty_type;
	else
		token->type = word_type;
	return (token);
}
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

t_stack	*ft_tokenizer(char *arr[])
{
	t_stack	*new;
	size_t	i;

	i = 0;
	new = ft_stacknew();
	while (arr[i])
	{
		ft_stackadd_bottom(new, ft_newnode(ft_token_creator(arr[i], i)));
		i++;
	}
	ft_stackiter(new, (void *)ft_tokdisplay);
//	ft_token_manager(new);
	ft_arr_freer(arr);
	return (new);
}
