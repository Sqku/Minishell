# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 11:47:56 by ahua              #+#    #+#              #
#    Updated: 2015/05/10 18:02:11 by ahua             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c \
	  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	  ft_strsplit.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putstr.c ft_putstr_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c			\
	  ft_lstdelone.c		\
	  ft_lstdel.c			\
	  ft_lstadd.c			\
	  ft_lstlen.c			\
	  ft_lstiter.c			\
	  ft_lstmap.c			\
	  ft_lstpushback.c		\
	  ft_lstsmartpushback.c	\
	  ft_lstsimpledel.c		\
	  ft_lstsimpledelone.c	\
	  ft_lstdelnode.c		\
	  get_next_line.c

		

OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c -o $@ $(FLAGS) $^

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
