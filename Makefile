NAME = push_swap
NAME_BONUS = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = ./src/check_input.c ./src/main.c ./src/move.c ./src/operations2.c \
	./src/operations.c ./src/position.c ./src/sort.c ./src/stack.c \
	./src/string_utils.c ./src/utils2.c ./src/utils.c \

OBJ = $(SRC:c=o)

SRCB = ./bonus/check_input.c  ./bonus/operations2.c  ./bonus/stack.c ./bonus/string_utils2.c\
	./bonus/operations.c ./bonus/utils.c  ./bonus/checker_bonus.c ./bonus/string_utils.c\

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating push_swap objects... %-100.900s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\nDeleting executable..."
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\033[0m"

re: fclean all

bonus : $(NAME_BONUS)
$(NAME_BONUS) : $(OBJB)
	@echo "\033[0;32m\n\nCompiling push_swap (with bonuses)..."
	@$(CC) $(CFLAGS) $(SRCB) -o $(NAME_BONUS)
	@echo "\n\033[0mDone !"
.PHONY: clean fclean re bonus
