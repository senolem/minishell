/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:39:11 by albaur            #+#    #+#             */
/*   Updated: 2022/07/15 17:44:10 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_exec_args(char **cmd_args)
{
	char		**args;

	args = malloc(sizeof(char *) * 4);
	if (!args)
		return (NULL);
	args[0] = ft_strdup("/bin/bash");
	args[1] = ft_strdup("-c");
	args[2] = cmd_args[0];
	args[3] = 0;
	return (args);
}