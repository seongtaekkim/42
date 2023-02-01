NAME		= container
SRCS		= main.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXDEBUG    = -fsanitize=address -g
HEADER		= ./includes/
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f

.cpp.o:
	$(CXX) $(CXXFLAGS) -I $(HEADER) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re:
	make fclean
	make all

.PHONY: all clean fclean re