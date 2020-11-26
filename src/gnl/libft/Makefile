# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 11:38:26 by ktbatou           #+#    #+#              #
#    Updated: 2019/06/20 12:35:17 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./ft_atoi.c ./ft_memccpy.c ./ft_putendl.c	./ft_strcmp.c ./ft_strlen.c ./ft_strrchr.c ./ft_bzero.c	./ft_memchr.c ./ft_putendl_fd.c	./ft_strcpy.c ./ft_strmap.c ./ft_strsplit.c ./ft_isalnum.c ./ft_memcmp.c ./ft_putnbr.c ./ft_strdel.c ./ft_strmapi.c	ft_strstr.c ./ft_isalpha.c ./ft_memcpy.c ./ft_putnbr_fd.c ./ft_strdup.c	./ft_strncat.c ./ft_strsub.c ./ft_isascii.c	./ft_memdel.c ./ft_putstr.c	./ft_strequ.c ./ft_strncmp.c ./ft_strtrim.c ./ft_isdigit.c ./ft_memmove.c ./ft_putstr_fd.c ./ft_striter.c ./ft_strncpy.c ./ft_tolower.c ./ft_isprint.c ./ft_memset.c ./ft_strcat.c ./ft_striteri.c ./ft_strnequ.c ./ft_toupper.c ./ft_itoa.c ./ft_putchar.c ./ft_strchr.c ./ft_strjoin.c ./ft_strnew.c ./ft_memalloc.c ./ft_putchar_fd.c ./ft_strclr.c ./ft_strlcat.c ./ft_strnstr.c
HEADER = ./libft.h

all : $(NAME)

$(NAME) :
	gcc -Wextra -Werror -Wall -c $(SRC) -I $(HEADER)
	ar rc $(NAME) ./ft_atoi.o ./ft_memdel.o ./ft_strclr.o ./ft_strncat.o ./ft_bzero.o ./ft_memmove.o ./ft_strcmp.o ./ft_strncmp.o ./ft_isalnum.o ./ft_memset.o ./ft_strcpy.o ./ft_strncpy.o ./ft_isalpha.o ./ft_putchar.o ./ft_strdel.o ./ft_strnequ.o ./ft_isascii.o ./ft_putchar_fd.o ./ft_strdup.o ./ft_strnew.o ./ft_isdigit.o ./ft_putendl.o ./ft_strequ.o ./ft_strnstr.o ./ft_isprint.o ./ft_putendl_fd.o ./ft_striter.o ./ft_strrchr.o ./ft_itoa.o ./ft_putnbr.o ./ft_striteri.o ./ft_strsplit.o ./ft_memalloc.o ./ft_putnbr_fd.o ./ft_strjoin.o ./ft_strstr.o ./ft_memccpy.o ./ft_putstr.o ./ft_strlcat.o ./ft_strsub.o ./ft_memchr.o ./ft_putstr_fd.o  ./ft_strlen.o ./ft_strtrim.o ./ft_memcmp.o ./ft_strcat.o ./ft_strmap.o ./ft_tolower.o ./ft_memcpy.o ./ft_strchr.o ./ft_strmapi.o ./ft_toupper.o
clean :
	rm -f ./ft_atoi.o ./ft_memdel.o ./ft_strclr.o ./ft_strncat.o ./ft_bzero.o ./ft_memmove.o ./ft_strcmp.o ./ft_strncmp.o ./ft_isalnum.o ./ft_memset.o ./ft_strcpy.o ./ft_strncpy.o ./ft_isalpha.o ./ft_putchar.o ./ft_strdel.o ./ft_strnequ.o ./ft_isascii.o ./ft_putchar_fd.o ./ft_strdup.o ./ft_strnew.o ./ft_isdigit.o ./ft_putendl.o ./ft_strequ.o ./ft_strnstr.o ./ft_isprint.o ./ft_putendl_fd.o ./ft_striter.o ./ft_strrchr.o ./ft_itoa.o ./ft_putnbr.o	./ft_striteri.o ./ft_strsplit.o ./ft_memalloc.o ./ft_putnbr_fd.o ./ft_strjoin.o ./ft_strstr.o ./ft_memccpy.o ./ft_putstr.o ./ft_strlcat.o ./ft_strsub.o ./ft_memchr.o ./ft_putstr_fd.o ./ft_strlen.o ./ft_strtrim.o ./ft_memcmp.o ./ft_strcat.o	./ft_strmap.o ./ft_tolower.o ./ft_memcpy.o ./ft_strchr.o ./ft_strmapi.o ./ft_toupper.o
fclean : clean
	rm -f $(NAME)
re : fclean all
