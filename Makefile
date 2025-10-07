CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I.

LIBFT = ../pipex_folder/libft/libft.a
PRINTF = ../pipex_folder/printf/libftprintf.a

SRCS = pipex_utils.c pipex.c

OBJS = $(SRCS:.c=.o)

NAME = pipex

all: $(NAME)

$(LIBFT):
	make -C ../pipex_folder/libft

$(PRINTF):
	make -C ../pipex_folder/printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L../pipex_folder/libft -lft -L../pipex_folder/printf -lftprintf

clean:
	rm -f $(OBJS)
	make -C ../pipex_folder/libft clean
	make -C ../pipex_folder/printf clean

fclean: clean
	rm -f $(NAME)
	make -C ../pipex_folder/libft fclean
	make -C ../pipex_folder/printf fclean

re: fclean all

.PHONY: all clean fclean re 