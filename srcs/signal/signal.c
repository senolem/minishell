/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:55 by albaur            #+#    #+#             */
/*   Updated: 2022/07/22 11:37:41 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_doc_sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
	{
		
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
	{
		ft_putendl("");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		ft_putendl_fd("minishell: quit", 2);
}

void	sig_int_nl(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	ft_putendl("");
}

int	sig_toggle(int n)
{
	if (n == 0)
	{
		sig_wait(SIGINT, sig_handler);
		sig_ignore(SIGQUIT);
	}
	else if (n == 1)
	{
		sig_wait(SIGINT, sig_int_nl);
		sig_wait(SIGQUIT, sig_handler);
	}
	if (n == 2)
	{
		sig_ignore(SIGINT);
		sig_ignore(SIGQUIT);
		init_mode(1);
		return (0);
	}
	if (n == 3)
	{
		sig_wait(SIGINT, here_doc_sig_handler);
		sig_ignore(SIGQUIT);
		return (0);
	}
	init_mode(n);
	return (1);
}

void	sig_wait(int sig, void (*hdlr)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = hdlr;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, sig);
	if (sigaction(sig, &sa, NULL))
		perror("sigaction");
}

void	sig_ignore(int sig)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, sig);
	if (sigaction(sig, &sa, NULL))
		perror("sigaction");
}
