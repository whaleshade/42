# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 23:12:01 by jibang            #+#    #+#              #
#    Updated: 2022/06/19 21:32:16 by jibang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME2 = checker
LIBA = libft.a
MAKE = make
SRCS = ./push_swap.c\
		   ./stack_push.c\
		   ./parse/parsing.c\
		   ./parse/parsing2.c\
		   ./sort_utils/index_sort.c\
		   ./sort_logics/main_sort_logic.c\
		   ./sort_logics/main_sort_logic2.c\
		   ./sort_logics/main_logic_a_b.c\
		   ./sort_logics/sub_main_logic/sub_logic_two.c\
		   ./sort_logics/sub_main_logic/sub_logic_3_a.c\
		   ./sort_logics/sub_main_logic/sub_logic_3_b.c\
		   ./sort_logics/sub_main_logic/sub_logic_3_b2.c\
		   ./sort_logics/only_cases.c\
		   ./sort_logics/only_cases2.c\
		   ./sort_utils/check_sorted.c\
		   ./sort_utils/stack_ops.c\
		   ./sort_utils/operations.c\
		   ./sort_utils/operations2.c\
		   ./main_utils.c \
		   ./leak_free.c
SRCS2 = ./checker.c\
		./main_utils.c\
		   ./stack_push.c\
		   ./parse/parsing.c\
		   ./parse/parsing2.c\
		   ./sort_utils/index_sort.c\
		   ./sort_logics/main_sort_logic.c\
		   ./sort_logics/main_sort_logic2.c\
		   ./sort_logics/main_logic_a_b.c\
		   ./sort_logics/sub_main_logic/sub_logic_two.c\
		   ./sort_logics/sub_main_logic/sub_logic_3_a.c\
		   ./sort_logics/sub_main_logic/sub_logic_3_b.c\
		   ./sort_logics/sub_main_logic/sub_logic_3_b2.c\
		   ./sort_logics/only_cases.c\
		   ./sort_logics/only_cases2.c\
		   ./sort_utils/check_sorted.c\
		   ./sort_utils/stack_ops.c\
		   ./sort_utils/operations.c\
		   ./sort_utils/operations2.c\
		   ./leak_free.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME2)

$(NAME2): $(LIBA)
	@$(CC) $(CFLAGS) $(SRCS2) ./libft/libft.a -o $(NAME2)

$(NAME): $(LIBA)
	@$(CC) $(CFLAGS) $(SRCS) ./libft/libft.a -o $(NAME)

$(LIBA):
	make all -C ./libft/

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
