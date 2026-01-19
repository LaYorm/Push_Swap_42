NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = objs

SRC = check_arg.c find_cheapest.c find_target_a.c find_target_b.c free_and_error.c\
		initiate_stack.c main.c move_from_stack.c prepare_for_sort.c push.c sort.c\
		reverse_rotate.c rotate.c sort_small.c split.c swap.c utils.c

OBJ = ${SRC:%.c=$(OBJ_DIR)/%.o}

all : $(NAME)

$(NAME) : $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.c push_swap.h
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean :
			rm -rf $(OBJ_DIR)

fclean : clean
			rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
