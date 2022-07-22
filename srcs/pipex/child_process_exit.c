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
	int		ret;
	char	*tmp;
	char	*err;
	char	*str;

	str = ft_itoa(WEXITSTATUS(code));
	err = env_get_arg("?EXIT");
	ret = ft_atoi(err);
	if (ret != 0)
	{
		shlvl = env_get_shlvl();
		tmp = ft_itoa(shlvl - 1);
		env_set_arg("SHLVL", tmp);
		env_set_arg("?", str);
		env_set_arg("?EXIT", "0");
		if (shlvl == 1)
			unlink(ENV_FILE);
		free(str);
		free(err);
		free(tmp);
		exit(ret);
	}
	else
		env_set_arg("?", str);
	free(str);
	free(err);
}
