/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:41:11 by albaur            #+#    #+#             */
/*   Updated: 2022/06/23 14:38:05 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get_pwd(void)
{
	char	*pwd;
	char	**env;

	env = env_read(ENV_FILE);
	pwd = env_get("PWD", env);
	free(env);
	return (pwd);
}
