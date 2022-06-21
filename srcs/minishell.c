/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:45:37 by albaur            #+#    #+#             */
/*   Updated: 2022/06/21 10:59:09 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**arr;
	t_data	*data;

	i = 0;
	data = malloc(sizeof(t_data));
	if (argc > 1 && argv)
		throw_error(data, "Error", E2BIG);
	init_shell(data);
	while (!data->exit)
	{
		data->input = readline(ft_strjoin(env_get_pwd(ENV_FILE), " $ "));
		if (quote_checker(data->input))
		{
			arr = ms_split(data->input);
			while (arr[i])
			{
				ft_printf("%s\n", arr[i]);
				i++;
			}
			ft_arr_freer(arr);
		}
		process_input(data);
		free(data->input);
	}
}
