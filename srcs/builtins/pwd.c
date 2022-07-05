/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:52:22 by albaur            #+#    #+#             */
/*   Updated: 2022/07/04 16:51:09 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(char **str)
{
	char	**env;

	if (str)
	{
		ft_printf("pwd: too many arguments\n");
		return (1);
	}
	env = env_read(ENV_FILE);
	ft_putendl(env_get("PWD", env));
	ft_arr_freer(env);
	return (0);
}
