/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:44:32 by albaur            #+#    #+#             */
/*   Updated: 2022/06/20 16:32:33 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>

# define ENV_FILE "/tmp/minishell_env"

// main struct

typedef struct s_data
{
	char		*input;
	int			exit;
	int			mode;
}		t_data;

// init
int			init_shell(t_data *data);
int			init_env(void);

// parsing
void		process_input(t_data *data);
int			ms_check_charset(char c);
int			quote_checker(char *line);
char		**ms_split(char *s);
int			between_squotes(char *str, int *index);
int			squote_len_index(char *str, int *index);
char		*ft_squote_pruner_index(char *quote, char *str, int *index, int	*j);
int			between_dquotes(char *str, int *index);
int			dquote_len_index(char *str, int *index);
char		*ft_dquote_pruner_index(char *quote, char *str, int *index, int	*j);

// env
char		*env_get(char *name, char **env);
void		env_write(char *path, char **env);
void		env_set(char *str, char *value, char ***env);
char		**env_add(char *str, char ***env);
char		*env_get(char *str, char **env);
int			env_search(char *str, char **env);
char		**env_read(char *path);

// builtins
char	**cd(t_data data);
char	**export(t_data data);
void	pwd();

// signals
void		sig_ignore(t_data *data, int sig);

// utils
void		throw_error(t_data *data, char *msg, int err);
char		**ft_arrdup(char **arr);

#endif