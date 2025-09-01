CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

FILES = ft_putchar.c ft_putstr.c ft_putnbr_base.c ft_putnbr.c ft_percent.c ft_putptr.c ft_printf.c

SRCS = $(FILES)

OFILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
		ar rcs $(NAME) $(OFILES)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

