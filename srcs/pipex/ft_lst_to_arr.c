/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:50:10 by albaur            #+#    #+#             */
/*   Updated: 2022/07/13 12:00:06 by faventur         ###   ########.fr       */
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

	if (!stack)
		return (NULL);
	i = 0;
	tmp = stack->top;
	arr = malloc(sizeof(char *) * (ft_stacksize(stack) + 1));
	if (!arr)
		return (NULL);
	arr[ft_stacksize(stack)] = 0;
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
	return (arr);
}
