NAME = push_swap

SRC = main.c \
	  movements.c \
	  movements1.c \
	  movements2.c \
	  list_operations.c \
	  parsing_utils.c \
	  push_swap.c \
	  push_swap1.c \
	  push_swap2.c \
	  push_swap3.c \
	  hardcode_sorting.c \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re