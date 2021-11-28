CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
NAME	:= libftprintf.a
SRC		:= ft_putnbr.c ft_printf_utils.c ft_printf.c ft_strlen.c
OBJ		:= $(patsubst %.c, %.o, $(SRC)) 

.PHONY: all clean fclean re 

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
