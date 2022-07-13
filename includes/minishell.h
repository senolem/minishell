/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:44:32 by albaur            #+#    #+#             */
/*   Updated: 2022/07/13 12:47:08 by albaur           ###   ########.fr       */
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
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_fprintf.h"
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
	int		i;
	ssize_t	j;
	char	*tmp;
	char	**env;
	char	**input;
}				t_export;

typedef struct s_dollar
{
	char	*line;
	char	*str;
	char	*varname;
	char	*var;
	ssize_t	line_len;
	ssize_t	len;
	ssize_t	varname_len;
	ssize_t	var_len;
	ssize_t	i;
	ssize_t	j;
	int		sq;
	int		dq;
}				t_dollar;

typedef struct s_var
{
	pid_t	pid;
	int		fd[2];
	int		end[2];
	int		status;
	int		ac;
	char	**av;
	int		mode;
	int		type;
	int		fr;
}			t_var;

// init
int			init_shell(t_data *data);

// sanity check
int			ft_check_quotes(char *str);

// tokenizing
t_token		*ft_token_creator(char *line, size_t line_index);
void		ft_tokenizer(char **arr);
void		ft_tokdisplay(t_token *token);
void		ft_tokdel(t_token *tok);
size_t		ft_tokstrlen(t_token *token);
int			ft_tokcmp(t_token *token, int type);

void		ms_dollar_manager(t_stack *stack);
void		ms_dollar_parser(t_token *token, ssize_t *index);
void		ms_dollar_quote_eraser(t_stack *stack);
void		ms_dollar_counter(t_dollar *dollar, ssize_t *index);
char		*ms_dollar_replacer(t_dollar *dollar);
ssize_t		ms_dollar_checker(t_token *token);
int			ms_usd_quote_checker(t_token *token, ssize_t *index);
int			ms_dollar_check_charset(char c);

// parsing
void		process_input(t_data *data);
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
char		*ft_getenv(char *varname);
char		*env_get(char *name, char **env);
void		env_write(char *path, char **env);
void		env_set(char *str, char *value, char ***env);
char		**env_add(char *str, char ***env);
char		**env_delete(char *str, char ***env);
char		*env_get(char *str, char **env);
ssize_t		env_search(char *str, char **env);
char		**env_read(char *path);

// builtins
int			builtin_pwd(char **str);
int			builtin_cd(char **path);
int			builtin_export(char **str);
int			builtin_unset(char **str);
int			builtin_env(char **str);
int			builtin_exit(int n, t_data *data);

// signals
void		sig_ignore(t_data *data, int sig);
void		sig_wait(t_data *data, int sig,
				void (*hdlr)(int, siginfo_t *, void *));
void		sig_handler(int sig, siginfo_t *info, void *context);

// pipex
t_var		get_args(char ac, char *av[]);
t_var		hd_managing(int ac, char *av[]);
void		pipex(char **cmd_args);
int			ft_exec(char **cmd_args);
char		*ft_path_searcher(char *cmd);
size_t		pipe_counter(t_stack *stack);
int			pipe_manager(t_stack *stack);
t_stack		**ft_stack_splitter(t_stack *stack);
char		**ft_lst_to_arr(t_stack *stack);
char		*ft_lst_to_arrdup(t_token *token);
void		ft_redir_parser(t_stack **av, t_var *var);
void		ft_redir_del(t_stack **av);

// utils
void		throw_error(t_data *data, char *msg, int err);
int			throwback_error(char *str, char *str2, int i);
void		thrownull_error(char *str, char *str2);
char		**ft_arrdup(char **arr);
size_t		ft_arrlen(char **array);
char		*ft_concat(char *s1, char *s2);

#endif