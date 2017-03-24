

NAME			=	fillit.a
CC				=	gcc
FLAGS			=	-c -Wall -Werror -Wextra
// LIBS			=	-static -llibft
HEADER			=	fillit.h
FILES			=	open_file.c \

OBJECTS			=	$(FILES:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(FILES) $(LIBS) 


clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all