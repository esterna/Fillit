NAME = fillit
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.a
FUNCTIONS = main.c\
			file_checker.c\
			translator.c\
			solver.c\
			check_add_remove.c\

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $@ $(FUNCTIONS) libft.a

clean:

fclean: clean
	/bin/rm -f rm $(NAME)

re: fclean all
