# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 18:50:30 by seongtki          #+#    #+#              #
#    Updated: 2022/08/07 18:50:32 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   libftprintf.a
SRCS	=	ft_printf.c \
			ft_printf_setting.c \
			ft_itoa.c	\
			ft_nbr_base.c	\
			ft_utoa.c	\
			util.c	\
			c_proc.c	\
			s_proc.c	\
			p_proc.c	\
			di_proc.c	\
			u_proc.c	\
			x_proc.c	\
			per_proc.c	
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CFLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all: $(NAME)

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)
    
re:
	make fclean
	make all

.PHONY: all clean fclean re 
