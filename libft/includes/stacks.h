/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:10:47 by faventur          #+#    #+#             */
/*   Updated: 2022/07/05 10:34:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft.h"

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	size_t			length;
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

// Doubly linked list functions
t_stack	*ft_stacknew(void);
t_stack	*ft_stackadd_top(t_stack *stack, t_node *new);
t_stack	*ft_stackadd_bottom(t_stack *stack, t_node *new);
t_stack	*ft_stackinsert(t_stack *stack, t_node *node, int position);
t_node	*ft_newnode(void *content);
char	**ft_create_chartab(t_stack *stack);
void	ft_stackdelone(t_node *node, void (*del)(void *));
void	ft_stackclear(t_stack *stack, void (*del)(void *));
void	ft_stackiter(t_stack *stack, void (*f)(void *));
void	ft_stacksort(t_stack *begin_list, int (*cmp)());
void	ft_stackiter_if(t_stack *stack, void (*f)(void *), void *data_ref,
			int (*cmp)());
void	ft_stack_remove_if(t_stack *begin_list, void *data_ref, int (*cmp)());
int		ft_stacksize(t_stack *stack);

#endif