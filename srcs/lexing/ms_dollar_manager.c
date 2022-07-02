/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 16:40:12 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	ms_gate_keeper(t_token *token)
{
	size_t	i;
	
	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '$' && )
			
		i++;
	}
}
*/
void	ms_dollar_manager(t_stack *stack)
{
	t_node	*current;
	ssize_t	index;
	size_t	i;

	i = 0;
	index = 0;
	current = stack->top;
	ft_printf("ciao\n");
	while (current)
	{
		ft_printf("level: %d\nindex: %u\n", i, index);
		index = ms_dollar_checker(current->content);
		if (index >= 0 && (ms_quote_checker(current->content, &index) == 2
				|| !ms_quote_checker(current->content, &index)))
			ms_dollar_parser(current->content, &index);
		current = current->next;
		i++;
	}
}
