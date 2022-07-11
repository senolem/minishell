/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/11 16:40:46 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	ft_dst_manager(char **av, size_t *index)
{
	;
}
*/
void	ft_gt_manager(t_stack **av, size_t *index)
{
	;
}

void	ft_redir_parser(t_stack **av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (ft_strnstrbool(av[i], ">", 1))
			ft_gt_manager(av, &i);
//		else if (!ft_strnstrbool(av[i], "<", 1))
//			ft_dst_manager(av, &i);
//		else if (!ft_strnstrbool(av[i], ">>", 2))
//			ft_dgt_manager(av, &i);
//		else if (!ft_strnstrbool(av[i], "<<", 2))
//			ft_st_manager(av, &i);
		i++;
	}
}
