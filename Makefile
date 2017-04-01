NAME = fillit
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
DEPS = libft.a
FUNCTIONS = *.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $@ *.c libft.a

clean:
	/bin/rm -f rm $(NAME)

fclean: clean

re: fclean all
