/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:22:29 by albaur            #+#    #+#             */
/*   Updated: 2022/07/13 23:00:58 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_concat(char *s1, char *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = ft_calloc((len_s1 + len_s2 + 1), sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, len_s1);
	ft_memcpy((dst + len_s1), s2, len_s2);
	free(s1);
	return (dst);
}

int	throwback_err(char *str, char *str2, int i)
{
	if (str2)
		ft_printf("%s %s\n", str, str2);
	else
		ft_printf("%s\n", str);
	return (i);
}

void	thrownull_error(char *str, char *str2)
{
	if (str2)
		ft_printf("%s %s\n", str, str2);
	else
		ft_printf("%s\n", str);
	return ;
}

void	throw_error(t_data *data, char *msg, int err)
{
	free(data);
	if (err != 0)
		errno = err;
	perror(msg);
	exit(EXIT_FAILURE);
}
