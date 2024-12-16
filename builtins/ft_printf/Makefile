# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 07:51:49 by jkerthe           #+#    #+#              #
#    Updated: 2024/03/12 15:55:24 by jkerthe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = ft_printchar.c \
	ft_printhex.c \
	ft_printnbr.c \
	ft_printunsigned.c \
	ft_prints.c \
	ft_print_ptr.c \
	ft_printf.c \
	
PRINTF	= ft_printf


OBJ = ft_printchar.o \
	ft_printhex.o \
	ft_printnbr.o \
	ft_printunsigned.o \
	ft_prints.o \
	ft_print_ptr.o \
	ft_printf.o

all : $(NAME)

$(NAME):
	echo "Compiling .."
	cc -Wall -Wextra -Werror -c $(SRC)  && ar rc $(NAME) $(OBJ)
	echo "Done !"


clean:
	echo "Remove .o  ..."
	rm -rf $(OBJ)
	echo "Done !"

fclean: clean
	echo "Remove lib ..."
	rm -rf $(NAME)
	echo "Done !"


re: fclean all