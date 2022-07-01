# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaur <albaur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:47:12 by faventur          #+#    #+#              #
#    Updated: 2022/07/01 15:01:04 by albaur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		( ͡° ͜ʖ ͡°)			COMPILATION			( ͡° ͜ʖ ͡°)

NAME = minishell
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
LINKS = -lreadline -L${HOME}/goinfre/.brew/opt/readline/lib
LIBLINKS = -I./includes -I./libft/includes -I ${HOME}/goinfre/.brew/opt/readline/include
SRC_PATH = srcs/
OBJ_PATH = bin/
C_EXTENSION = .c

#		눈_눈			SOURCES			눈_눈

MAIN_PATH	=	
MAIN_FILES 	= 	minishell
SRCS_FILES	+=	$(addprefix $(MAIN_PATH), $(MAIN_FILES))

INIT_PATH	=	init/
INIT_FILES 	= 	init
SRCS_FILES	+=	$(addprefix $(INIT_PATH), $(INIT_FILES))

ENV_PATH	=	env/
ENV_FILES 	= 	env_add env_delete env_get_pwd env_get env_read env_set \
				env_search env_write
SRCS_FILES	+=	$(addprefix $(ENV_PATH), $(ENV_FILES))

SIG_PATH	=	signal/
SIG_FILES 	= 	signal
SRCS_FILES	+=	$(addprefix $(SIG_PATH), $(SIG_FILES))

PARS_PATH	=	parsing/
PARS_FILES 	= 	single_quotes double_quotes path_searcher pipe_manager \
				ms_split ms_quote_manager process_input ft_tokenizer \
				ft_isoper check check_utils
SRCS_FILES	+=	$(addprefix $(PARS_PATH), $(PARS_FILES))

UTIL_PATH	=	utils/
UTIL_FILES 	= 	utils
SRCS_FILES	+=	$(addprefix $(UTIL_PATH), $(UTIL_FILES))

BUI_PATH	=	builtins/
BUI_FILES 	= 	pwd cd export unset env
SRCS_FILES	+=	$(addprefix $(BUI_PATH), $(BUI_FILES))

SRCS_FILES_EXT 		+= 	$(addsuffix $(C_EXTENSION), $(SRCS_FILES))
SRCS 				+= 	$(addprefix $(SRC_PATH), $(SRCS_FILES_EXT))
OBJS 				= 	$(addprefix $(OBJ_PATH), $(SRCS_FILES_EXT:c=o))

#		(҂◡_◡)			UTILS			(҂◡_◡)

RM = rm -rf

#		(｡◕‿◕｡)			COLORS			(｡◕‿◕｡)

NONE = \033[0m
HIRED = \033[31m
HIGREEN = \033[92m
HIBLUE = \033[94m
CURSIVE = \033[3m

#		( ಠ ʖ̯ ಠ)		RULES			( ಠ ʖ̯ ಠ)

all: $(NAME)

$(NAME):  $(OBJS)
	@echo "$(HIRED)Compiling...$(NONE)"
	@$(MAKE) stacks _ft -sC ./libft
	@mv ./libft/libft.a .
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a $(LINKS)
	@echo "$(CURSIVE)$(HIBLUE)Parce que taper une commande,$(NONE)"
	@echo "$(CURSIVE)$(HIGREEN)c'est du pipi de chat.$(NONE)"

.c.o:
	@$(CC) $(FLAGS) -c ${LIBLINKS} $< -o ${<:.c=.o} 


$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} $(LIBLINKS) -c $< -o $@

clean:
	@$(RM) -r libft.a $(OBJ_PATH)
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME) minishell.dSYM
	@$(MAKE) fclean -C ./libft

re: fclean all

.phony: all clean fclean re
