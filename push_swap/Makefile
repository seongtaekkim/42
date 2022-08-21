# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 18:05:39 by seongtki          #+#    #+#              #
#    Updated: 2022/08/21 15:26:25 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./libft/libft.h -I ./push_swap.h
INCS_B = -I ./libft/libft.h -I ./push_swap_bonus.h
LIBFT = -L./libft -lft
RM = rm -f
SRCS =	push_swap.c stack.c operations.c close.c sort.c search.c init.c output.c process1.c
SRCS_B = push_swap.c
OBJS = $(SRCS:.c=.o) 
OBJS_B = $(SRCS_B:.c=.o) 
ifdef V_BO
	OBJ_FILES = $(OBJS_B)
	V_INCS = $(INCS_B)
else
	OBJ_FILES = $(OBJS)
	V_INCS = $(INCS)
endif
.c.o :
	$(CC) $(CFLAGS) $(V_INCS) -c $< -o $@

$(NAME) : $(OBJ_FILES)
	make -C ./libft
	$(CC) $(CFLAGS) $(V_INCS) $(LIBFT) $(MLX_FLAGS) $(OBJ_FILES) -o $@
all :
	$(RM) $(OBJS_B)
	make $(NAME)
bonus :
	$(RM) $(OBJS)
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
