/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:45:37 by albaur            #+#    #+#             */
/*   Updated: 2022/06/22 15:36:57 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv)
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
		data->input = readline(ft_strjoin(env_get_pwd(), " $ "));
		if (data->input == NULL)
			break ;
//		ft_tokenizer(data->input);
		arr = ms_split(data->input);
		int i = 0;
		while (arr[i])
		{
			printf("%s\n", arr[i]);
			i++;
		}
		i = 0;
		process_input(data);
		free(data->input);
	}
	unlink(ENV_FILE);
	return (0);
}
