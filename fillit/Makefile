

NAME			=	fillit
LIBFT			=	libft
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -o
LIBS			=	./libft/libft.a
HEADER			=	fillit.h
FILES			=	open_file.c read_file.c main.c error_chk.c tet_array.c \
					print.c fillit.c \

OBJECTS			=	$(FILES:%.c=%.o)

all:	$(NAME)

$(NAME):
	make -C./libft
	$(CC) $(FLAGS) $(NAME) $(FILES) $(LIBS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
