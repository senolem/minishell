/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_asts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:23:02 by faventur          #+#    #+#             */
/*   Updated: 2022/07/05 12:22:34 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	from_stack_to_ast_converter(t_btree *root, void *item)
{
	t_btree *new;

	new = btree_create_node(item);
}
*/

t_btree	*ft_list_scroller(t_stack *stack)
{
	t_btree	*tree;
	t_node	*current;

	current = stack->top;
	tree = NULL;
	while (current)
	{
		btree_data_inserter(&tree, current->content);
		current = current->next;
	}
	return (tree);
}

void	btree_data_inserter(t_btree **root, t_token *token)
{
	t_btree	*new;

	new = btree_create_node(token);
	if (root)
	{
		if (*root)
		{
			if (ft_tok_classifier(token) < 10)
			{
				if ((*root)->left)
					btree_data_inserter(&(*root)->left, token);
				else
					(*root)->left = new;
			}
			else
			{
				if ((*root)->right)
					btree_data_inserter(&(*root)->right, token);
				else
					(*root)->right = new;
			}
		}
		else
			*root = new;
	}
}
