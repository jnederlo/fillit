

NAME			=	fillit
LIBFT			=	libft
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -o
DEBUG			=	-g -Wall -Werror -Wextra -o
LIBS			=	./libft/libft.a
HEADER			=	fillit.h
FILES			=	open_file.c read_file.c main.c error_chk_1.c error_chk_2.c \
					tet_array.c piece_config.c print.c fillit.c tet_shapes_1.c \
					tet_shapes_2.c tet_shapes_3.c tet_shapes_4.c \

OBJECTS			=	$(FILES:%.c=%.o)

all:	$(NAME)

$(NAME):
	make -C./libft
	$(CC) $(FLAGS) $(NAME) $(FILES) $(LIBS)

lldb: 
	make -C./libft
	$(CC) $(DEBUG) $(NAME) $(FILES) $(LIBS)

clean:
	rm -f $(OBJECTS)
	rm -rf fillit.dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all
