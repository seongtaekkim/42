# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 19:13:16 by susong            #+#    #+#              #
#    Updated: 2023/02/03 20:53:41 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
SRCS	= miniRT.c src/mlx_hook.c src/calc.c src/calc2.c src/calc3.c src/calc4.c src/parse.c src/parse_element.c src/parse_valid.c \
			src/parse_element2.c src/ray.c src/ray_check.c src/light.c src/shadow.c src/cylinder.c src/cylinder2.c \
			library/gnl.c library/gnl2.c library/ft_split.c library/library.c library/ft_atoi.c library/ft_atof.c library/ft_strlen2.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
HEADER  = mini_rt.h
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${OBJS}
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER} -I mlx

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re .c.o
