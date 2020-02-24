
NAME2 = push_swap
NAME1 = checker
LIBFT = ./libft/libft.a
FILES2 = srcs/push_swap.c srcs/small_sorts.c srcs/small_sorts_a.c \
		srcs/small_sorts_b.c srcs/sort.c

FILES1 = srcs/checker.c

FILES3 = srcs/fill.c srcs/is_sorted.c srcs/print.c srcs/pushes.c \
		srcs/reverse_rotates.c srcs/rotates.c srcs/stack_operations.c \
		srcs/swaps.c

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
OBJ3 = $(patsubst %.c, %.o, $(FILES3))
CFLAGS	=  -Wall -Werror -Wextra
HEADER		= includes/both.h includes/push_swap.h includes/checker.h
NAME 		= $(NAME1) $(NAME2)

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC libft all

$(NAME1): $(OBJ1) $(OBJ3)
	@gcc $(CFLAGS) -o $(NAME1) $(OBJ1) $(OBJ3) $(LIBFT)
	@echo checker compiled

$(NAME2): $(OBJ2) $(OBJ3)
	@gcc $(CFLAGS) -o $(NAME2) $(OBJ2) $(OBJ3) $(LIBFT)
	@echo push_swap compiled

%.o: %.c $(HEADER) $(LIBFT)
	@gcc -I . $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean -C ./libft

fclean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean -C ./libft
	@rm -f $(NAME1) $(NAME2) && $(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all