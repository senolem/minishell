/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:50:10 by albaur            #+#    #+#             */
/*   Updated: 2022/07/06 17:05:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_lst_to_arrdup(t_token *token)
{
	char	*tmp;

	tmp = ft_strdup(token->str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	**ft_lst_to_arr(t_stack *stack)
{
	size_t	i;
	t_node	*tmp;
	char	**arr;
	int		len;

	i = 0;
	len = ft_stacksize(stack);
	tmp = stack->top;
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = 0;
	while (tmp)
	{
		arr[i] = ft_lst_to_arrdup(tmp->content);
		if (!arr[i])
		{
			ft_arr_freer_index(arr, &i);
			return (NULL);
		}
		tmp = tmp->next;
		++i;
	}
}
