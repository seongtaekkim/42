# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 15:31:20 by seongtki          #+#    #+#              #
#    Updated: 2022/08/08 17:47:55 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I./libft -I./
LIBFT = -L./libft -lft
RM = rm -f
SRCS =	pipex.c pipex_proc.c pipex_free.c pipex_setting.c
SRCS_B = pipex_bonus.c	\
		 pipex_bonus_setting.c	\
		 pipex_bonus_free.c	\
		 pipex_bonus_c_proc.c	\
		 pipex_bonus_p_proc.c	\
		 ./get_next_line/get_next_line.c	\
		 ./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o) 
OBJS_B = $(SRCS_B:.c=.o) 
ifdef V_BO
	OBJ_FILES = $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif
.c.o :
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

$(NAME) : $(OBJ_FILES)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_FILES) -o $@


all :
	$(RM) $(OBJS_B)
	make $(NAME)
bonus :
	#$(RM) $(OBJS)
	make V_BO=1 $(NAME)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)
re:	clean all

.PHONY: all bonus clean fclean re

