# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 12:06:35 by wdaher-a          #+#    #+#              #
#    Updated: 2019/07/09 16:42:20 by berry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC =	./get_next_line.c ./ft_atoi.c ./ft_isprint.c ./ft_memset.c  ./ft_strlcat.c ./ft_strrchr.c \
	 	./ft_bzero.c   ./ft_memccpy.c ./ft_strcat.c  ./ft_strlen.c  ./ft_strstr.c \
	 	./ft_isalnum.c ./ft_memchr.c  ./ft_strchr.c  ./ft_strncat.c ./ft_tolower.c \
	 	./ft_isalpha.c ./ft_memcmp.c  ./ft_strcmp.c  ./ft_strncmp.c ./ft_toupper.c \
	 	./ft_isascii.c ./ft_memcpy.c  ./ft_strcpy.c  ./ft_strncpy.c ./ft_isdigit.c \
		./ft_memmove.c ./ft_strdup.c  ./ft_strnstr.c ./ft_memalloc.c ./ft_memdel.c \
		./ft_strnew.c ./ft_strclr.c ./ft_striter.c ./ft_striteri.c ./ft_strdel.c \
		./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c \
		./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c \
		./ft_itoa.c \
		./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c \
		./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_lstnew.c ./ft_lstdelone.c \
		./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c

RM=rm -f

HDDIRS=-I ./

OBJ=$(SRC:.c=.o)

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) $(HDDIRS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
