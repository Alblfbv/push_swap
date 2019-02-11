# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/31 18:19:37 by allefebv          #+#    #+#              #
#    Updated: 2019/02/11 17:45:39 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER		=	checker
PUSH_SWAP	=	push_swap
LIB			=	./libft/libft.a
INCLUDES	=	./includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -I $(INCLUDES) -g3 -fsanitize=address

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

SRCCHECK	=	srcs/store_instructions.c	\
				srcs/checker_dir/main.c

SRCPUSHSW	=	srcs/push_swap_dir/main.c			\
				srcs/push_swap_dir/selection_sort.c	\
				srcs/push_swap_dir/quick_sort.c		\

OBJ			=	$(SRC:.c=.o)
OBJCHECK	=	$(SRCCHECK:.c=.o)
OBJPUSHSW	=	$(SRCPUSHSW:.c=.o)

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJPUSHSW) $(OBJ) libft
	$(CC) $(CFLAGS) $(OBJPUSHSW) $(OBJ) -o $(PUSH_SWAP) $(LIB)
	echo "made push_swap"

$(CHECKER): $(OBJCHECK) $(OBJ) libft
	$(CC) $(CFLAGS) $(OBJCHECK) $(OBJ) -o $(CHECKER) $(LIB)
	echo "made checker"

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
	$(RM) $(CHECKER)
	$(RM) $(PUSH_SWAP)
	echo "fcleaned project push_swap"

re: fclean all

.PHONY: all clean fclean re push_swap libft
.SILENT: $(OBJCHECK) $(OBJPUSHSW) $(OBJ) all clean fclean re checker push_swap libft
