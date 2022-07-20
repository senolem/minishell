/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:25:59 by albaur            #+#    #+#             */
/*   Updated: 2022/07/20 11:33:36 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process_exit(int code)
{
	if (ft_atoi(env_get_arg("?EXIT")) == 1)
	{
		env_set_arg("?", ft_itoa(WEXITSTATUS(code)));
		env_set_arg("!EXIT", "0");
		exit(0);
	}
	else
	{
		env_set_arg("?", ft_itoa(WEXITSTATUS(code)));
	}
}