/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:46:09 by albaur            #+#    #+#             */
/*   Updated: 2022/07/04 16:50:58 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_tilde(char *path, char *tmp, char ***env)
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

static int	cd_exit(char **tmp, char ***env)
{
	perror("cd");
	free(tmp);
	ft_arr_freer(*env);
	return (1);
}

int	builtin_cd(char	**path)
{
	int		i;
	char	*tmp;
	char	**env;

	if (ft_arrlen(path) > 1)
	{
		ft_printf("cd: too many arguments\n");
		return (1);
	}
	i = 0;
	env = env_read(ENV_FILE);
	tmp = env_get("PWD", env);
	if (path[0][0] == '~')
		i = cd_tilde(path[0], tmp, &env);
	else
	{
		i = chdir(path[0]);
		if (i == 0)
		{
			env_set("OLDPWD", tmp, &env);
			env_set("PWD", path[0], &env);
		}
	}
	if (i != 0)
		return (cd_exit(&tmp, &env));
	env_write(ENV_FILE, env);
	free(tmp);
	ft_arr_freer(env);
	return (0);
}
