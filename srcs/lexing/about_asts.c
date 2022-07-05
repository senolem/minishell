/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_asts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:23:02 by faventur          #+#    #+#             */
/*   Updated: 2022/07/05 10:28:23 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft(void *nb)
{
	*(int *)nb *= 5;
//	printf("%d\n", *(int *)nb);
}

int	from_stack_to_ast_converter()
{
	t_btree	*tree;
	
	tree = NULL;
	btree_insert_data(&tree, &a, cmp);
	btree_insert_data(&tree, &b, cmp);
	btree_insert_data(&tree, &c, cmp);
	btree_insert_data(&tree, &d, cmp);
	btree_insert_data(&tree, &f, cmp);
	btree_insert_data(&tree, &g, cmp);
	btree_insert_data(&tree, &l, cmp);
	printf("%d %d %d %d\n", *(int *)tree->item, *(int *)tree->right->item, *(int *)tree->right->left->item, *(int *)tree->right->right->item);
	printf("%d", btree_level_count(tree));
}
