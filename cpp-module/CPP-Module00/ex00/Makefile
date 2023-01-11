NAME		= megaphone
SRCS		= megaphone.cpp

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

test: re
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

.PHONY: all clean fclean re test