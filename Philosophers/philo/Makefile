# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: staek <staek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:25:42 by seongtki          #+#    #+#              #
#    Updated: 2023/01/06 12:06:02 by staek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror  # -fsanitize=address -g3
INCS = -I ./philo.h
RM = rm -f
SRCS = main.c ft_itoa.c ft_strlen.c time.c print.c util.c exit_process.c philo_process.c
OBJS = $(SRCS:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -pthread -o $@ $(INCS)
clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
re:	clean all
.PHONY: all clean fclean re
