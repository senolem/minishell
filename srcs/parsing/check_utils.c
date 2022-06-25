/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:17:17 by albaur            #+#    #+#             */
/*   Updated: 2022/06/25 18:17:52 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes_end(int *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 3)
			return (1);
		++i;
	}
	return (0);
}

void	check_quotes_count(char *str, int *squote, int *dquote)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			++*squote;
		else if (str[i] == '\"')
			++*dquote;
		++i;
	}
}
