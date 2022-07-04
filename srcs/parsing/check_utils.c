/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:11:14 by albaur            #+#    #+#             */
/*   Updated: 2022/07/04 14:58:50 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_quote_checker_pt2(int *sq, int *dq)
{
	int	ret;

	if (!*sq && !*dq)
		ret = 0;
	else if (*sq && !*dq)
		ret = 1;
	else
		ret = 2;
	return (ret);
}

static int	ft_quote_checker(char *str, size_t *index)
{
	size_t	i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (str[i] && i < *index)
	{
		if (str[i] == '\'' && !sq && !dq)
			sq++;
		else if (str[i] == '\'' && sq && !dq)
			sq--;
		else if (str[i] == '\"' && !dq && !sq)
			dq++;
		else if (str[i] == '\"' && !sq && dq)
			dq--;
		i++;
	}
	return (ft_quote_checker_pt2(&sq, &dq));
}

int	check_quotes(char *str)
{
	size_t	index;

	index = ft_strlen(str);
	if (index > 0)
		return (ft_quote_checker(str, &index));
	return (0);
}
