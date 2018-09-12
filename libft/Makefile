#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otiniako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 11:36:22 by otiniako          #+#    #+#              #
#    Updated: 2018/03/31 17:06:56 by otiniako         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -Iinclude/

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
	ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
	ft_strjoin_clean.c ft_wstrlen.c ft_wstrnew.c ft_putnwstr.c ft_putwchar_fd.c\
	ft_putwchar.c ft_putnstr.c ft_putnbr_base.c ft_atoi_base.c\
	ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c\
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c\
	ft_putnbr_u_base_fd.c ft_putnbr_u.c ft_printf.c ft_params.c ft_null.c\
	ft_printf_procent.c ft_tools.c ft_printf_int.c ft_printf_long.c ft_printf_char.c\
	ft_printf_str.c ft_printf_hex.c ft_printf_octal.c ft_printf_unsign.c\
	ft_printf_void.c ft_atoi_long.c get_next_line.c ft_str_toupper.c ft_atoi_uint.c\

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)
	@echo "\033[1;92mlibft.a is created!\033[m"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o : %.c
	@gcc -c $(FLAGS) -o $@ -c $<

main: re
	@gcc main.c -L. -lft

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all