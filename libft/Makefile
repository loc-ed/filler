# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 12:10:55 by cfrederi          #+#    #+#              #
#    Updated: 2018/08/08 03:15:30 by cfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TAG = gcc
NAME = libft.a
FLAG = -Wall -Werror -Wextra
SRC = ft_bzero.c ft_isdigit.c ft_memcmp.c ft_strcat.c ft_strdup.c ft_strncmp.c ft_strstr.c\
		ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcat.c ft_strncpy.c ft_tolower.c\
		ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strcmp.c ft_strlen.c	ft_strnstr.c ft_toupper.c\
		ft_atoi.c ft_isascii.c	ft_memchr.c	ft_memset.c	ft_strcpy.c	ft_strncat.c ft_strrchr.c\
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
		ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_swap.c ft_strrev.c ft_isupper.c ft_islower.c\
		ft_caps.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
		get_next_line.c ft_strnew_arr.c ft_min.c ft_max.c\

all:	$(NAME)

$(NAME):
		$(TAG) $(FLAGS) -c $(SRC)
		ar rc $(NAME) *.o
		ranlib $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f libft.a

re: fclean all
