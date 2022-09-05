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

NAME = philo
BNAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./philo.h
RM = rm -f
SRCS = ./philo/main.c
SRCS_B = ./philo_bonus/main.c
OBJS = $(SRCS:.c=.o) 
OBJS_B = $(SRCS_B:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCS)

$(BNAME) : $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $@ $(INCS)
clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
re:	clean all
.PHONY: all bonus clean fclean re
