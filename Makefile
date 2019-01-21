# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 17:24:14 by cfrederi          #+#    #+#              #
#    Updated: 2018/08/31 15:26:58 by cfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./resources/players/cfrederi.filler

INC_DIR = ./includes

SRC := ./src/populate.c
SRC += ./src/filler.c
SRC += ./src/place.c


#compliler and libraries 

CFLAGS = -Wall -Wextra -Werror -I./includes

#rules

#OBJ = $(SRC:.c=.o)#

all: $(NAME)

$(NAME):
	$(MAKE) -C libft all
	 	gcc -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a
	echo "Filler done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_DIR)*.h

.PHONY : all clean fclean re

