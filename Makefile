#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otiniako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 16:17:52 by otiniako          #+#    #+#              #
#    Updated: 2018/07/02 16:17:53 by otiniako         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FLAGS = -Wall -Wextra -Werror -I includes/

LIB = libft/libft.a

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = src/fractol.c\
		src/tools.c\
		src/threadf.c\
		src/ft_frs.c\
		src/init.c\

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(LIB):
	@make -C libft/

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIB) $(MLX)
	@echo "\033[1;92mfractol is created!\033[m"

$(OBJ): %.o: %.c
	@gcc -c $(FLAGS) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all