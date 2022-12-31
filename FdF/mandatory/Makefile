# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 12:07:40 by seongtki          #+#    #+#              #
#    Updated: 2022/12/31 18:35:34 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./libft/libft.h -I ./fdf.h
LIBFT = -L./libft -lft
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRCS =	fdf.c readfile.c bresenham.c mlx.c draw.c util.c clear.c calc_proj.c calc_rotate.c event_motion.c ft_atoi_base.c
OBJS = $(SRCS:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(INCS) $(LIBFT) $(MLX_FLAGS) $(OBJS) -o $@
clean:
	make -C ./libft clean
	$(RM) $(OBJS)
fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)
re:	
	make fclean
	make all
.PHONY: all clean fclean re
