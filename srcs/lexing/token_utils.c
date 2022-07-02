/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:33:31 by faventur          #+#    #+#             */
/*   Updated: 2022/07/02 12:02:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokdel(t_token *tok)
{
	if (tok != NULL)
	{
		free(tok->str);
		tok->str = NULL;
		free(tok);
		tok = NULL;
	}
}

void	ft_tokdisplay(t_token *token)
{
	ft_printf("string: %s\ntype: %d\n", token->str, token->type);
}

int	ft_tokcmp(t_token *token, int type)
{
	if (token->type == type)
		return (0);
	return (1);
}
