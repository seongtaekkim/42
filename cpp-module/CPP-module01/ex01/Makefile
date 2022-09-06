# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 14:03:19 by seongtki          #+#    #+#              #
#    Updated: 2022/09/06 14:03:24 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = clang++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
INCS = -I Zombie.h
RM = rm -f
SRCS = main.cpp Zombie.cpp zombieHorde.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:	clean all
.PHONY: all bonus clean fclean re
