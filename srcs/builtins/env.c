/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:38:25 by albaur            #+#    #+#             */
/*   Updated: 2022/07/01 15:12:48 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(void)
{
	char	**env;
	size_t	i;

	env = env_read(ENV_FILE);
	i = 0;
	while (env[i])
	{
		if (env[i][0] == '!')
			continue ;
		else
			ft_printf("%s\n", env[i]);
		++i;
	}
	ft_arr_freer(env);
}
