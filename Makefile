CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CLIB = -c

SRC_FILES = utils/ft_overflow_atoi.c utils/ft_split.c utils/ft_substr.c \
	utils/ft_strdup.c utils/ft_strlen.c src/check_argv.c utils/ft_isnum.c \
	utils/error_handle.c utils/check_argv_src.c utils/ft_atoi.c \
	src/populate_stack.c src/main.c src/sort_stack.c utils/sort_small_num.c \
	comands/swap_a_b.c utils/ft_putendl_fd.c utils/ft_putstr_fd.c \
	utils/populate_stack_src.c utils/sort_small_num_utils.c \
	comands/push_a_b.c comands/reverse_rotate_a_b.c comands/rotate_a_b.c \
	utils/quick_sort.c utils/prepare_quick_sort.c utils/ft_redix_sort.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CLIB) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY:  clean fclean all
