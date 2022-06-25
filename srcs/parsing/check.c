/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:11:14 by albaur            #+#    #+#             */
/*   Updated: 2022/06/25 18:22:48 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_quotes_populate(int *qtmp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
}

void	check_quotes_siblings(int *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i < len - 1 && str[i] == str[i + 1])
		{
			str[i] = 3;
			str[i + 1] = 3;
		}
		++i;
	}
}

void	check_quotes_parallel(int *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 1)
		{
			if (str[(len - 1) - i] == 1)
			{
				str[i] = 3;
				str[(len - 1) - i] = 3;
			}
		}
		if (str[i] == 2)
		{
			if (str[(len - 1) - i] == 2)
			{
				str[i] = 3;
				str[(len - 1) - i] = 3;
			}
		}
		++i;
	}
}

int	check_quotes_closed(char *str, int squote, int dquote)
{
	int		i;
	int		len;
	int		*qtmp;

	i = 0;
	len = squote + dquote;
	qtmp = malloc(sizeof(int) * (len + 1));
	if (!qtmp)
		return (1);
	check_quotes_populate(qtmp, str);
	check_quotes_siblings(qtmp, len);
	check_quotes_parallel(qtmp, len);
	i += check_quotes_end(qtmp);
	free(qtmp);
	return (i);
}

int	check_quotes(t_data *data)
{
	t_check	c;

	c.i = -1;
	c.j = 0;
	c.split = ft_split(data->input, '|');
	if (!c.split)
		return (1);
	while (c.split[++c.i])
	{
		c.k = -1;
		c.squote = 0;
		c.dquote = 0;
		check_quotes_count(c.split[c.i], &c.squote, &c.dquote);
		if (c.squote % 2 == 0 && c.dquote % 2 == 0)
			c.j += check_quotes_closed(c.split[c.i], c.squote, c.dquote);
		else
			return (1);
	}
	free(c.split);
	return (c.j);
}
