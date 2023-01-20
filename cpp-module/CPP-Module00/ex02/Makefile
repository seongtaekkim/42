NAME		= account
SRCS		= Account.cpp tests.cpp
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