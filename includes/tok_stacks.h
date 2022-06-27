/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_stacks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:18:14 by faventur          #+#    #+#             */
/*   Updated: 2022/06/27 16:54:36 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_STACKS_H
# define TOK_STACKS_H

# include "minishell.h"
# include "stacks.h"

typedef struct s_token
{
	char	*str;
	int		type;
	size_t	index;
}				t_token;

// token types
enum e_lexer_type
{
	word_type = 1,
	greater_than_type,
	d_greater_than_type,
	smaller_than_type,
	d_smaller_than_type,
	pipe_type,
	and_type,
	or_type,
	slash_type,
	tilde_type,
	empty_type
};

#endif