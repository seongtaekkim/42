# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 12:07:40 by seongtki          #+#    #+#              #
#    Updated: 2022/08/31 16:52:21 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./libft/libft.h -I ./fdf.h
LIBFT = -L./libft -lft
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRCS =	fdf.c readfile.c bresenham.c mlx.c draw.c util.c clear.c calc_proj.c calc_rotate.c
SRCS_B = fdf.c
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

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C ./libft
	$(CC) $(CFLAGS) $(V_INCS) $(LIBFT) $(MLX_FLAGS) $(OBJ_FILES) -o $@
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
