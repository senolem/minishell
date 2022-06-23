/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:52:22 by albaur            #+#    #+#             */
/*   Updated: 2022/06/23 14:38:05 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	**env;

	env = env_read(ENV_FILE);
	ft_putendl(env_get("PWD", env));
	free(env);
}
