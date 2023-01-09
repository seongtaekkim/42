# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:25:42 by seongtki          #+#    #+#              #
#    Updated: 2023/01/09 13:51:02 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC		= cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./philo.h
RM = rm -f
SRCS = main.c ft_itoa.c ft_strlen.c time.c print.c util.c exit_process.c philo_process.c thread_func.c
OBJS = $(SRCS:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $@ $(INCS)
clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
re:	fclean all
.PHONY: all clean fclean re
