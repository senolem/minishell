/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:00:52 by faventur          #+#    #+#             */
/*   Updated: 2022/02/27 14:30:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strstr() function finds the first occurrence of the substring
** needle in the string haystack. The terminating null bytes are not
** compared.
** 
** Return Value: This function returns a pointer to the beginning of
** the substring, or NULL if the substring is not found.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	str_len;
	size_t	tofind_len;
	size_t	i;
	size_t	j;

	str_len = ft_strlen(haystack);
	tofind_len = ft_strlen(needle);
	i = 0;
	if (str_len < tofind_len)
		return (NULL);
	while (i <= str_len - tofind_len)
	{
		j = 0;
		while (j < tofind_len)
		{
			if (*(char *)(haystack + i + j) != *(char *)(needle + j))
				break ;
			j++;
		}
		if (j == tofind_len)
			return (&*(char *)(haystack + i));
		i++;
	}
	return (NULL);
}
