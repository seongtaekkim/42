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

NAME 		= animal
CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98
RM 			= rm -f
INCS 		= -I
SRCS 		= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
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
