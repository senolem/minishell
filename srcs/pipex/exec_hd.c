/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_hd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:22:20 by albaur            #+#    #+#             */
/*   Updated: 2022/07/25 15:26:39 by albaur           ###   ########.fr       */
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
	if (WIFEXITED(code))
		hd->code = WEXITSTATUS(code);
	if (hd->code == 1)
		env_set_arg("?", "1");
	sig_toggle(0);
}
