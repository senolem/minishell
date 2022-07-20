/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_splitter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:39:16 by faventur          #+#    #+#             */
/*   Updated: 2022/07/19 14:08:27 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_stack_splitter_pt2(t_stack *stack, t_stack **arr)
{
	t_node	*current;
	t_node	*delenda;
	size_t	i;

	current = stack->top;
	i = 0;
	arr[i] = ft_stacknew();
	while (current)
	{
		if (!ft_tokcmp(current->content, pipe_type))
		{
			delenda = current;
			current = current->next;
			ft_stackdelone(stack, delenda, ft_nodedel);
			current->prev->next = NULL;
			i++;
			if (current && ft_tokcmp(current->content, pipe_type))
				arr[i] = ft_stacknew();
			continue ;
		}
		ft_stackadd_bottom(arr[i], current);
		current = current->next;
	}
	arr[++i] = NULL;
}

t_stack	**ft_stack_splitter(t_stack *stack)
{
	t_stack	**arr;
	size_t	counter;

	counter = pipe_counter(stack);
	arr = malloc(sizeof(*arr) * (counter + 2));
	if (counter)
		ft_stack_splitter_pt2(stack, arr);
	else
	{
		arr[0] = stack;
		arr[1] = NULL;
	}
	return (arr);
}
