# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:25:42 by seongtki          #+#    #+#              #
#    Updated: 2022/09/05 17:30:25 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# cc -L/opt/homebrew/opt/readline/lib -lreadline -lhistory readline.c     
NAME = shell
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = shell.c
OBJS = $(SRCS:.c=.o)
RDLIB = /opt/homebrew/opt/readline/

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(RDLIB)lib -I$(RDLIB)include -lreadline -lhistory -o $(NAME)

.c.o :
	$(CC) $(CFLAGS)  -I$(RDLIB)include -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:	clean all
.PHONY: all clean fclean re
