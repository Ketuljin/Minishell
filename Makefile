# Nom de l'exécutable
NAME= Minishell

# Compilateur et drapeaux
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ilibft 
# Fichiers sources et objets
SRC =	main.c \
		main_utils.c \
		 \
		parsing/parsing.c \
		parsing/split_pipe.c \
		parsing/split_token.c \
		parsing/replace_var.c \

OBJ= $(SRC:.c=.o)

# Règle all
all: $(NAME)

# Règles pour créer l'exécutable
$(NAME): $(OBJ)
	$(MAKE) -C newlibft
	$(CC) $(CFLAGS) $(OBJ) newlibft/libft.a -o $(NAME) -lreadline

# Règle clean
clean:
	$(RM) $(OBJ)
	$(MAKE) -C newlibft clean

# Règle fclean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C newlibft fclean

# Règle re
re: fclean all

.PHONY: all clean fclean re
