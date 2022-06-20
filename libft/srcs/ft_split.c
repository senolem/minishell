/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:21:03 by faventur          #+#    #+#             */
/*   Updated: 2022/02/28 16:26:41 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strsplit() function allocates (with malloc(3)) and returns
** an array of "fresh" null-terminated strings (and the array will
** be null-terminated too) resulting from the splitting of the string
** passed as a parameter based on the character c. If the allocation
** fails, the function returns NULL.
*/

#include "libft.h"

static int	ft_check_charset(char c, char set)
{
	if (c == set || c == '\0')
		return (1);
	return (0);
}

static int	ft_word_counter(const char *s, char set)
{
	int		counter;
	char	*str;

	counter = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		if (!ft_check_charset(*str, set) && ft_check_charset(*(str + 1), set))
			counter++;
		str++;
	}
	return (counter);
}

static int	let_count(char *str, char set, int *index)
{
	int	j;

	j = 0;
	while (ft_check_charset(str[*index], set))
		(*index)++;
	while (str[*index] && !ft_check_charset(str[*index], set))
	{
		j++;
		(*index)++;
	}
	return (j);
}

static char	*ft_word_split(char	*newstr, char *str, char set, int *index)
{
	int	j;

	j = 0;
	while (ft_check_charset(str[*index], set))
		(*index)++;
	while (str[*index] && !ft_check_charset(str[*index], set))
		newstr[j++] = str[(*index)++];
	newstr[j] = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char	**strtab;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	strtab = (char **)malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!strtab)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < ft_word_counter(s, c))
	{
		strtab[k] = malloc(sizeof(char) * (let_count((char *)s, c, &i) + 1));
		if (!strtab[k])
			return (NULL);
		ft_word_split(strtab[k++], (char *)s, c, &j);
	}
	strtab[k] = NULL;
	return (strtab);
}
