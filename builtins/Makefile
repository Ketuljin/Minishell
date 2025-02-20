NAME = test

CC = cc -Wall -Werror -Wextra

SRC = cd.c \
	echo.c\
	env.c\
	export.c\
	export_print.c\
	pwd.c\
	unset.c\
	utils_task.c\
	change_var.c \
	../exec/check_builtin.c \
	../exec/ft_exec_1.c \
	../exec/pipes_utils.c \




OBJS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ft_printf
	@make -C libft
	@$(CC)  $(OBJS) libft/libft.a ft_printf/ft_printf.a  -o $(NAME)

clean :
	@make clean -C ft_printf
	@make clean -C libft

	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C ft_printf
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
