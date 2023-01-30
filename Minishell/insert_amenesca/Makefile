NAME = insert_list

SRCS = create_list.c lstadd_back_command.c lstlast_command.c lstnew_command.c split_quotes.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cc -g $(SRCS) libft.a -o $(NAME)

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
