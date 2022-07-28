NAME	=   libftprintf.a
SRCS	=	ft_printf.c \
			ft_printf_setting.c \
			ft_itou.c	\
			ft_nbr_base.c	\
			ft_utoa.c	\
			util.c	\
			c_proc.c	\
			s_proc.c	\
			p_proc.c	\
			di_proc.c	\
			u_proc.c	\
			x_proc.c
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
	$(RM) -f $(OBJS)
    
re:
	make fclean
	make all

.PHONY: all clean fclean re 
