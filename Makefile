

NAME			=	fillit
LIBFT			=	libft
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra
LIBS			=	./libft/libft.a
FILES			=	./srcs/open_file.c ./srcs/read_file.c ./srcs/main.c \
					./srcs/error_chk_1.c ./srcs/error_chk_2.c ./srcs/tet_array.c \
					./srcs/piece_config.c ./srcs/print.c ./srcs/placing.c \
					./srcs/grid_manipulator.c ./srcs/coord_manipulator.c \
					./srcs/solve.c ./srcs/tet_shapes_1.c ./srcs/tet_shapes_2.c \
					./srcs/tet_shapes_3.c ./srcs/tet_shapes_4.c \

OBJECTS			=	open_file.o read_file.o main.o error_chk_1.o error_chk_2.o \
					tet_array.o piece_config.o print.o placing.o \
					grid_manipulator.o coord_manipulator.o solve.o tet_shapes_1.o \
					tet_shapes_2.o tet_shapes_3.o tet_shapes_4.o \

all:	$(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME):
	make -C./libft
	$(CC) $(FLAGS) -c $(FILES)
	$(CC) $(OBJECTS) $(FLAGS) $(LIBS) -o $(NAME)

