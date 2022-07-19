/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:43:28 by albaur            #+#    #+#             */
/*   Updated: 2022/07/18 22:22:27 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(char **s)
{
	size_t	i;
	int		fd;
	int		code;

	i = 0;
	code = 0;
	if (!s)
		exit(126);
	else if (ft_arrlen(s) > 2)
		return (ret_err("minishell: exit: too many arguments", NULL, 1));
	while (ft_arrlen(s) == 2 && s[1][i])
	{
		if (ft_isdigit(s[1][i]) == 0)
		{
			ft_printf("exit\n");
			ft_printf("minishell: exit: %s: numeric argument required\n", s[1]);
			code = 255;
		}
		++i;
	}
	if (ft_arrlen(s) == 2 && s[1][0] == '\0')
	{
		ft_printf("minishell: exit: %s: numeric argument required\n", s[1]);
		code = 255;
	}
	if (ft_arrlen(s) == 2)
		code = ft_atoi(s[1]);
	fd = open("/dev/stdin", O_WRONLY, 0777);
	ft_putendl_fd("exit", fd);
	close(fd);
	return (code);
}
