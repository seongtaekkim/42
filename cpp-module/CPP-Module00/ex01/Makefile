# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: staek <staek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:36:44 by staek             #+#    #+#              #
#    Updated: 2023/01/11 13:53:56 by staek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook
SRCS		= PhoneBook.cpp Contact.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX			= c++

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re:
	make fclean
	make all

.PHONY: all clean fclean re test