cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

file(GLOB libft_SRC
        "libft/*.c")

add_executable(push_swap srcs/push_swap.c includes/push_swap.h
        srcs/stack_operations.c ${libft_SRC} libft/libft.h srcs/swaps.c srcs/pushes.c srcs/rotates.c srcs/print.c srcs/sort.c srcs/small_sorts.c srcs/fill.c)