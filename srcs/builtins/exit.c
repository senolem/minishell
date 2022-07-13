/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:43:28 by albaur            #+#    #+#             */
/*   Updated: 2022/07/13 17:58:02 by albaur           ###   ########.fr       */
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
		return (throwback_error("minishell: exit: too many arguments", NULL, 1));
	while (str[1][i])
	{
		if (ft_isdigit(str[1][i]) == 0)
		{
			ft_printf("exit\n");
			ft_printf("minishell: exit: %s: numeric argument required\n", str[1]);
			unlink(ENV_FILE);
			exit(EXIT_FAILURE);
		}
		++i;
	}
	if (str[1][0] == '\0')
		ft_printf("minishell: exit: %s: numeric argument required\n", str[1]);
	unlink(ENV_FILE);
	ft_printf("exit\n");
	exit(ft_atoi(str[1]));
}
