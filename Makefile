CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I.

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

SRCS = pipex_utils.c pipex.c

OBJS = $(SRCS:.c=.o)

NAME = pipex

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft -L./printf -lftprintf

clean:
	rm -f $(OBJS)
	make -C ./libft clean
	make -C ./printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re