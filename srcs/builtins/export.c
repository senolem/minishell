/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:20:06 by albaur            #+#    #+#             */
/*   Updated: 2022/06/27 16:34:54 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(char *str)
{
	size_t	i;
	char	**input;
	char	**env;

	i = 0;
	env = env_read(ENV_FILE);
	input = ft_split(str, '=');
	if (!input)
		return ;
	while (input[0][i])
	{
		if (ft_isalnum(input[0][i]) == 0)
		{
			printf("export: not valid in this context: %s\n", input[0]);
			return ;
		}
		++i;
	}
	env_set(input[0], input[1], &env);
	env_write(ENV_FILE, env);
	free(input);
	free(env);
}