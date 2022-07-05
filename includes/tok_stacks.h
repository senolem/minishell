/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_stacks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:18:14 by faventur          #+#    #+#             */
/*   Updated: 2022/07/05 10:26:45 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_STACKS_H
# define TOK_STACKS_H

# include "minishell.h"
# include "stacks.h"
# include "ft_btree.h"

typedef struct s_token
{
	char	*str;
	int		type;
	int		subtype;
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