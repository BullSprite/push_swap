#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swynona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 14:34:53 by swynona           #+#    #+#              #
#    Updated: 2020/02/24 14:34:53 by swynona          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME2 = push_swap
NAME1 = checker
LIBFT_PATH = ./libft/
SRCS_PATH = ./srcs/
INCLUDES_PATH=./includes/
LIBFT = $(addprefix $(LIBFT_PATH), libft.a)
FILES2 =$(addprefix $(SRCS_PATH), push_swap.c small_sorts.c small_sorts_a.c \
		small_sorts_b.c sort.c)

FILES1 = $(addprefix $(SRCS_PATH), checker.c)

FILES3 = $(addprefix $(SRCS_PATH), fill.c is_sorted.c print.c pushes.c \
		reverse_rotates.c rotates.c stack_operations.c \
		swaps.c errors.c)

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
OBJ3 = $(patsubst %.c, %.o, $(FILES3))
CFLAGS	=  -Wall -Werror -Wextra
HEADER		= $(addprefix $(INCLUDES_PATH), both.h push_swap.h checker.h)
NAME 		= $(NAME1) $(NAME2)
MAKE		= cd $(LIBFT_PATH) && make

all: $(NAME)

$(LIBFT):
	@$(MAKE) all && cd ../
	@echo libft compiled

$(NAME1): $(OBJ1) $(OBJ3)
	@gcc $(CFLAGS) -o $(NAME1) $(OBJ1) $(OBJ3) $(LIBFT)
	@echo checker compiled

$(NAME2): $(OBJ2) $(OBJ3)
	@gcc $(CFLAGS) -o $(NAME2) $(OBJ2) $(OBJ3) $(LIBFT)
	@echo push_swap compiled

%.o: %.c $(HEADER) $(LIBFT)
	@gcc -I . $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean && cd ../

fclean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean && cd ../
	@rm -f $(NAME1) $(NAME2) && $(MAKE) fclean  && cd ../

re: fclean all

.PHONY: clean fclean re all