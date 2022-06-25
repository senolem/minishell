/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:36 by albaur            #+#    #+#             */
/*   Updated: 2022/06/25 17:19:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isoper(char c)
{
	if (c == '<')
		return (1);
	if (c == '|')
		return (2);
	if (c == '>')
		return (3);
	if (c == '&')
		return (4);
	return (0);
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

