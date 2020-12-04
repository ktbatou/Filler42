# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 12:09:56 by ktbatou           #+#    #+#              #
#    Updated: 2020/12/04 02:10:28 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ktbatou.filler

LIB = src/gnl/libft/ft_atoi.o	src/gnl/libft/ft_bzero.o   src/gnl/libft/ft_isalnum.o   src/gnl/libft/ft_isalpha.o \
	src/gnl/libft/ft_isascii.o	src/gnl/libft/ft_isdigit.o	src/gnl/libft/ft_isprint.o	 src/gnl/libft/ft_itoa.o\
	src/gnl/libft/ft_memalloc.o	src/gnl/libft/ft_memccpy.o	src/gnl/libft/ft_memchr.o	src/gnl/libft/ft_memcmp.o\
	src/gnl/libft/ft_memcpy.o	src/gnl/libft/ft_memdel.o	src/gnl/libft/ft_memmove.o	src/gnl/libft/ft_memset.o\
	src/gnl/libft/ft_putchar.o	src/gnl/libft/ft_putchar_fd.o	src/gnl/libft/ft_putendl.o	src/gnl/libft/ft_putendl_fd.o\
	src/gnl/libft/ft_putnbr.o	src/gnl/libft/ft_putnbr_fd.o	src/gnl/libft/ft_putstr.o	src/gnl/libft/ft_putstr_fd.o\
	src/gnl/libft/ft_strcat.o	src/gnl/libft/ft_strchr.o	src/gnl/libft/ft_strclr.o	src/gnl/libft/ft_strcmp.o\
	src/gnl/libft/ft_strcpy.o	src/gnl/libft/ft_strdel.o	src/gnl/libft/ft_strdup.o	src/gnl/libft/ft_strequ.o\
	src/gnl/libft/ft_striter.o	src/gnl/libft/ft_striteri.o	src/gnl/libft/ft_strnew.o	src/gnl/libft/ft_strlen.o\
	src/gnl/libft/ft_strjoin.o	src/gnl/libft/ft_strlcat.o	src/gnl/libft/ft_strmap.o	src/gnl/libft/ft_strncpy.o\
	src/gnl/libft/ft_strmapi.o	src/gnl/libft/ft_strncat.o	src/gnl/libft/ft_strncmp.o	src/gnl/libft/ft_strnequ.o\
	src/gnl/libft/ft_strnstr.o	src/gnl/libft/ft_strrchr.o	src/gnl/libft/ft_strsplit.o	src/gnl/libft/ft_strstr.o\
	src/gnl/libft/ft_strsub.o	src/gnl/libft/ft_strtrim.o	src/gnl/libft/ft_tolower.o	src/gnl/libft/ft_toupper.o

OBJ =  src/main.o src/detail.o src/initial.o src/gnl/get_next_line.o src/point_to_num.o src/heat_map.o \
		 src/free.o src/placing1.o  src/placing2.o $(LIB)

HDR = -I ./src/include -I ./src/libft -I ./src/gnl

CFLAGS = $(HDR) -Wall -Werror -Wextra

CC = gcc 


all : LIBFT $(NAME)
		
$(NAME): $(OBJ)
		gcc $^ -o $@
		#ar rc $(NAME) $(OBJ)

LIBFT :
	make -C ./src/gnl/libft

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)
re : fclean all
	