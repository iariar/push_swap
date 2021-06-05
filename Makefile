# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iariss <iariss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 11:44:36 by iariss            #+#    #+#              #
#    Updated: 2021/06/05 18:34:29 by iariss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap.a
EXEC    = push_swap
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC = main.c initialize.c instructions.c instructions2.c print_ex.c extra.c operate.c
	
OBJ = $(SRC:.c=.o)


all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft
	make bonus -C libft

$(NAME): $(OBJ)

	ar rcs $(NAME) $(OBJ) libft/*.o
	$(CC) $(CFLAGS) $(SRC) $(NAME) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all