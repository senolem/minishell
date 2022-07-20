/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:27:38 by albaur            #+#    #+#             */
/*   Updated: 2022/07/20 11:33:39 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_reset(struct termios *terminal)
{
	terminal->c_lflag &= ~terminal->c_lflag;
	terminal->c_lflag |= (ISIG | ICANON | IEXTEN | ECHO | NOFLSH);
	terminal->c_iflag &= ~terminal->c_iflag;
	terminal->c_iflag |= (ICRNL | IXON | IXANY | IMAXBEL | IUTF8);
	terminal->c_oflag &= ~terminal->c_oflag;
	terminal->c_oflag |= (OPOST | ONLCR);
	terminal->c_cflag &= ~terminal->c_cflag;
	terminal->c_cflag |= (CREAD | CS8);
}

static void	init_ignore(void)
{
	sig_ignore(SIGQUIT);
	sig_ignore(SIGTSTP);
	sig_ignore(SIGTTIN);
	sig_ignore(SIGTTOU);
	sig_ignore(SIGTERM);
	sig_ignore(SIGHUP);
	sig_toggle(0);
}

int	init_mode(int n)
{
	struct termios	term;

	if (isatty(STDIN_FILENO))
	{
		if (errno == EBADF)
			printf("/!\\ Failed to setup interactive mode\n");
		else
		{
			if (!tcgetattr(STDIN_FILENO, &term))
			{
				init_reset(&term);
				if (n == 1)
					term.c_lflag |= (ECHOCTL);
				if (tcsetattr(STDIN_FILENO, TCSANOW, &term))
					perror("tcsetattr");
			}
			else
				perror("tcgetattr");
		}
		return (1);
	}
	return (0);
}

static int	init_env(void)
{
	char		**env;
	char		*pwd;
	extern char	**environ;

	env = ft_arrdup(environ);
	if (!env)
		return (0);
	pwd = env_get("PWD", env);
	pwd = ft_concat(pwd, "/minishell");
	env_set("SHELL", "minishell", &env);
	env_set("?", "0", &env);
	env_set("?EXIT", "0", &env);
	env_write(ENV_FILE, env);
	ft_arr_freer(env);
	free(pwd);
	return (1);
}

int	init_shell(t_data *data)
{
	init_ignore();
	init_mode(0);
	init_env();
	data->exit = 0;
	return (0);
}
