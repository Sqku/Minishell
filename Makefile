NAME	= ft_minishell1
SRC		= main.c \
		  ft_command.c \
		  ft_cd.c \
		  ft_env.c \
		  ft_goodpath.c \
		  ft_setenv.c \
		  ft_utils.c \
		  ft_unsetenv.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra #-Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(OBJ) -o $(NAME) -L libft/ -lft $(FLAGS)

%.o: %.c
	@$(CC) -I . -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all