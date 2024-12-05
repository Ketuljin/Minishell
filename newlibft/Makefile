# Nom de la bibliothèque
NAME = libft.a

# Compilateur et drapeaux
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Fichiers sources et objets
SRC = get_next_line.c \
	\
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_error.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tabdup.c \
	ft_tabfree.c \
	ft_tablen.c \
	ft_tolower.c \
	ft_toupper.c \
	\
	ft_lstadd_back.c \
	ft_lstlast.c \
	ft_lstsize.c \
	

OBJ = $(SRC:.c=.o)

# Règle allclient.c
all: $(NAME)

# Règles pour créer la bibliothèque
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


# Règle clean
clean:
	$(RM) $(OBJ)

# Règle fclean
fclean: clean
	$(RM) $(NAME)

# Règle re
re: fclean all

.PHONY: all clean fclean re
