/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:11:14 by albaur            #+#    #+#             */
/*   Updated: 2022/06/25 17:17:49 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes_closed(char *str, int squote, int dquote)
{
	int		i;
	int		j;
	int		len;
	int		*qtmp;

	i = 0;
	j = 0;
	len = squote + dquote;
	qtmp = malloc(sizeof(int) * (len + 1));
	if (!qtmp)
		return (1);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			qtmp[j] = 1;
			++j;
		}
		else if (str[i] == '\"')
		{
			qtmp[j] = 2;
			++j;
		}
		++i;
	}
	qtmp[j] = '\0';
	i = 0;
	while (qtmp[i] != '\0')
	{
		if (i < len - 1 && qtmp[i] == qtmp[i + 1])
		{
			qtmp[i] = 3;
			qtmp[i + 1] = 3;
		}
		++i;
	}
	i = 0;
	while (qtmp[i] != '\0')
	{
		if (qtmp[i] == 1)
		{
			if (qtmp[(len - 1) - i] == 1)
			{
				qtmp[i] = 3;
				qtmp[(len - 1) - i] = 3;
			}
		}
		if (qtmp[i] == 2)
		{
			if (qtmp[(len - 1) - i] == 2)
			{
				qtmp[i] = 3;
				qtmp[(len - 1) - i] = 3;
			}
		}
		++i;
	}
	i = 0;
	while (qtmp[i] != '\0')
	{
		if (qtmp[i] != 3)
		{
			free(qtmp);
			return (1);
		}
		++i;
	}
	free(qtmp);
	return (0);
}

int	check_quotes(t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		squote;
	int		dquote;
	char	**split;

	i = 0;
	j = 0;
	split = ft_split(data->input, '|');
	if (!split)
		return (1);
	while (split[i])
	{
		k = 0;
		squote = 0;
		dquote = 0;
		while (split[i][k])
		{
			if (split[i][k] == '\'')
				++squote;
			else if (split[i][k] == '\"')
				++dquote;
			++k;
		}
		if (squote % 2 == 0 && dquote % 2 == 0)
			j += check_quotes_closed(split[i], squote, dquote);
		else
			return (1);
		++i;
	}
	free(split);
	return (j);
}

int	check_start(t_data *data)
{
	int	j;

	j = 0;
	j += check_quotes(data);
	if (j > 0)
	{
		ft_printf("Syntax error !\n");
		return (0);
	}
	return (1);
}
