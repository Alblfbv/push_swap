# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/31 18:19:37 by allefebv          #+#    #+#              #
#    Updated: 2019/02/01 15:18:02 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER		=	checker
PUSH_SWAP	=	push_swap
LIB			=	./libft/libft.a
INCLUDES	=	./includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -I $(INCLUDES)

SRC		=		srcs/create_stacks.c		\
				srcs/store_instructions.c	\
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
				srcs/checker_dir/main.c

OBJ		=	$(SRC:.c=.o)

all: $(CHECKER)

$(CHECKER): $(OBJ) libft
	$(CC) $(CFLAGS) $(OBJ) -o $(CHECKER) $(LIB)
	echo "made project"

libft:
	make -C libft -f libft.mk

clean:
	make -C libft -f libft.mk clean
	$(RM) $(OBJ)
	echo "cleaned project push_swap"


fclean: clean
	make -C libft -f libft.mk fclean
	$(RM) $(CHECKER)
	echo "fcleaned project push_swap"

re: fclean all

.PHONY: all clean fclean re checker libft
.SILENT: $(OBJ) all clean fclean re checker libft
