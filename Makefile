AR = ar rc

NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line_utils.c get_next_line.c

HEADER = get_next_line.h

OBJ = $(SRC:.c=.o)

all: ${NAME}

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all