CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra
NAME	:= resolv_func
SRCDIR	:= src/
SRC		:= ft_putdouble.c resolv_func.c
OBJ		:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ): $(SRC)
	rm -f $(SRC)

	$(CC) $(CFLAGS) $^

$(SRC):
	cd $(SRCDIR) && mv $@ ..	

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(SRC)
	rm -f $(OBJ)
