/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:20:12 by albaur            #+#    #+#             */
/*   Updated: 2022/07/13 15:27:11 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_input(t_data *data)
{
	char	**arr;

	if (data->input && data->input[0] != '\0' && data->mode)
		add_history(data->input);
	if (ft_check_quotes(data->input) > 0)
	{
		ft_printf("\033[31mSyntax error : invalid quote sequence\033[0m\n");
		return ;
	}
	if (data->input && data->input[0] != '\0')
	{
		arr = ms_split(data->input);
		if (arr)
			ft_tokenizer(arr);
		free(data->input);
	}
}
