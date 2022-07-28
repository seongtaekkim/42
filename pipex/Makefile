# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 15:31:20 by ulee              #+#    #+#              #
#    Updated: 2021/08/26 15:31:21 by ulee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
INCS = -I./libft -I./
LIBFT = -L./libft -lft
RM = rm -f
FILE =	pipex 
BONUS = pipex_bonus
SRCS = $(addprefix ./, $(addsuffix .c, $(FILE)))
OBJS = $(addprefix ./, $(addsuffix .o, $(FILE)))
SRCS_B = $(addprefix ./, $(addsuffix .c, $(BONUS)))
OBJS_B = $(addprefix ./, $(addsuffix .o, $(BONUS)))
ifdef BO
	OBJ_FILES = $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif
%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
all :
	$(RM) pipex_bonus.o
	$(RM) pipex_bonus_utils.o
	make $(NAME)
$(NAME) : $(OBJ_FILES)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_FILES) -o $@
clean:
	make -C ./libft clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)
re:	clean all
bonus :
	$(RM) pipex.o
	$(RM) pipex_utils.o
	make BO=1 $(NAME)

.PHONY: all clean fclean re bonus

