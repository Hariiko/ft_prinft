# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 23:35:25 by laltarri          #+#    #+#              #
#    Updated: 2023/10/01 18:41:04 by laltarri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	ft_printf.h

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_putstr.c \
			ft_strchr.c \
			pt_putbase.c \
			pt_putchar.c \
			ft_putpointer.c

OBJS	= 	$(SRCS:.c=.o)

CC	= 	gcc

RM	= 	rm -f

LIBC	= 	ar -rcs

FLAGS	= 	-Wall -Wextra -Werror

.c.o :
	${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJS} ${HEADER}
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
