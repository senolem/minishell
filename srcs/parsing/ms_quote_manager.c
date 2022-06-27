/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/06/27 16:44:36 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_checker(char *line)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			counter += between_squotes(line, &i);
		else if (line[i] == '\"')
			counter += between_dquotes(line, &i);
		i++;
	}
	return (counter);
}
