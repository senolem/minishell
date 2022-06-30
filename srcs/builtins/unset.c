/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:22:54 by albaur            #+#    #+#             */
/*   Updated: 2022/06/30 13:48:48 by albaur           ###   ########.fr       */
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
			printf("unset: %s: invalid parameter name\n", str);
			return (-1);
		}
		++i;
	}
	return (1);
}

void	unset(char *str)
{
	size_t	i;
	char	**env;
	char	**arr;

	i = 0;
	env = env_read(ENV_FILE);
	arr = ft_split(str, ' ');
	if (!arr)
	{
		//ft_arr_freer(env);
		return ;
	}
	while (arr[i])
	{
		if (unset_check(arr[i]) && env_search(arr[i], env) >= 0)
		{
			env = env_delete(env_search(arr[i], env), &env);
			env_write(ENV_FILE, env);
		}
		++i;
	}
	printf("\n");
	//ft_arr_freer(arr);
	//ft_arr_freer(env);
}