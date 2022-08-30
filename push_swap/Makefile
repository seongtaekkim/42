# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 18:05:39 by seongtki          #+#    #+#              #
#    Updated: 2022/08/30 17:40:40 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker
CFLAGS = -Wall -Wextra -Werror
INCS = -I ./libft/libft.h -I ./push_swap.h
LIBFT = -L./libft -lft
RM = rm -f
SRCS =	push_swap.c stack.c operations.c operations2.c close.c sort.c search.c init.c output.c hardcode_swap_a.c hardcode_swap_b.c hardcode_swap_b2.c util.c push_swap_stack_a.c push_swap_stack_b.c
SRCS_B = checker.c stack.c operations.c operations2.c close.c sort.c search.c init.c output.c hardcode_swap_a.c hardcode_swap_b.c hardcode_swap_b2.c util.c
OBJS = $(SRCS:.c=.o) 
OBJS_B = $(SRCS_B:.c=.o) 
.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@ $(INCS)

$(BNAME) : $(OBJS_B)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_B) -o $@ $(INCS)
clean:
	make -C ./libft clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)
	$(RM) $(BNAME)
re:	clean all
.PHONY: all bonus clean fclean re
