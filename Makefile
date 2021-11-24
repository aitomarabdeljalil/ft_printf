CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
NAME	:= libft.a
SRC		:= ft_atoi.c ft_isdigit.c ft_bzero.c ft_memset.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_printf.c
OBJ		:= $(patsubst %.c, %.o, $(SRC)) 

.PHONY: all clean fclean re 

all: $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BN)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	make -C libft all
	ar cr $(NAME) $(OBJ)
