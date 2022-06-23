/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:46:13 by faventur          #+#    #+#             */
/*   Updated: 2022/06/23 13:52:59 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	between_dquotes(char *str, int *index)
{
	int	counter;

	counter = 0;
	if (str[*index] == '\"')
		(*index)++;
	while (str[*index])
	{
		printf("betdquotes isoper %d\n", ft_isoper(str[*index + 1]));
		if (str[*index] == '\"' && (ft_isoper(str[*index + 1])
					|| ms_check_charset(str[*index + 1])))
		{
			counter++;
			printf("betdquotes count %d\n", counter);
			return (counter);
		}
		else if (str[*index] == '\"' && !ms_check_charset(str[*index + 1]))
			break ;
		(*index)++;
	}
	return (counter);
}

int	dquote_len_index(char *str, int *index)
{
	int	counter;

	counter = 0;
	if (str[*index] == '\"')
		(*index)++;
	while (str[*index] && str[*index] != '\"')
	{
		counter++;
		(*index)++;
	}
	if (str[*index] == '\"' && str[*index + 1] != '\0')
		(*index)++;
	return (counter);
}

char	*ft_dquote_pruner_index(char *quote, char *str, int *index, int	*j)
{
	if (str[*index] == '\"')
		(*index)++;
	while (str[*index] && str[*index] != '\"')
	{
		quote[*j] = str[*index];
		(*j)++;
		(*index)++;
	}
	if (str[*index] == '\"' && str[*index + 1] != '\0')
		(*index)++;
	quote[*j] = '\0';
	return (quote);
}
