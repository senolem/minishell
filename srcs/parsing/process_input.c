/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:20:12 by albaur            #+#    #+#             */
/*   Updated: 2022/07/04 14:53:40 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_input(t_data *data)
{
	char	**arr;

	if (data->input && data->input[0] != '\0' && data->mode)
		add_history(data->input);
	if (check_quotes(data) > 0)
	{
		ft_printf("\033[31mSyntax error : invalid quote sequence\033[0m\n");
		return ;
	}
	
	arr = ms_split(data->input);
	ft_tokenizer(arr);
//	int i = 0;
//	while (arr[i])
//	{
//		ft_printf("%s\n", arr[i]);
//		i++;
//	}
	free(data->input);
}
