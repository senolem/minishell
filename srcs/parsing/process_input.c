/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:20:12 by albaur            #+#    #+#             */
/*   Updated: 2022/07/05 12:09:22 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_input(t_data *data)
{
	char	**arr;
	char *test[3] = {"              ", "parsing", 0};
	char *test2[2] = {"              ", 0};

	if (data->input && data->input[0] != '\0' && data->mode)
		add_history(data->input);
	if (ft_check_quotes(data->input) > 0)
	{
		ft_printf("\033[31mSyntax error : invalid quote sequence\033[0m\n");
		return ;
	}
	
	arr = ms_split(data->input);
	builtin_export(test);
	builtin_export(test2);
	builtin_export(NULL);
	ft_tokenizer(arr);
	//	int i = 0;
	//	while (arr[i])
	//	{
	//		ft_printf("%s\n", arr[i]);
	//		i++;
	//	}
	free(data->input);
}
