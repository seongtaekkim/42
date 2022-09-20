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

NAME = find
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -f
INCS = -I
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o) 
.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:	clean all
.PHONY: all bonus clean fclean re
