

NAME			=	fillit
LIBFT			=	libft
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra
LIBS			=	./libft/libft.a
HEADER			=	fillit.h
FILES			=	open_file.c \

OBJECTS			=	$(FILES:%.c=%.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME):
	$(CC) $(FLAGS) $(FILES) $(LIBS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
