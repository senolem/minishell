/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:43:28 by albaur            #+#    #+#             */
/*   Updated: 2022/07/13 17:48:36 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(char **str)
{
	size_t	i;

	i = 0;
	if (ft_arrlen(str) == 1)
		exit(1);
	else if (ft_arrlen(str) > 2)
	{
		ft_printf("minishell: exit: too many arguments\n");
		return (1);
	}
	while (str[1][i])
	{
		if (ft_isdigit(str[1][i]) == 0)
		{
			ft_printf("minishell: exit: %s: numeric argument required\n", str[1]);
			unlink(ENV_FILE);
			exit(EXIT_FAILURE);
		}
		++i;
	}
	unlink(ENV_FILE);
	exit(ft_atoi(str[1]));
}
