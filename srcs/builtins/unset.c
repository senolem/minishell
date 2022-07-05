/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:22:54 by albaur            #+#    #+#             */
/*   Updated: 2022/07/05 11:10:08 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unset_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
		{
			ft_printf("minishell: unset: `%s': not a valid identifier\n", str);
			return (-1);
		}
		++i;
	}
	return (1);
}

static int	unset_min(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isascii(str[i][j]) > 0)
				return (1);
			++j;
		}
		++i;
	}
	return (-1);
}

int	builtin_unset(char **str)
{
	ssize_t	i;
	char	**env;

	if (!str || unset_min(str) == -1)
		return (1);
	i = -1;
	env = env_read(ENV_FILE);
	while (str[++i])
	{
		if (unset_check(str[i]) && env_search(str[i], env) >= 0)
			env = env_delete(str[i], &env);
	}
	env_write(ENV_FILE, env);
	ft_arr_freer(env);
	return (0);
}
