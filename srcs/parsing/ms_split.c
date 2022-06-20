/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:51 by faventur          #+#    #+#             */
/*   Updated: 2022/06/18 18:26:16 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_check_charset(char c)
{
	if (ft_isspace(c) || c == '\0')
		return (1);
	return (0);
}

static int	wordgroup_counter(char *s)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			counter += between_squotes(s, &i);
		else if (s[i] == '\"')
			counter += between_dquotes(s, &i);
		else if (!ms_check_charset(s[i]) && ms_check_charset((s[i + 1])))
			counter++;
		i++;
	}
	return (counter);
}

static int	ms_let_count(char *str, int *index)
{
	int	counter;

	counter = 0;
	while (ms_check_charset(str[*index]))
		(*index)++;
	while (str[*index] && !ms_check_charset(str[*index]))
	{
		if (str[*index] == '\'')
			counter += squote_len_index(str, index);
		else if (str[*index] == '\"')
			counter += dquote_len_index(str, index);
		else
		{
			(*index)++;
			counter++;
		}
	}
	return (counter);
}

static char	*wordgroup_split(char *newstr, char *str, int *index)
{
	int	j;

	j = 0;
	while (ms_check_charset(str[*index]))
		(*index)++;
	while (str[*index] && !ms_check_charset(str[*index]))
	{
		if (str[*index] == '\'')
		{
			ft_squote_pruner_index(newstr, str, index, &j);
		}
		else if (str[*index] == '\"')
		{
			ft_dquote_pruner_index(newstr, str, index, &j);
		}
		else
			newstr[j++] = str[(*index)++];
	}
	newstr[j] = '\0';
	return (newstr);
}

char	**ms_split(char *s)
{
	char	**strtab;
	int		size;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	size = wordgroup_counter(s);
	strtab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strtab)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < size)
	{
		strtab[k] = malloc(sizeof(char) * (ms_let_count((char *)s, &i) + 1));
		if (!strtab[k])
			return (NULL);
		wordgroup_split(strtab[k++], (char *)s, &j);
	}
	strtab[k] = NULL;
	return (strtab);
}
