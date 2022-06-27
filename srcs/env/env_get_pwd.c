/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:41:11 by albaur            #+#    #+#             */
/*   Updated: 2022/06/27 18:05:46 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get_pwd(void)
{
	char	*pwd;
	char	**env;

	env = env_read(ENV_FILE);
	pwd = env_get("PWD", env);
	ft_arr_freer(env);
	return (pwd);
}
