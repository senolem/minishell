/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/06/18 19:02:06 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quote_checker(char *line)
{
	int	i;
	int	counter;

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
