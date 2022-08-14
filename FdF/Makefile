# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 12:07:40 by seongtki          #+#    #+#              #
#    Updated: 2022/08/14 15:09:22 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./libft/libft.h -I ./get_next_line.h -I ./fdf.h
INCS_B = -I ./libft/libft.h -I ./get_next_line.h -I ./fdf_bonus.h
LIBFT = -L./libft -lft
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRCS =	fdf.c get_next_line.c get_next_line_utils.c readfile.c bresenham.c mlx.c draw.c 
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
