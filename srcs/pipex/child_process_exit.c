/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:25:59 by albaur            #+#    #+#             */
/*   Updated: 2022/07/20 15:21:55 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process_exit(int code)
{
	int		shlvl;
	char	*tmp;
	char	*err;
	int		ret;

	if (ft_atoi(env_get_arg("?EXIT")) != 0)
	{
		shlvl = env_get_shlvl();
		tmp = ft_itoa(shlvl - 1);
		err = env_get_arg("?EXIT");
		ret = ft_atoi(err);
		env_set_arg("SHLVL", tmp);
		env_set_arg("?", ft_itoa(WEXITSTATUS(code)));
		env_set_arg("?EXIT", "0");
		if (shlvl == 1)
			unlink(ENV_FILE);
		free(tmp);
		free(err);
		exit(ret);
	}
	else
	{
		env_set_arg("?", ft_itoa(WEXITSTATUS(code)));
	}
}
