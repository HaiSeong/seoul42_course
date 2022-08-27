# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 13:12:26 by hajeong           #+#    #+#              #
#    Updated: 2022/08/27 13:12:26 by hajeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft

SRCS =	ft_doubly_circular_list.c \
		push_swap.c \
		push.c \
		swap.c \
		reverse_rotate.c \
		rotate.c \
		sorting_before.c\
		sorting.c \
		calculate_cost1.c \
		calculate_cost2.c \
		rotate_best_cost.c \
		

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJS) -L ./libft -l ft

%.o			:	%.c
		cc $(FLAGS) -c $^ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re