HEADER	=	libft.h

NAME	=	libft.a

SRCS	=	ft_prinft.c 

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
