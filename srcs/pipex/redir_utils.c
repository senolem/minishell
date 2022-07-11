/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/11 15:38:08 by albaur           ###   ########.fr       */
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
void	ft_stack_splitter_pt2(t_stack *stack, t_stack **arr)
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
			ft_stackdelone(delenda, ft_nodedel);
			ft_stackadd_bottom(arr[i], NULL);
			i++;
			arr[i] = ft_stacknew();
			continue ;
		}
		ft_tokdisplay(current->content);
		ft_stackadd_bottom(arr[i], current);
		current = current->next;
	}
	ft_stackadd_bottom(arr[i], NULL);
	arr[++i] = NULL;
	free(stack);
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
