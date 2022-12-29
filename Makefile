
NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC = ./inc/push_swap.h

SRC = ./src/string_utils.c ./src/main.c ./src/push.c ./src/init.c ./src/stack.c ./src/swap.c\
		./src/check_input_utils.c ./src/check_input.c ./src/rotate.c ./src/rrotate.c ./src/sort.c ./src/sort_tree.c \
		./src/move.c ./src/cost.c ./src/position.c ./src/utils.c

OBJ = $(SRC:c=o)

# SRCB =

# OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"
	@rm -f $(OBJ) $(OBJB)

%.o: %.c
	@printf "\033[0;33mGenerating push_swap objects... %-100.200s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

bonus: $(OBJB)
	@echo "\033[0;32m\n\nCompiling push_swap (with bonuses)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB)
	@echo "\n\033[0mDone !"

.PHONY: clean fclean re bonus
