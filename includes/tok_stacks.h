/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_stacks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:18:14 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 12:03:28 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_STACKS_H
# define TOK_STACKS_H

# include <minishell.h>

typedef struct s_token
{
	char			c;
	int				type;
	int				index;
}				t_token;

// token types
enum e_lexer_type
{
	squote_type,
	dquote_type,
	greater_than_type,
	smaller_than_type,
	pipe_type,
	char_type,
	white_space_type,
	newline_type,
	tab_type,
	backslash_type
};

#endif