/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:43:28 by albaur            #+#    #+#             */
/*   Updated: 2022/07/18 14:43:03 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(char **s)
{
	size_t	i;

	i = 0;
	if (ft_arrlen(s) == 1)
		exit(1);
	else if (ft_arrlen(s) > 2)
		return (ret_err("minishell: exit: too many arguments", NULL, 1));
	while (s[1][i])
	{
		if (ft_isdigit(s[1][i]) == 0)
		{
			ft_printf("exit\n");
			ft_printf("minishell: exit: %s: numeric argument required\n", s[1]);
			unlink(ENV_FILE);
			exit(EXIT_FAILURE);
		}
		++i;
	}
	if (s[1][0] == '\0')
		ft_printf("minishell: exit: %s: numeric argument required\n", s[1]);
	unlink(ENV_FILE);
	ft_printf("exit\n");
	exit(ft_atoi(s[1]));
}
