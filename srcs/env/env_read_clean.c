/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_read_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:23:13 by albaur            #+#    #+#             */
/*   Updated: 2022/06/28 23:23:36 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_read_clean(t_read *r)
{
	close(r->fd);
	free(r->tmp);
	if (!r->env)
		return (NULL);
	else
		return (r->env);
}
