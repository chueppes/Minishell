NAME	= minishell

LIBRARY = ./sources/libft/libft.a

SRCS = $(shell find sources -name '*.c')

OBJS	= $(SRC:.c=.o)

CFLAGS	= -I /opt/homebrew/Cellar/readline/8.2.1/include

LFLAGS = -L /opt/homebrew/Cellar/readline/8.2.1/lib

$(NAME):	$(OBJS)
	make -s -C ./sources/libft 
	cc -g -Wall -Wextra -Werror $(SRCS) -o $(NAME) $(LIBFT) -lreadline $(CFLAGS) $(LFLAGS)

all:	$(NAME)

clean:
	make clean -s -C ./sources/libft 
	rm -f $(OBJS)

fclean:	clean
	make fclean -s -C ./sources/libft 
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re norminette

valgrind: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --track-origins=yes  --log-file=lib.log ./minishel