# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 12:07:40 by seongtki          #+#    #+#              #
#    Updated: 2022/12/31 18:36:40 by seongtki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
RM = rm -f
MAN_DIR = ./mandatory
BONUS_DIR = ./bonus

all : 
	make -C $(MAN_DIR)

bonus :
	make -C $(BONUS_DIR) bonus
	
clean:
	make -C $(MAN_DIR) clean
	make -C $(BONUS_DIR) clean

fclean: clean
	make -C $(MAN_DIR) fclean
	make -C $(BONUS_DIR) fclean
	
re:
	make fclean
	make all

norm:
	Norminette -R CheckForbiddenSourceHeader mandatory/*.c bonus/*.c
	Norminette -R CheckForbiddenSourceHeader mandatory/libft/*.c bonus/libft/*.c
	Norminette -R CheckDefine mandatory/*.h bonus/*.h
	Norminette -R CheckDefine mandatory/libft/*.h bonus/libft/*.h

.PHONY: all bonus clean fclean re
