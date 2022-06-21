/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:41:11 by albaur            #+#    #+#             */
/*   Updated: 2022/06/21 10:56:40 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*env_get_pwd(char *path)
{
	char	*pwd;
	char	**env;

	env = env_read(path);
	pwd = env_get("PWD", env);
	free(env);
	return (pwd);
}