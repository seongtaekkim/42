NAME	=   libft.a
SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_striteri.c	\
			ft_strnstr.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c	\
			ft_strtrim.c	\
			ft_split.c	\
			ft_split2.c	\
			ft_split2_util.c	\
			ft_strcmp.c	\
			get_next_line.c	\
			get_next_line_utils.c
SRCS_B	=   ft_lstnew.c	\
			ft_lstadd_front.c	\
			ft_lstadd_back.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstiter.c	\
			ft_lstmap.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CFLAGS	= -Wall -Wextra -Werror
INCS	= .

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all: $(NAME)

bonus:
	make WITH_BONUS=1 all

$(NAME): ${OBJ_FILES}
	${LIBC} $(NAME) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
    
re:
	make fclean
	make all

.PHONY: all bonus clean fclean re 
