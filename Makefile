# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/31 18:19:37 by allefebv          #+#    #+#              #
#    Updated: 2019/03/04 17:59:52 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_CHECK	=	checker
LIB			=	./libft/libft.a
INCLUDES	=	./includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -I $(INCLUDES) -g3 # -fsanitize=address
SDL			=	-F/Library/Frameworks -framework SDL2

SRC			=	srcs/create_stacks.c		\
				srcs/push_a.c				\
				srcs/push_b.c				\
				srcs/swap_a.c				\
				srcs/swap_b.c				\
				srcs/swap_ab.c				\
				srcs/rotate_a.c				\
				srcs/rotate_b.c				\
				srcs/rotate_ab.c			\
				srcs/rev_rotate_a.c			\
				srcs/rev_rotate_b.c			\
				srcs/rev_rotate_ab.c		\
				srcs/free_int_ptr.c

SRCCHECK	=	srcs/store_instructions.c	\
				srcs/checker_dir/main.c		\
				srcs/checker_dir/visual_checker.c	\
				srcs/checker_dir/classic_checker.c	\
				srcs/checker_dir/fptr_init_del.c	\
				srcs/checker_dir/rect_management.c	\
				srcs/checker_dir/rect_print.c	\
				srcs/checker_dir/rect_print_inv.c	\
				srcs/checker_dir/rect_print_inv2.c	\
				srcs/checker_dir/rect_print_success1.c	\
				srcs/checker_dir/rect_print_success2.c	\

SRCPUSHSW	=	srcs/push_swap_dir/main.c			\
				srcs/push_swap_dir/quick_sort.c		\
				srcs/push_swap_dir/median_finder.c		\
				srcs/push_swap_dir/partition_a.c		\
				srcs/push_swap_dir/partition_b.c		\
				srcs/push_swap_dir/kompressor.c		\
				srcs/push_swap_dir/ps_calls.c		\

OBJ			=	$(SRC:.c=.o)
OBJCHECK	=	$(SRCCHECK:.c=.o)
OBJPUSHSW	=	$(SRCPUSHSW:.c=.o)

all: $(NAME)

$(NAME): $(OBJPUSHSW) $(OBJCHECK) $(OBJ) libft
	$(CC) $(CFLAGS) $(OBJPUSHSW) $(OBJ) -o $(NAME) $(LIB)
	$(CC) $(CFLAGS) $(SDL) $(OBJCHECK) $(OBJ) -o $(NAME_CHECK) $(LIB)
	echo "made push_swap & checker"

libft:
	make -C libft -f libft.mk

clean:
	make -C libft -f libft.mk clean
	$(RM) $(OBJ)
	$(RM) $(OBJCHECK)
	$(RM) $(OBJPUSHSW)
	echo "cleaned project push_swap"

fclean: clean
	make -C libft -f libft.mk fclean
	$(RM) $(NAME)
	$(RM) $(NAME_CHECK)
	echo "fcleaned project push_swap"

re: fclean all

.PHONY: all clean fclean re libft
.SILENT: $(OBJCHECK) $(OBJPUSHSW) $(OBJ) all clean fclean re libft
