/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ms_launch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:28:03 by albaur            #+#    #+#             */
/*   Updated: 2022/07/23 12:44:55 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_ms_launch(t_stack *stack)
{
	size_t	i;
	char	**str;

	i = 0;
	if (!stack)
		return;
	str = ft_lst_to_arr(stack);
	if (!str)
		return;
	while (str[i])
	{
		if (!ft_strnstrbool(str[i], "/minishell", ft_strlen(str[i])))
		{
			sig_toggle(2);
			ft_arr_freer(str);
			return ;
		}
		++i;
	}
	sig_toggle(1);
	ft_arr_freer(str);
}
