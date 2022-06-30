/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:22:54 by albaur            #+#    #+#             */
/*   Updated: 2022/06/30 14:35:13 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
		{
			ft_printf("unset: %s: invalid parameter name\n", str);
			return (-1);
		}
		++i;
	}
	return (1);
}

int	unset_min(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) > 0)
			return (1);
		++i;
	}
	return (-1);
}

void	unset(char *str)
{
	size_t	i;
	char	**env;
	char	**arr;

	if (!str)
		return ;
	if (unset_min(str) == -1)
	{
		ft_printf("unset: not enough arguments\n");
		return ;
	}
	i = 0;
	env = env_read(ENV_FILE);
	arr = ft_split(str, ' ');
	if (!arr)
	{
		ft_arr_freer(env);
		return ;
	}
	while (arr[i])
	{
		if (unset_check(arr[i]) && env_search(arr[i], env) >= 0)
			env = env_delete(arr[i], &env);
		++i;
	}
	env_write(ENV_FILE, env);
	ft_arr_freer(arr);
	ft_arr_freer(env);
}