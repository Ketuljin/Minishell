# Nom de l'exécutable
NAME= Minishell

# Compilateur et drapeaux
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ilibft 
# Fichiers sources et objets
SRC =	main.c \
		main_utils.c \
		 \
		parsing/utlis.c \
		parsing/parsing.c \
		parsing/split_pipe.c \
		parsing/split_token.c \
		parsing/replace_var.c \
		parsing/check_heredoc.c \
		 \
		exec/check_builtin.c \
		exec/ft_exec_1.c \
		exec/pipes_utils.c \
		exec/ft_out_put.c \
		exec/ft_in_put.c \
		 \
		exec/builtins/cd.c \
		exec/builtins/echo.c \
		exec/builtins/env.c \
		exec/builtins/export.c \
		exec/builtins/export_print.c \
		exec/builtins/pwd.c \
		exec/builtins/unset.c \
		exec/builtins/utils_task.c \
		exec/builtins/change_var.c \

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
