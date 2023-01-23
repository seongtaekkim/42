NAME 		= zombie
CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98
INCS 		= -I Zombie.h
RM 			= rm -f
SRCS 		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS 		= $(SRCS:.cpp=.o) 
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
.PHONY: all clean fclean re
