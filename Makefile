# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpickard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 10:17:56 by dpickard          #+#    #+#              #
#    Updated: 2022/04/19 10:27:27 by dpickard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c printf_char.c printf_num.c

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS:.c=.o)
	ar -rc $(NAME) $^

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(SRCS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

