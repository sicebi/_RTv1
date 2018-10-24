# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antini <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/28 09:06:30 by antini            #+#    #+#              #
#    Updated: 2018/09/28 09:06:32 by antini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		rtv1

SRCS=		main.c		\
			ft_calc.c		\
			ft_light.c		\
			ft_shadow.c	\
			ft_colors.c	\
			ft_rotate.c	\
			ft_inter_obj.c	\
			ft_draw.c		\
			ft_list.c		\
			ft_string.c	\
			ft_hooks.c

OBJS=		$(SRCS:%.c=%.o)

LIB=		-L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

CFLAGS=		-Wall -Wextra -Werror -I/usr/X11/include/

CC=			gcc

RM=			rm -f

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "\033[34m Compilation : \033[32m OK ! \033[0m"
			@$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
