# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:25:42 by seongtki          #+#    #+#              #
#    Updated: 2023/01/03 13:59:47 by nouswong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
SRCS 	= shell_bonus.c lexer_bonus.c linkedlist_bonus.c astree_bonus.c parser_bonus.c free_bonus.c lex_func1_bonus.c	lex_func2_bonus.c \
		  parse_cmd_bonus.c parse_job_bonus.c parse_single_cmd_bonus.c lexer_env_bonus.c lexer_asterisk_bonus.c lexer_asterisk2_bonus.c lexer_asterisk3_bonus.c lexer_heredoc_bonus.c lexer_heredoc2_bonus.c lexer_heredoc3_bonus.c lexer_valid_bonus.c \
		  execute_bonus.c execute2_bonus.c execute_util_bonus.c execute_util2_bonus.c execute_redir_bonus.c execute_pipe_bonus.c execute_waitpid_bonus.c \
		  common_bonus.c exit_process_bonus.c builtin_bonus.c \
		  builtIn/ft_echo_bonus.c builtIn/ft_env_bonus.c builtIn/ft_exit_bonus.c builtIn/ft_export_bonus.c builtIn/ft_unset_bonus.c builtIn/ft_cd_pwd_bonus.c builtIn/built_in_util_bonus.c builtIn/ft_export_util_bonus.c
OBJS 	= $(SRCS:.c=.o)
RDLIB	= /Users/susong/.brew/opt/readline/
LIBFT	= -L./libft -lft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -L$(RDLIB)lib -I$(RDLIB)include -lreadline -lhistory -o $(NAME)

.c.o :
	$(CC) $(CFLAGS)  -I$(RDLIB)include -c $< -o $@
clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re:	fclean all
.PHONY: all clean fclean re
