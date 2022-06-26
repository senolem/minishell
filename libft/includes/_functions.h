/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _functions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:02:09 by faventur          #+#    #+#             */
/*   Updated: 2022/06/26 16:40:58 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FUNCTIONS_H
# define _FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_fprintf.h"

int		ft_strstrbool(const char *haystack, const char *needle);
int		ft_strnstrbool(const char *haystack, const char *needle,
			size_t len);
void	ft_printerror(char *program, char *pathname);
char	**ft_map_reader(char *filename);

#endif