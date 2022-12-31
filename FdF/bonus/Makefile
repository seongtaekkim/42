# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 12:07:40 by seongtki          #+#    #+#              #
#    Updated: 2022/12/31 18:47:07 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./libft/libft.h -I ./fdf.h
LIBFT = -L./libft -lft
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRCS =	fdf_bonus.c readfile_bonus.c bresenham_bonus.c mlx_bonus.c draw_bonus.c util_bonus.c clear_bonus.c calc_proj_bonus.c \
		calc_rotate_bonus.c event_motion_bonus.c ft_atoi_base_bonus.c
OBJS = $(SRCS:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
bonus : $(NAME)
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
	make bonus
.PHONY: bonus clean fclean re
