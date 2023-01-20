NAME		= megaphone
SRCS		= megaphone.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f

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