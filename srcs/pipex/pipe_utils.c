/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:48:03 by faventur          #+#    #+#             */
/*   Updated: 2022/07/06 18:41:16 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	pipe_counter(t_stack *stack)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (ft_tokcmp(node->content, pipe_type))
			++i;
		node = node->next;
	}
	return (i);
}

int	parg_size(char *str, size_t i)
{
	int	counter;

	counter = 0;
	while (str[i])
	{
		if (str[i - 1] != '|' && str[i] == '|' && str[i + 1] != '|')
			break ;
		++counter;
		++i;
	}
	++counter;
	return (counter);
}

char	*parg_writer(char *dst, char *src, size_t *i)
{
	size_t	j;

	j = 0;
	while (src[*i])
	{
		dst[j] = src[*i];
		if (src[*i - 1] != '|' && src[*i] == '|' && src[*i + 1] != '|')
			break ;
		++(*i);
		++j;
	}
	++(*i);
	dst[j] = '\0';
	return (dst);
}

char	**parg_cut(char *str)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (pipe_counter(str) + 2));
	if (!arr)
		return (NULL);
	while (i < pipe_counter(str) + 1)
	{
		arr[i] = malloc(sizeof(char) * (parg_size(str, j)));
		if (!arr[i])
			return (NULL);
		arr[i] = parg_writer(arr[i], str, &j);
		++i;
	}
	arr[i] = NULL;
	return (arr);
}
