/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:42 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 15:17:38 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The dquote_dollar_counter() function counts the amount of characters
 * of the name of the environment variable preceded by the dollar ($)
 * symbol in the string passed as a parameter.
 * 
 * The dquote_dollar_parser() function allocates (with malloc(3)) and
 * returns a "fresh" null-terminated string representing the the name
 * of the environment variable found in the string passed as a
 * parameter.
 * 
 * The ft_get_env() function takes an environment variable name as a
 * parameter and returns its content.
 * 
 * The dquote_dollar_replacer() function checks if the environment
 * variable name passed as a parameter corresponds to an existant
 * variable and, if it's the case, replaces it with its content
 * in the new string.
*/

#include "minishell.h"

void	ms_dollar_manager(t_stack *stack)
{
	t_node	*current;
	size_t	index;

	current = stack->top;
	index = -1;
	while (current && index < 0)
	{
		index = ms_dollar_checker(current->content);
		if (index >= 0 && (ms_quote_checker(current->content, &index) == 2
				|| !ms_quote_checker(current->content, &index)))
			ms_dollar_parser(current->content, &index);
		current = current->next;
	}
}
