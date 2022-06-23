/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:36 by albaur            #+#    #+#             */
/*   Updated: 2022/06/23 14:36:02 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_oper_writer_index(char *quote, char *str, int *index, int *j)
{
	char	oper;

	oper = str[*index];
	while (str[*index] && str[*index] == oper)
	{
		quote[*j] = str[*index];
		(*j)++;
		(*index)++;
	}
	quote[*j] = '\0';
	return (quote);
}

int	oper_len_index(char *str, int *index)
{
	int		counter;
	char	oper;

	oper = str[*index];
	counter = 0;
	while (str[*index] && str[*index] == oper)
	{
		counter++;
		(*index)++;
	}
	return (counter);
}

int	ft_isoper(char c)
{
	if (c == '<')
		return (1);
	if (c == '|')
		return (2);
	if (c == '>')
		return (3);
	return (0);
}
