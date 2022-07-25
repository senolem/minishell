/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_hd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:22:20 by albaur            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/25 16:43:09 by albaur           ###   ########.fr       */
=======
/*   Updated: 2022/07/25 16:40:45 by albaur           ###   ########.fr       */
>>>>>>> fa35d7ceab4cf6ef6180cf18c159563731f64b22
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_hd(char *path, t_hd *hd)
{
	pid_t	pid;
	int		code;

	hd->code = 0;
	pid = fork();
	sig_toggle(2);
	if (pid < 0)
		return (ret_null("fork:", strerror(errno)));
	if (pid == 0)
	{
		sig_toggle(3);
		ft_hd_performer(path, hd);
		sig_toggle(0);
	}
	else if (pid > 0)
	{
		rl_on_new_line();
		waitpid(pid, &code, 0);
	}
	sig_toggle(0);
}
