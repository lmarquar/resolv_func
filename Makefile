CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra
NAME	:= resolv_func
SRCDIR	:= src/
SRC		:= ft_putdouble.c resolv_func.c
SRCD	:= main.c
OBJ		:= $(SRC:.c=.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ): $(SRC)
	cd $(SRCDIR) && $(CC) $(CFLAGS) $^ -c && mv $@ ..

$(SRC):
	cd $(SRCDIR) && cp $@ ..	

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(SRC)
	rm -f $(OBJ)
