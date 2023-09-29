HEADER	=	libftprintf.h

NAME	=	libftprintf.a

SRCS	=	ft_prinft.c /
			ft_putnbase.c /
			ft_putstr.c /
			ft_strchr.c /
			pt_putbase.c /
			pt_putchar.c

OBJS	= 	$(SRCS:.c=.o)

CC	= 	gcc

RM	= 	rm -f

LIBC	= 	ar -rcs

FLAGS	= 	-Wall -Wextra -Werror

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):: ${OBJS} ${HEADER}
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re  bonus
