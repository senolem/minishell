/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:28:56 by faventur          #+#    #+#             */
/*   Updated: 2022/06/20 20:35:59 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdupcat(const char *s1, const char *s2)
{
	char	dst;

	dst = (char *)malloc(sizeof(char)
			* (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}

char	*ft_strnstrbool(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && !needle[0])
		return (0);
	if (ft_strlen(haystack) < ft_strlen(needle) || len < ft_strlen(needle))
		return (1);
	while (i <= ft_strlen(haystack) - ft_strlen(needle) && i < len)
	{
		j = 0;
		while (j < ft_strlen(needle) && i + j < len)
		{
			if (*(char *)(haystack + i + j) != *(char *)(needle + j))
				break ;
			j++;
		}
		if (j == ft_strlen(needle))
			return (0);
		i++;
	}
	return (1);
}

char	**cd(t_data data)
{
	t_stack	*new;
	t_node	*current;
	char	**args;
	char	**arr;
	char	*temp;
	int		i;

	i = 0;
	new = ft_stacknew();
	args = split(data.av, ' ');
	while (data.env[i])
	{
		ft_stackadd_bottom(new, ft_newnode(ft_strdup(data.env[i])));
		i++;
	}
	while (current)
	{
		if (!ft_strstrbool(current->content, "OLDPWD"))
		{
			temp = current->content;
			current->content = ft_strdupcat(temp, args[2]); //apres CD
			free(temp);
		}
		if (ft_strnstrbool(current->content, "PWD=", 4))
		{
			temp = current->content;
			current->content = ft_strdupcat(temp, args[2]);	//apres CD
			free(temp);
		}
	}
	ft_stackclear(new, ft_delete);
	return (arr);
}
