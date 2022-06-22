/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_stacks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:18:14 by faventur          #+#    #+#             */
/*   Updated: 2022/06/22 16:34:18 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_STACKS_H
# define TOK_STACKS_H

# include "minishell.h"
# include "stacks.h"

typedef struct s_token
{
	char			*str;
	int				type;
	int				subtype;
	int				index;
}				t_token;

// token types
enum e_lexer_type
{
	str_type = 1,
	squote_type,
	dquote_type,
	greater_than_type,
	smaller_than_type,
	pipe_type,
	whitespace_type,
	newline_type,
	backslash_type,
	slash_type,
	tilde_type
};

#endif