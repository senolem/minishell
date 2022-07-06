/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/06 18:56:03 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	ft_gt_manager(char **av, int *index)
{
	
}

void	ft_redir_parser(char **av)
{
	size_t	i;

	while (av[i])
	{
		if (ft_strnstrbool(av[i], ">", 1))
			ft_gt_manager(av, &i);
		else if (!ft_strnstrbool(av[i], ">>", 2))
			ft_dgt_manager(av, &i);
		else if (!ft_strnstrbool(av[i], "<<", 2))
			ft_st_manager(av, &i);
		else if (!ft_strnstrbool(av[i], "<", 1))
			ft_dst_manager(av, &i);
		i++;
	}
}
*/

t_stack	**ft_stack_splitter(t_stack *stack)
{
	t_stack	**arr;
	t_node	*current;
	size_t	counter;
	size_t	i;

	counter = pipe_counter(stack);
	arr = malloc(sizeof(*arr) * (counter + 2));
	current = stack->top;
	i = 0;
	if (counter)
	{
		while (current && counter)
		{
			arr[i] = ft_stacknew;
			if (ft_tokcmp(current->content, pipe_type))
			{
				ft_stackdelone(current, ft_nodedel);
				i++;
			}
			ft_stackadd_bottom(arr[i], current);
			current = current->next;
		}
		arr[i] = NULL;
		free(stack);
	}
	else
	{
		arr[0] = stack;
		arr[1] = NULL;
	}
	return (arr);
}
