/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:46:09 by albaur            #+#    #+#             */
/*   Updated: 2022/06/27 12:08:57 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_tilde(char *path, char *tmp, char ***env)
{
	int		i;
	char	*ptmp;

	i = 0;
	++path;
	ptmp = ft_strjoin(env_get("HOME", *env), path);
	i = chdir(ptmp);
	if (i == 0)
	{
		env_set("OLDPWD", tmp, env);
		env_set("PWD", ptmp, env);
	}
	free(ptmp);
	return (i);
}

void	cd(char	*path)
{
	int		i;
	char	*tmp;
	char	**env;

	i = 0;
	env = env_read(ENV_FILE);
	tmp = env_get("PWD", env);
	if (path[0] == '~')
		i = cd_tilde(path, tmp, &env);
	else
	{
		i = chdir(path);
		if (i == 0)
		{
			env_set("OLDPWD", tmp, &env);
			env_set("PWD", path, &env);
		}
	}
	if (i != 0)
	{
		perror("cd");
		return ;
	}
	env_write(ENV_FILE, env);
	free(tmp);
	free(env);
}
