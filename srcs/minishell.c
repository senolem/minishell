/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:45:37 by albaur            #+#    #+#             */
/*   Updated: 2022/07/18 11:22:24 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*prompt;

	data = malloc(sizeof(t_data));
	if (argc > 1 && argv)
		throw_error(data, "Error", E2BIG);
	init_shell(data);
	while (!data->exit)
	{
		prompt = ft_concat(env_get_pwd(), " $ ");
		data->input = readline(prompt);
		if (data->input == NULL)
			break ;
		process_input(data);
		free(prompt);
	}
	if (ft_atoi(env_get_arg("SHLVL")) == 1)
		unlink(ENV_FILE);
	env_set_arg("SHLVL", ft_itoa(ft_atoi(env_get_arg("SHLVL")) - 1));
	free(prompt);
	free(data->input);
	free(data);
	return (0);
}
