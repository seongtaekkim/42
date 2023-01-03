# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:25:42 by seongtki          #+#    #+#              #
#    Updated: 2023/01/01 19:50:47 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# cc -L/opt/homebrew/opt/readline/lib -lreadline -lhistory readline.c     
NAME	= minishell
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
SRCS 	= shell.c lexer.c linkedlist.c astree.c parser.c free.c lex_func1.c	lex_func2.c \
		  parse_cmd.c parse_job.c parse_single_cmd.c lexer_env.c lexer_asterisk.c lexer_asterisk2.c lexer_asterisk3.c lexer_heredoc.c lexer_heredoc2.c lexer_heredoc3.c lexer_valid.c \
		  execute.c execute2.c execute_util.c execute_util2.c execute_redir.c execute_pipe.c execute_waitpid.c \
		  common.c exit_process.c builtin.c \
		  builtIn/ft_echo.c builtIn/ft_env.c builtIn/ft_exit.c builtIn/ft_export.c builtIn/ft_unset.c builtIn/ft_cd_pwd.c builtIn/built_in_util.c builtIn/ft_export_util.c
OBJS 	= $(SRCS:.c=.o)
# RDLIB	= /Users/susong/.brew/opt/readline/
RDLIB = /opt/homebrew/opt/readline/
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
