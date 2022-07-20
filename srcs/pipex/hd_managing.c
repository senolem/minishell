/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_managing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:59 by faventur          #+#    #+#             */
/*   Updated: 2022/07/20 15:53:52 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_hd_performer(char *av[], t_hd *hd)
{
	hd->buffer = readline("heredoc> ");
	hd->cmp = ft_strncmp(hd->buffer, av[2], ft_strlen(hd->buffer) - 1);
	hd->temp = ft_strjoin(hd->temp, hd->buffer);
	free(hd->buffer);
	while (hd->cmp && hd->buffer)
	{
		hd->buffer = readline("heredoc> ");
		hd->cmp = ft_strncmp(hd->buffer, av[2], ft_strlen(hd->buffer) - 1);
		hd->temp = ft_strjoin(hd->temp, hd->buffer);
		free(hd->buffer);
	}
}

static int	ope_and_write(char **arr, char *av[])
{
	int	fd;
	int	i;

	i = 0;
	fd = open("temporary.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_printerror("pipex", "temporary.txt");
	while (arr[i] && ft_strncmp(arr[i], av[2], ft_strlen(av[2])))
	{
		write(fd, arr[i], ft_strlen(arr[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	ft_arr_freer(arr);
	return (fd);
}

t_var	hd_managing(int ac, char *av[])
{
	t_var	var;
	t_hd	hd;

	hd.temp = malloc(sizeof(char) * 1);
	hd.temp[0] = '\0';
	ft_hd_performer(av, &hd);
	hd.arr = ft_split(hd.temp, '\n');
	var.fd[0] = ope_and_write(hd.arr, av);
	var.fd[0] = open("temporary.txt", O_RDONLY);
	if (var.fd[0] < 0)
		ft_printerror("pipex", "temporary.txt");
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var.fd[1] < 0)
		ft_printerror("pipex", av[ac - 1]);
	return (var);
}
