/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrbool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:00:52 by faventur          #+#    #+#             */
/*   Updated: 2022/07/20 14:37:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strstrbool() function finds the first occurrence of the substring
** needle in the string haystack. The terminating null bytes are not
** compared.
** 
** Return Value: This function returns 0 if the substring is found, 1 if
** it's not found.
**
** Notice: I created the strstrbool() function for use with my
** ft_stack_remove_if() function, that's why it returns a 0 where it
** should return a 1 and vice versa.
*/

#include "_functions.h"

int	ft_strstrbool(const char *haystack, const char *needle)
{
	t_cmp	var;

	if (!haystack || !needle)
		return (0);
	var.str_len = ft_strlen(haystack);
	var.tofind_len = ft_strlen(needle);
	var.i = 0;
	if (var.str_len < var.tofind_len)
		return (1);
	while (var.i <= var.str_len - var.tofind_len)
	{
		var.j = 0;
		while (var.j < var.tofind_len)
		{
			if (*(char *)(haystack + var.i + var.j)
				!= *(char *)(needle + var.j))
				break ;
			var.j++;
		}
		if (var.j == var.tofind_len)
			return (0);
		var.i++;
	}
	return (1);
}
