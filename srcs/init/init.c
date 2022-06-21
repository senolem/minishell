/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:27:38 by albaur            #+#    #+#             */
/*   Updated: 2022/06/21 18:08:11 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_reset(struct termios *terminal)
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

static void	init_ignore(t_data *data)
{
	sig_ignore(data, SIGQUIT);
	sig_ignore(data, SIGTSTP);
	sig_ignore(data, SIGTTIN);
	sig_ignore(data, SIGTTOU);
	sig_ignore(data, SIGTERM);
	sig_ignore(data, SIGHUP);
	sig_wait(data, SIGINT, sig_handler);
}

static int init_mode(t_data *data)
{
	struct termios term;

	if (isatty(STDIN_FILENO))
	{
		if (errno == EBADF)
			printf("/!\\ Failed to setup interactive mode\n");
		else
		{
			data->mode = 1;
			if (!tcgetattr(STDIN_FILENO, &term))
			{
				init_reset(&term);
				term.c_lflag &= ECHO;
				if (tcsetattr(STDIN_FILENO, TCSANOW, &term))
					throw_error(data, "Error: tcsetattr", 0);
			}
			else
				throw_error(data, "Error: tcgetattr", 0);
		}
		return (1);
	}
	return (0);
}

int	init_env(void)
{
	char		**env;
	char		*pwd;
	extern char	**environ;

	env = ft_arrdup(environ);
	if (!env)
		return (0);
	pwd = env_get("PWD", env);
	pwd = ft_strjoin(pwd, "/minishell");
	env_set("SHELL", "minishell", &env);
	env_set("?NB", "0", &env);
	env_set("?PWD", pwd, &env);
	env_write(ENV_FILE, env);
	free(pwd);
	return (1);
}

int	init_shell(t_data *data)
{
	init_ignore(data);
	init_mode(data);
	init_env();
	return (0);
}
