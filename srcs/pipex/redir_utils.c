/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:24 by faventur          #+#    #+#             */
/*   Updated: 2022/07/06 16:32:30 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_gt_manager(char **av, int *index)
{
	
}

void	ft_redir_parser(char **av)
{
	size_t	i;

	while (av[i])
	{
		if (ft_strnstrbool(av[i], ">", 1))
			ft_gt_manager(av, &i);
		else if (!ft_strnstrbool(av[i], ">>", 2))
			ft_dgt_manager(av, &i);
		else if (!ft_strnstrbool(av[i], "<<", 2))
			ft_st_manager(av, &i);
		else if (!ft_strnstrbool(av[i], "<", 1))
			ft_dst_manager(av, &i);
		i++;
	}
}
