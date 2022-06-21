/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_stacks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:18:14 by faventur          #+#    #+#             */
/*   Updated: 2022/06/21 10:55:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_STACKS_H
# define TOK_STACKS_H

# include <minishell.h>

typedef struct s_tok_stack
{
	size_t			length;
	struct s_node	*top;
	struct s_node	*bottom;
}				t_tok_stack;

typedef struct s_token
{
	char			c;
	int				type;
	int				index;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

// Doubly linked list functions
t_tok_stack	*ft_tok_stacknew(void);
t_tok_stack	*ft_tok_stackadd_top(t_tok_stack *stack, t_token *new);
t_tok_stack	*ft_tok_stackadd_bottom(t_tok_stack *stack, t_token *new);
t_tok_stack	*ft_tok_stackinsert(t_tok_stack *stack, t_token *node,
				int position);
t_token		*ft_newtok(void *content);
void		ft_tok_stackdelone(t_token *node, void (*del)(void *));
void		ft_tok_stackclear(t_tok_stack *stack, void (*del)(void *));
void		ft_tok_stackiter(t_tok_stack *stack, void (*f)(void *));
void		ft_tok_stackiter_if(t_tok_stack *stack, void (*f)(void *),
				void *data_ref, int (*cmp)());
void		ft_tok_stack_remove_if(t_tok_stack *begin_list,
				void *data_ref, int (*cmp)());
int			ft_tok_stacksize(t_tok_stack *stack);

#endif