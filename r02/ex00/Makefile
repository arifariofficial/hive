NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c parser.c converter.c utils.c big_numbers.c huge_numbers.c larger_numbers.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
