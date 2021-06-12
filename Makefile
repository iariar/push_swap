# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iariss <iariss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 11:44:36 by iariss            #+#    #+#              #
#    Updated: 2021/06/07 19:07:56 by iariss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap.a
EXEC    = push_swap
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
LIBFT = libft/libft.a
HEADER = file.h

SRC = main.c initialize.c instructions.c instructions2.c print_ex.c extra.c operate.c extra2.c cases.c
	
OBJ = $(SRC:.c=.o)


all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft
	make bonus -C ./libft

$(NAME): $(HEADER) $(OBJ) 

	ar rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(NAME) $(LIBFT) -o $(EXEC) 


clean:
	rm -f $(OBJ) $(NAME)
	make fclean -C libft

fclean: clean
	rm -f $(EXEC)
	make fclean -C libft

re: fclean all