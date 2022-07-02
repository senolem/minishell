/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:44:32 by albaur            #+#    #+#             */
/*   Updated: 2022/07/02 12:03:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include "libft.h"
# include "_functions.h"
# include "tok_stacks.h"

# define ENV_FILE "/tmp/minishell_env"

// main struct
typedef struct s_data
{
	int			exit;
	int			mode;
	char		*input;
}				t_data;

// other structs

typedef struct s_check
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		squote;
	int		dquote;
	char	**split;
}				t_check;

typedef struct s_read
{
	ssize_t	i;
	int		fd;
	char	buffer[2];
	char	*tmp;
	char	**env;
}				t_read;

typedef struct s_delete
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**ptr;
	char	**new;
}				t_delete;

typedef struct s_export
{
	ssize_t	i;
	char	**env;
	char	**arr;
	char	**input;
}				t_export;

typedef struct s_dollar
{
	char	*line;
	char	*varname;
	char	*var;
	size_t	len;
	size_t	varname_len;
	size_t	var_len;
	size_t	i;
	size_t	sq;
	size_t	dq;
}				t_dollar;

// init
int			init_shell(t_data *data);

// sanity check
int			check_quotes(t_data *data);
int			check_quotes_end(int *str);
void		check_quotes_count(char *str, int *squote, int *dquote);

// tokenizing
t_token		*ft_token_creator(char *line, size_t line_index);
void		ft_tokenizer(char *arr[]);
void		ft_tokdel(t_token *tok);
void		ft_tokdisplay(t_token *token);
int			ft_tokcmp(t_token *token, int type);

void		ms_dollar_manager(t_stack *stack);
int			ms_quote_checker(t_token *token, size_t *index);
int			ms_dollar_checker(t_token *token);

// parsing
void		process_input(t_data *data);
void		dquote_dollar_parser(char *line, size_t *index);
char		*dquote_dollar_replacer(t_dollar *dollar);
char		**ms_split(char *s);
size_t		ms_let_count(char *str, size_t *index);
int			ms_check_charset(char c);
int			between_squotes(char *str, size_t *index);
int			squote_len_index(char *str, size_t *index);
char		*ft_squote_pruner_index(char *quote, char *str,
				size_t *index, size_t *j);
int			between_dquotes(char *str, size_t *index);
int			dquote_len_index(char *str, size_t *index);
char		*ft_dquote_pruner_index(char *quote, char *str,
				size_t *index, size_t *j);
char		*env_get_pwd(void);
int			ft_isoper(char c);
int			oper_len_index(char *str, size_t *index);
char		*ft_oper_writer_index(char *quote, char *str,
				size_t *index, size_t *j);

// env
char		*env_get(char *name, char **env);
void		env_write(char *path, char **env);
void		env_set(char *str, char *value, char ***env);
char		**env_add(char *str, char ***env);
char		**env_delete(char *str, char ***env);
char		*env_get(char *str, char **env);
ssize_t		env_search(char *str, char **env);
char		**env_read(char *path);

// builtins
void		builtin_pwd(void);
void		builtin_cd(char	*path);
void		builtin_export(char *str);
void		builtin_unset(char *str);
void		builtin_env(void);
void		builtin_exit(int n, t_data *data);

// signals
void		sig_ignore(t_data *data, int sig);
void		sig_wait(t_data *data, int sig,
				void (*hdlr)(int, siginfo_t *, void *));
void		sig_handler(int sig, siginfo_t *info, void *context);

// utils
void		throw_error(t_data *data, char *msg, int err);
int			throwback_error(char *str, char *str2, int i);
void		thrownull_error(char *str, char *str2);
char		**ft_arrdup(char **arr);
size_t		ft_arrlen(char **array);
char		*ft_concat(char *s1, char *s2);

#endif