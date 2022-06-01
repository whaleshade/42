# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 19:08:14 by jibang            #+#    #+#              #
#    Updated: 2022/04/29 19:08:15 by jibang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
	SRCS = ft_printf.c ft_print_mem_address.c ft_putchar.c \
		   ft_putstr.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_unsign.c

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar -rcus $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
