/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_managing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:59 by faventur          #+#    #+#             */
/*   Updated: 2022/07/05 15:59:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ope_and_write(char **arr, char *av[])
{
	int	fd;
	int	i;

	i = 0;
	fd = open("temporary.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_printerror("pipex", "temporary.txt");
	while (ft_strstrbool(arr[i], av[2]))
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
	char	**arr;
	char	*buffer;
	char	*temp;

	temp = malloc(sizeof(char) * 1);
	temp[0] = '\0';
	while (ft_strstrbool(temp, av[2]))
	{
		ft_fprintf(1, "heredoc> ");
		buffer = get_next_line(0);
		buffer[ft_strlen(buffer)] = '\0';
		temp = ft_strjoin(temp, buffer);
		free(buffer);
	}
	arr = ft_split(temp, '\n');
	var.fd[0] = ope_and_write(arr, av);
	var.fd[0] = open("temporary.txt", O_RDONLY);
	if (var.fd[0] < 0)
		ft_printerror("pipex", "temporary.txt");
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var.fd[1] < 0)
		ft_printerror("pipex", av[ac - 1]);
	return (var);
}
