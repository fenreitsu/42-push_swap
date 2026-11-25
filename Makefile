
CC = cc
CFLAGS = -Wall -Wextra -Werror -I . -I libft

NAME = push_swap

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS = main.c \
	bench.c \
	parsing/parse.c \
	parsing/parse_utils.c \
	parsing/validate.c \
	stack/stack.c \
	stack/stack_utils.c \
	operations/operation_printer.c \
	operations/push.c \
	operations/reverse.c \
	operations/rotate.c \
	operations/swap.c \
	sorting/simple.c \
	sorting/medium.c \
	sorting/complex.c \
	sorting/adaptive.c \
	sorting/sort_utils.c \
	sorting/get_disorder.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
