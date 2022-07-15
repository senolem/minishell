/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:39:11 by albaur            #+#    #+#             */
/*   Updated: 2022/07/15 12:44:46 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_exec_args(char **cmd_args)
{
	char	**args;

	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("/bin/bash");
	args[1] = ft_strdup(cmd_args[0]);
	args[2] = 0;
	return (args);
}