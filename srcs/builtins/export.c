/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:20:06 by albaur            #+#    #+#             */
/*   Updated: 2022/07/01 14:06:48 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void export_print(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == '!')
			ft_printf("%s\n", env[i] + 1);
		else
			ft_printf("%s\n", env[i]);
		++i;
	}
}

int export_min(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) > 0)
			return (1);
		++i;
	}
	return (-1);
}

int export_check(char **str)
{
	size_t i;

	i = 0;
	if (ft_arrlen(str) == 1)
		return (-2);
	if (!str[0])
	{
		ft_printf("minishell: bad assignment\n");
		return (-1);
	}
	if (ft_isdigit(str[0][0]) == 0)
	{
		ft_printf("export : not a valid identifier : %s\n", str[0]);
		return (-1);
	}
	while (str[0][i])
	{
		if (ft_isalnum(str[0][i]) == 0 && str[0][i] != '_')
		{
			ft_printf("export: not valid in this context: %s\n", str);
			return (-1);
		}
		++i;
	}
	return (1);
}

void export_exec(t_export *e)
{
	int		i;
	char	*tmp;

	i = 0;
	while (e->arr[++e->i])
	{
		e->input = ft_split(e->arr[e->i], '=');
		if (!e->input)
		{
			ft_printf("minishell: bad assignment\n");
			return ;
		}
		i = export_check(e->input);
		if (i == 1)
		{
			tmp = ft_strjoin("!", e->input[0]);
			if (env_search(tmp, e->env) >= 0)
				env_set(tmp, e->input[1], &e->env);
			else
				env_set(e->input[0], e->input[1], &e->env);
		}
		else if (i == -2)
		{
			tmp = ft_strjoin("!", e->input[0]);
			env_set(tmp, "''", &e->env);
			free(tmp);
		}
		ft_arr_freer(e->input);
	}
}

void export(char *str)
{
	t_export	e;

	e.i = -1;
	e.env = env_read(ENV_FILE);
	if (!str || export_min(str) == -1)
	{
		export_print(e.env); // il faudra trier dans l'ordre alphabetique
		ft_arr_freer(e.env);
		return ;
	}
	e.arr = ft_split(str, ' ');
	if (!e.arr)
	{
		ft_arr_freer(e.env);
		return ;
	}
	export_exec(&e);
	env_write(ENV_FILE, e.env);
	ft_arr_freer(e.arr);
	ft_arr_freer(e.env);
}