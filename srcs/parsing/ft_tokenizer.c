/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:09 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 12:04:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tok_stacks.h>

t_token *ft_tokenizer(char c, int index)
{
    t_token *tok;

    tok->c = c;
    tok->index = index;
	if (ft_isalnum(c))
        tok->type = char_type;
    return (tok);
}