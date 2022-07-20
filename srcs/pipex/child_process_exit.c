/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:25:59 by albaur            #+#    #+#             */
/*   Updated: 2022/07/20 12:19:11 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process_exit(int code)
{
	int		shlvl;
	char	*tmp;
	char	*err;

	if (ft_atoi(env_get_arg("?EXIT")) != 0)
	{
		shlvl = env_get_shlvl();
		tmp = ft_itoa(shlvl - 1);
		env_set_arg("SHLVL", tmp);
		env_set_arg("?", ft_itoa(WEXITSTATUS(code)));
		err = env_get_arg("?EXIT");
		env_set_arg("?EXIT", "0");
		if (shlvl == 1)
			unlink(ENV_FILE);
		exit(ft_atoi(err));
	}
	else
	{
		env_set_arg("?", ft_itoa(WEXITSTATUS(code)));
	}
}