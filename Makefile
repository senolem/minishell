# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaur <albaur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:47:12 by faventur          #+#    #+#              #
#    Updated: 2022/06/21 17:30:55 by albaur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_M = minishell.c
SRCS_P = single_quotes.c double_quotes.c path_searcher.c pipe_counter.c \
			ms_split.c ms_quote_manager.c process_input.c ft_tokenizer.c
SRCS_E = env.c env_search.c env_get_pwd.c
SRCS_S = signal.c
SRCS_I = init.c
SRCS_U = utils.c
SRCS_B = pwd.c

OBJS_M = $(addprefix srcs/, ${SRCS_M:.c=.o})
OBJS_I = $(addprefix srcs/init/, ${SRCS_I:.c=.o})
OBJS_E = $(addprefix srcs/env/, ${SRCS_E:.c=.o})
OBJS_S = $(addprefix srcs/signal/, ${SRCS_S:.c=.o})
OBJS_P = $(addprefix srcs/parsing/, ${SRCS_P:.c=.o})
OBJS_U = $(addprefix srcs/utils/, ${SRCS_U:.c=.o})
OBJS_B = $(addprefix srcs/builtins/, ${SRCS_B:.c=.o})

FLAGS = -Wall -Wextra -Werror

LINKS = -lreadline

RM =	rm -f

NAME = minishell

NONE = \033[0m
HIRED = \033[31m
HIGREEN = \033[92m
HIBLUE = \033[94m
CURSIVE = \033[3m

all: $(NAME)

$(NAME): $(OBJS_M) $(OBJS_I) $(OBJS_E) $(OBJS_S) $(OBJS_P) $(OBJS_U) $(OBJS_B)
	@echo "$(HIRED)Compiling...$(NONE)"
	@$(MAKE) stacks -sC ./libft
	@mv ./libft/libft.a .
	@gcc $(FLAGS) $(OBJS_M) $(OBJS_I) $(OBJS_E) $(OBJS_S) $(OBJS_P) $(OBJS_U) $(OBJS_B) libft.a $(LINKS) -L${HOME}/goinfre/.brew/opt/readline/lib -o $(NAME)
	@echo "$(CURSIVE)$(HIBLUE)Parce que taper une commande,$(NONE)"
	@echo "$(CURSIVE)$(HIGREEN)c'est du pipi de chat.$(NONE)"
	@rm $(OBJS_M) $(OBJS_I) $(OBJS_E) $(OBJS_S) $(OBJS_P) $(OBJS_U) $(OBJS_B)

.c.o:
	@gcc -Wall -Wextra -Werror -c -I./includes -I./libft/includes -I ${HOME}/goinfre/.brew/opt/readline/include $< -o ${<:.c=.o}

clean:
	@$(RM) libft.a $(OBJS_M) $(OBJS_I) $(OBJS_E) $(OBJS_S) $(OBJS_P) $(OBJS_U) $(OBJS_B)
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.phony: all clean fclean re
