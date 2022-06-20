/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:54:45 by faventur          #+#    #+#             */
/*   Updated: 2022/06/20 15:56:19 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_var(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
	}
	return (0);
}

char	**export(t_data data)
{
	t_stack	*new;
	char	**arr;
	int		i;

	i = 0;
	new = ft_stacknew();
	while (data.env[i])
	{
		ft_stackadd_bottom(new, ft_newnode(ft_strdup(data.env[i])));
		i++;
	}
	if (data.av[1])	 //l'argument d'export
		add_to_env(new, data.av[1]);
//	ft_stack_remove_if(new, "_=", (void *)ft_strstrbool);
//	ce serait mieux de creer une fonction display_if
	arr = ft_create_chartab(new);
	ft_stacksort(new, (void *)ft_strcmp);
	ft_stackiter_if(new, (void *)ft_putendl, "_=", (void *)ft_strstrbool);
	ft_stackclear(new, ft_delete);
	return (arr);
}
