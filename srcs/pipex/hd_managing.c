/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_managing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:59 by faventur          #+#    #+#             */
/*   Updated: 2022/07/20 17:30:04 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_hd_performer(char *path, t_hd *hd)
{
	hd->buffer = readline("heredoc> ");
	if (!hd->buffer)
		return ;
	hd->cmp = ft_strncmp(hd->buffer, path, ft_strlen(hd->buffer) - 1);
	hd->temp = ft_strjoin(hd->temp, hd->buffer);
	if (!hd->temp)
		return ;
	free(hd->buffer);
	while (hd->cmp && hd->buffer)
	{
		hd->buffer = readline("heredoc> ");
		if (!hd->buffer)
			return ;
		hd->cmp = ft_strncmp(hd->buffer, path, ft_strlen(hd->buffer) - 1);
		hd->temp = ft_strjoin(hd->temp, hd->buffer);
		if (!hd->temp)
			return ;
		free(hd->buffer);
	}
}

static int	ope_and_write(char **arr, char *path)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("temporary.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_printerror("pipex", "temporary.txt");
	while (arr[i] && ft_strncmp(arr[i], path, ft_strlen(path)))
	{
		write(fd, arr[i], ft_strlen(arr[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	ft_arr_freer(arr);
	return (fd);
}

static void	hd_managing(char *path, t_var *var)
{
	t_hd	hd;

	hd.temp = malloc(sizeof(char) * 1);
	hd.temp[0] = '\0';
	ft_hd_performer(path, &hd);
	hd.arr = ft_split(hd.temp, '\n');
	if (!hd.arr)
		ret_err(strerror(errno), NULL, 0);
	var->fd[0] = ope_and_write(hd.arr, path);
	var->fd[0] = open("temporary.txt", O_RDONLY);
	if (var->fd[0] < 0)
		ret_err(strerror(errno), NULL, 0);
}

int	here_doc_redir_fd(t_stack **av, t_var *var)
{
	t_node	*node;
	char	*path;

	node = (*av)->top;
	while (node)
	{
		if (!ft_tokcmp(node->content, d_smaller_than_type))
		{
			if (node->next)
				node = node->next;
			else
				return (ret_err("minishell: parse error", NULL, 1));
			path = ft_lst_to_arrdup(node->content);
			hd_managing(path, var);
			if (var->fd[0] < 0)
				ret_err(strerror(errno), NULL, 0);
			redir_clear(node->prev, av);
			redir_clear(node, av);
			free(path);
			return (0);
		}
		if (node->next)
			node = node->next;
	}
	return (1);
}
