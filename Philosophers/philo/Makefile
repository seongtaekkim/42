# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:25:42 by seongtki          #+#    #+#              #
#    Updated: 2022/09/05 17:30:25 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./philo.h
RM = rm -f
SRCS = main.c ft_itoa.c ft_strlen.c
OBJS = $(SRCS:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCS)
clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
re:	clean all
.PHONY: all clean fclean re
