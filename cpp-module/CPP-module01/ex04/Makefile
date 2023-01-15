# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: staek <staek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 14:03:19 by seongtki          #+#    #+#              #
#    Updated: 2023/01/11 14:06:05 by staek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= replace
CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98
RM 			= rm -f
INCS 		= -I
SRCS 		= main.cpp
OBJS 		= $(SRCS:.cpp=.o) 
.c.o :
	$(CXX) $(CXXFLAGS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:
	make fclean
	make all
.PHONY: all bonus clean fclean re
