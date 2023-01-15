# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: staek <staek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 14:03:19 by seongtki          #+#    #+#              #
#    Updated: 2023/01/11 14:04:04 by staek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= zombie
CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98
INCS 		= -I Zombie.hpp
RM 			= rm -f
SRCS 		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS		= $(SRCS:.cpp=.o) 
.c.o :
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(INCS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:
	make fclean
	make all
.PHONY: all bonus clean fclean re
