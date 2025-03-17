# Nom de l'exécutable
NAME = Minishell

# Répertoires
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Compilateur et drapeaux
CC	 = cc
CFLAGS = -Wall -Wextra -Werror -g -Ilibft -I$(INCDIR)

# Fichiers sources (chemins relatifs depuis SRCDIR)
SRC_FILES = \
	main.c \
	main_utils.c \
	 \
	parsing/utlis.c \
	parsing/parsing.c \
	parsing/split_pipe.c \
	parsing/split_token.c \
	parsing/norm_heredoc.c \
	parsing/trans_token.c \
	parsing/trans_heredoc.c \
	parsing/trans_var.c \
	 \
	exec/check_builtin.c \
	exec/ft_exec_1.c \
	exec/pipes_utils.c \
	exec/ft_out_put.c \
	exec/ft_in_put.c \
	exec/ft_exec_2.c \
	exec/exec_utils.c \
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
	exec/builtins/exit.c

# Construction du chemin complet vers les sources et génération des objets
SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Règle all
all: $(NAME)

# Règles pour créer l'exécutable
$(NAME): $(OBJ)
	$(MAKE) -C newlibft
	$(CC) $(CFLAGS) $(OBJ) -I$(INCDIR) -Inewlibft newlibft/libft.a -o $(NAME) -lreadline

# Règle de compilation pour chaque fichier .c
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

gdb: re
	gdb ./$(NAME) -ex "b scan_trans"
# Règles de nettoyage
clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C newlibft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C newlibft fclean

re: fclean all

.PHONY: all clean fclean re